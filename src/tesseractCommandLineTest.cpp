/*
 * Should build without any external dependencies
 */
// c++ headers
#include <string>

// tesseract 4.1.0 and leptonica 1.78.0
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

int main() {
	char *outText;
	std::string dataPath = "../share/tessdata/";
	std::string imagePath = "../share/test.jpg";
	std::string language = "eng";

	tesseract::OcrEngineMode oem = tesseract::OEM_DEFAULT;
	/*
	 * PSM_OSD_ONLY
	 Orientation and script detection only.

	 PSM_AUTO_OSD
	 Automatic page segmentation with orientation and script detection. (OSD)

	 PSM_AUTO_ONLY
	 Automatic page segmentation, but no OSD, or OCR.

	 PSM_AUTO
	 Fully automatic page segmentation, but no OSD.

	 PSM_SINGLE_COLUMN
	 Assume a single column of text of variable sizes.

	 PSM_SINGLE_BLOCK_VERT_TEXT
	 Assume a single uniform block of vertically aligned text.

	 PSM_SINGLE_BLOCK
	 Assume a single uniform block of text. (Default.)
	 */
	tesseract::PageSegMode psm = tesseract::PSM_AUTO_OSD;
	//tesseract::PageSegMode psm = tesseract::PSM_SINGLE_BLOCK;

	tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
	// Initialize tesseract-ocr with English, without specifying tessdata path
	if (api->Init(dataPath.c_str(), language.c_str(), oem)) {
		fprintf(stderr, "Could not initialize tesseract.\n");
		exit(1);
	}

	// Set the Page Segmentation mode
	api->SetPageSegMode(psm);

	// Open input image with leptonica library
	Pix *image = pixRead(imagePath.c_str());
	api->SetImage(image);
	api->Recognize(NULL);

	tesseract::ResultIterator* ri = api->GetIterator();
	tesseract::PageIteratorLevel level = tesseract::RIL_WORD;
	printf("Words and bounding:\n");
	if (ri) {
		do {
			const char* word = ri->GetUTF8Text(level);
			float conf = ri->Confidence(level);
			int x1, y1, x2, y2;
			ri->BoundingBox(level, &x1, &y1, &x2, &y2);
			printf("word: '%s';  \tconf: %.2f; BoundingBox: %d,%d,%d,%d;\n",
					word, conf, x1, y1, x2, y2);
			delete[] word;
		} while (ri->Next(level));
	}
	// Get OCR result
	outText = api->GetUTF8Text();
	printf("\nOCR output:\n%s", outText);

	// Destroy used object and release memory
	api->End();
	delete[] outText;
	pixDestroy(&image);
	system("pause");
	return 0;
}
