/*
 * Should build without any external dependencies
 */

//#define DEBUG_BOUNDING_BOX 1
#define DEBUG_RECORD_PERFORMANCE 1

// c++ headers
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>

// tesseract 4.1.0 and leptonica 1.78.0
#include <leptonica/allheaders.h>
#include <tesseract/baseapi.h>
#include <tesseract/ocrclass.h>

void monitorProgress(ETEXT_DESC *monitor, int page);
void ocrProcess(tesseract::TessBaseAPI *api, ETEXT_DESC *monitor);

void monitorProgress(ETEXT_DESC *monitor, int page) {
  while (1) {
    printf("\r%3d%%", monitor[page].progress);
    fflush(stdout);
    if (monitor[page].progress == 100)
      break;
  }
}

void ocrProcess(tesseract::TessBaseAPI *api, ETEXT_DESC *monitor) {
  api->Recognize(monitor);
}

int main() {
  const std::string outputFileName = "performance.csv";
  std::chrono::duration<double, std::milli> processDuration;
  char *outText;
  std::string dataPath = "share/tessdata/";
  std::string imagePath = "share/test.jpg";
  std::string outputDataPath = "test.hocr";
  std::string language = "eng+ell";

  /*
   * OCR Engine modes:
   * 0    Legacy engine only.
   * 1    Neural nets LSTM engine only.
   * 2    Legacy + LSTM engines.
   * 3    Default, based on what is available.
   */
  tesseract::OcrEngineMode oem = tesseract::OEM_TESSERACT_ONLY;
  // tesseract::OcrEngineMode oem = tesseract::OEM_LSTM_ONLY;
  // tesseract::OcrEngineMode oem = tesseract::OEM_TESSERACT_LSTM_COMBINED;
  // tesseract::OcrEngineMode oem = tesseract::OEM_DEFAULT;
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
  // tesseract::PageSegMode psm = tesseract::PSM_SINGLE_BLOCK;

  tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
  ETEXT_DESC *monitor = new ETEXT_DESC();

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

  auto processStart = std::chrono::steady_clock::now();

  // monitoring OCR progress
  int page = 0;
  std::thread t1(ocrProcess, api, monitor);
  std::thread t2(monitorProgress, monitor, page);
  t1.join();
  t2.join();

  auto processEnd = std::chrono::steady_clock::now();
  processDuration = processEnd - processStart;
  processDuration = std::chrono::duration<double, std::milli>(
      std::round(processDuration.count()));
  std::cout << "\nTesseract 4 processing time: " << (int)processDuration.count()
            << " milliseconds\n";
#ifdef DEBUG_RECORD_PERFORMANCE
  std::fstream outputFile;
  outputFile.open(outputFileName, std::fstream::app);
  outputFile.close();
  outputFile.open(outputFileName, std::ios::in);
  char tempChar[1];
  unsigned int fsize = 0;
  unsigned int trial = 0;
  while (outputFile.read(tempChar, 1)) {
    // garbage
    // std::cout << tempChar;
    fsize++;
    if (*tempChar == '\n')
      trial++;
  }
  outputFile.close();
  outputFile.open(outputFileName, std::fstream::app);
  if (fsize == 0) {
    // empty file
    outputFile << "Trial,OCR Engine Mode,Path,Language,Runtime (ms)\n";
    trial = 1;
  }
  // outputFile
  std::cout << "WROTE: " << trial << "," << oem << "," << dataPath << ","
            << language << "," << (int)processDuration.count() << "\n";
  outputFile << trial << "," << oem << "," << dataPath << "," << language << ","
             << (int)processDuration.count() << "\n";
  outputFile.close();
#endif

  // Words and boundings
  tesseract::ResultIterator *ri = api->GetIterator();
  tesseract::PageIteratorLevel level = tesseract::RIL_WORD;
#ifdef DEBUG_BOUNDING_BOX
  printf("Words and bounding:\n");
  if (ri) {
    do {
      const char *word = ri->GetUTF8Text(level);
      float conf = ri->Confidence(level);
      int x1, y1, x2, y2;
      ri->BoundingBox(level, &x1, &y1, &x2, &y2);
      printf("word: '%s';  \tconf: %.2f; BoundingBox: %d,%d,%d,%d;\n", word,
             csonf, x1, y1, x2, y2);
      delete[] word;
    } while (ri->Next(level));
  }
#endif
  // Get OCR result
  // outText = api->GetUTF8Text();
  // printf("\nOCR output:\n%s", outText);

  // output hOCR file
  outText = api->GetHOCRText(0);

  std::fstream file(outputDataPath, std::fstream::out);
  if (file) {
    file << outText;
    file.close();
    printf("\nHOCR output SUCCESS:\n%s", outputDataPath.c_str());
  } else {
    printf("\nHOCR output FAILURE: File Could not be created:\n%s",
           outputDataPath.c_str());
  }

  // Destroy used object and release memory
  api->End();
  delete[] outText;
  pixDestroy(&image);
  system("pause");
  return 0;
}
