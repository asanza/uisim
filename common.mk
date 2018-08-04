ifeq ("$(V)","1")
Q :=
vecho := @true
else
Q := @
vecho := @echo
endif

ifeq ("$(BUILD)","WINDOWS")
CC = x86_64-w64-mingw32-gcc
CXX = x86_64-w64-mingw32-g++
LD = x86_64-w64-mingw32-ld
AR = x86_64-w64-mingw32-ar
SDL2_INCLUDE_PATH = /usr/local/x86_64-w64-mingw32/include
SDL2_LIBRARY_PATH = /usr/local/x86_64-w64-mingw32/lib
endif