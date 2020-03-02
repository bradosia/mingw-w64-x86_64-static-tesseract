cmake_minimum_required(VERSION 3.1)

project(mingw-w64-x86_64-static-tensorflow VERSION 1.0.0 LANGUAGES CXX)
set(BIN_1 CommandLine)
set(BIN_2 ShellAPI)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.10")

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

include_directories(
  third_party
  third_party/leptonica/include
  third_party/tesseract/include
)

link_directories(
  lib/
)

set(BIN_1_SOURCES
  src/CommandLine/main.cpp
)

set(BIN_2_SOURCES
  src/ShellAPI/main.cpp
)

add_executable(${BIN_1} ${BIN_1_SOURCES})
add_executable(${BIN_2} ${BIN_2_SOURCES})

target_link_libraries(${BIN_1}
tesseract
lept
openjp3d
openjpwl
openmj2
jpeg
pango-1.0
pangocairo-1.0
pangoft2-1.0
pangowin32-1.0
harfbuzz-gobject
harfbuzz-icu
harfbuzz-subset
harfbuzz
cairo
pixman-1
graphite2
glib-2.0
gio-2.0
gmodule-2.0
gobject-2.0
gthread-2.0
tiff
gif
webp
asprintf
charset
crypto
datrie
archive
expat
ffi
fontconfig
formw
fribidi
gettextlib
gettextpo
gmp
gmpxx
gnurx
png
freetype
openjp2
history
iconv
icudt
icuin
icuio
icutest
icutu
icuuc
z
intl
lcms2
lzma
panelw
pcre
pcre16
pcre32
pcrecpp
pcreposix
png16
readline
regex
sqlite3
ws2_32
bz2
ssl
tasn1
thai
tre
turbojpeg
zstd
lzo2
menuw
mpc
mpdec
mpfr
ncurses
ncurses++w
ncurses++w_g
tiffxx
tkstub86
webpdecoder
webpdemux
webpmux
ncursesw
ncursesw_g
bcrypt
systre
ole32
winmm
shlwapi
stdc++
user32
kernel32
gdi32
comdlg32
psapi
wsock32
hogweed
nettle
lz4
m
rpcrt4
)

# Post Build
# Copy default setttings
#add_custom_command(TARGET ${libsh_name} POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/plugins/")
add_custom_command(TARGET ${BIN_1} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory "${PROJECT_SOURCE_DIR}/share/" "${CMAKE_BINARY_DIR}/share/")
