cmake_minimum_required(VERSION 3.26.3 FATAL_ERROR)

project(Loader_setup)

add_executable(Loader_setup Loader_setup/main.cpp
dirExists.cpp
EngineClass.cpp
OpenFileDlgClass.cpp
Utf16ToUtf8_Class.cpp
WndProcClass.cpp
dirExists.h
EngineClass.h
OpenFileDlgClass.h
Utf16ToUtf8_Class.h
WndProcClass.h
)

