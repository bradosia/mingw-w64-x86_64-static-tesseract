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
```shell
$ gcc -v
Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-pc-msys/9.1.0/lto-wrapper.exe
Target: x86_64-pc-msys
Configured with: /msys_scripts/gcc/src/gcc-9.1.0/configure --build=x86_64-pc-msys --prefix=/usr --libexecdir=/usr/lib --enable-bootstrap --enable-shared --enable-shared-libgcc --enable-static --enable-version-specific-runtime-libs --with-arch=x86-64 --with-tune=generic --disable-multilib --enable-__cxa_atexit --with-dwarf2 --enable-languages=c,c++,fortran,lto --enable-graphite --enable-threads=posix --enable-libatomic --enable-libgomp --enable-libitm --enable-libquadmath --enable-libquadmath-support --disable-libssp --disable-win32-registry --disable-symvers --with-gnu-ld --with-gnu-as --disable-isl-version-check --enable-checking=release --without-libiconv-prefix --without-libintl-prefix --with-system-zlib --enable-linker-build-id --with-default-libstdcxx-abi=gcc4-compatible --enable-libstdcxx-filesystem-ts
Thread model: posix
gcc version 9.1.0 (GCC)
```

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
