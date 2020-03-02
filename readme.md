# Tesseract static libraries for MinGW64
Includes a static library linked test program for tesseract in windows with MinGW64 compiler. All static libraries are prebuilt for linking.

Features demonstrated:
* OCR of image
* Output as hocr file
* monitor OCR progress

Credit to:
* MSYS2 (https://msys2.duckdns.org/package/mingw-w64-x86_64-tesseract-ocr?repo=mingw64)
* Alexpux (https://github.com/msys2/MINGW-packages) 

for all the prebuilt libraries except for leptonica static libraries

Compiler: 
* gcc (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0

Library: 
* Tesseract 4.1.0-1
* leptonica 1.78.0
* harfbuzz 2.6.4
* and many others the libraries above depend on.

## Building Harfbuzz
1. Download the PKGBUILD: https://github.com/msys2/MINGW-packages/tree/master/mingw-w64-harfbuzz
2. In MSYS2:
```shell
makepkg-mingw -sCLf
```
