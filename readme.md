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

# Build Examples

## MSYS2 and cmake
```shell
cmake -G "MSYS Makefiles" -B build
cd build
make
./CommandLine.exe
```

# Development Progress

## 12/22/2019
Dealing with compiling errors:

```shell
17:32:17 **** Incremental Build of configuration Debug for project receiptFiler ****
Info: Internal Builder is used for build
g++ "-LC:\\Users\\admin\\eclipse-workspace\\receiptFiler\\lib" -fopenmp -o receiptFiler.exe "src\\receiptFiler.o" "src\\tesseractTest.o" -ltesseract -llept -lopenjp3d -lopenjpwl -lopenmj2 -ljpeg -lpango-1.0 -lpangocairo-1.0 -lpangoft2-1.0 -lpangowin32-1.0 -lharfbuzz-gobject -lharfbuzz-icu -lharfbuzz-subset -lharfbuzz -lcairo -lpixman-1 -lgraphite2 -lglib-2.0 -lgio-2.0 -lgmodule-2.0 -lgobject-2.0 -lgthread-2.0 -ltiff -lgif -lwebp -lasprintf -lcharset -lcrypto -ldatrie -larchive -lexpat -lffi -lfontconfig -lformw -lfribidi -lgettextlib -lgettextpo -lgmp -lgmpxx -lgnurx -lpng -lfreetype -lopenjp2 -lhistory -liconv -licudt -licuin -licuio -licutest -licutu -licuuc -lz -lintl -llcms2 -llzma -lpanelw -lpcre -lpcre16 -lpcre32 -lpcrecpp -lpcreposix -lpng16 -lreadline -lregex -lsqlite3 -lws2_32 -lbz2 -lssl -ltasn1 -lthai -ltre -lturbojpeg -lzstd -llzo2 -lmenuw -lmpc -lmpdec -lmpfr -lncurses -lncurses++w -lncurses++w_g -ltiffxx -ltkstub86 -lwebpdecoder -lwebpdemux -lwebpmux -lncursesw -lncursesw_g -lbcrypt -lsystre -lole32 -lwinmm -lshlwapi -lstdc++ -luser32 -lkernel32 -lgdi32 -lcomdlg32 -lpsapi -lwsock32 -lhogweed -lnettle -llz4 -lm 
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(utils1.o):(.text+0x1253): undefined reference to `__imp__difftime64'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x17a): undefined reference to `__imp_opj_stream_create'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x195): undefined reference to `__imp_opj_stream_set_user_data'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x1c8): undefined reference to `__imp_opj_stream_set_user_data_length'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x1d8): undefined reference to `__imp_opj_stream_set_read_function'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x1e8): undefined reference to `__imp_opj_stream_set_write_function'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x1f8): undefined reference to `__imp_opj_stream_set_skip_function'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x208): undefined reference to `__imp_opj_stream_set_seek_function'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x348): undefined reference to `__imp_opj_version'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x61f): undefined reference to `__imp_opj_image_create'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x7ba): undefined reference to `__imp_opj_set_default_encoder_parameters'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x80c): undefined reference to `__imp_opj_create_compress'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x83a): undefined reference to `__imp_opj_setup_encoder'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x871): undefined reference to `__imp_opj_start_compress'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x885): undefined reference to `__imp_opj_encode'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x899): undefined reference to `__imp_opj_end_compress'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x8a4): undefined reference to `__imp_opj_stream_destroy'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x8ad): undefined reference to `__imp_opj_destroy_codec'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x8b8): undefined reference to `__imp_opj_image_destroy'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x9c5): undefined reference to `__imp_opj_destroy_codec'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x9d0): undefined reference to `__imp_opj_image_destroy'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xa1f): undefined reference to `__imp_opj_set_info_handler'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xa32): undefined reference to `__imp_opj_set_warning_handler'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xa45): undefined reference to `__imp_opj_set_error_handler'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xb95): undefined reference to `__imp_opj_stream_destroy'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xb9e): undefined reference to `__imp_opj_destroy_codec'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xba9): undefined reference to `__imp_opj_image_destroy'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xc15): undefined reference to `__imp_opj_stream_destroy'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xc1e): undefined reference to `__imp_opj_destroy_codec'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xc29): undefined reference to `__imp_opj_image_destroy'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xc75): undefined reference to `__imp_opj_destroy_codec'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xc80): undefined reference to `__imp_opj_image_destroy'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xcc7): undefined reference to `__imp_opj_image_destroy'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xd78): undefined reference to `__imp_opj_version'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xdec): undefined reference to `__imp_opj_set_default_decoder_parameters'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xe21): undefined reference to `__imp_opj_create_decompress'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xe4a): undefined reference to `__imp_opj_setup_decoder'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xe7f): undefined reference to `__imp_opj_read_header'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xede): undefined reference to `__imp_opj_set_decode_area'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xefa): undefined reference to `__imp_opj_decode'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xf0e): undefined reference to `__imp_opj_end_decompress'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xf1f): undefined reference to `__imp_opj_stream_destroy'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0xf28): undefined reference to `__imp_opj_destroy_codec'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x1201): undefined reference to `__imp_opj_stream_destroy'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x120a): undefined reference to `__imp_opj_destroy_codec'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x1218): undefined reference to `__imp_opj_image_destroy'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x124a): undefined reference to `__imp_opj_image_destroy'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x1262): undefined reference to `__imp_opj_set_info_handler'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x1275): undefined reference to `__imp_opj_set_warning_handler'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x1288): undefined reference to `__imp_opj_set_error_handler'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x12a5): undefined reference to `__imp_opj_destroy_codec'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x12c5): undefined reference to `__imp_opj_destroy_codec'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x12d1): undefined reference to `__imp_opj_stream_destroy'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x12df): undefined reference to `__imp_opj_image_destroy'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/liblept.a(jp2kio.o):(.text+0x130f): undefined reference to `__imp_opj_destroy_codec'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/libharfbuzz.a(libharfbuzz_la-hb-directwrite.o):(.text+0x183): undefined reference to `__imp_DWriteCreateFactory'
C:\Users\admin\eclipse-workspace\receiptFiler\lib/libharfbuzz.a(libharfbuzz_la-hb-uniscribe.o):(.text+0x33a): undefined reference to `__imp_UuidCreate'
collect2.exe: error: ld returned 1 exit status
```

leptonica library is looking for dynamic libraries when static needs to be found. Harfbuzz library seems to be having the same issue, but not confirmed.

### Solution
https://cloud.tencent.com/developer/article/1433585

Recompile leptonica and harfbuzz with macro definitions to indicate it will be linked statically.

## 12/22/2019

The solution above was correct. Leptonica had a make file in its src directory allowing it to be build a static library when invoked by MSYS2. Used MSYS2 to use PKGBUILD to make static harfbuzz. https://github.com/msys2/MINGW-packages/tree/master/mingw-w64-harfbuzz

## 3/1/2020

Using cmake now intead of eclipse.

