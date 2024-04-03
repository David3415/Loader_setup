cmake_minimum_required(VERSION 3.26.3 FATAL_ERROR)

project(Loader_setup)

add_executable(Loader_setup Loader_setup/main.cpp
Loader_setup/dirExists.cpp
Loader_setup/EngineClass.cpp
Loader_setup/OpenFileDlgClass.cpp
Loader_setup/Utf16ToUtf8_Class.cpp
Loader_setup/WndProcClass.cpp
Loader_setup/dirExists.h
Loader_setup/EngineClass.h
Loader_setup/OpenFileDlgClass.h
Loader_setup/Utf16ToUtf8_Class.h
Loader_setup/WndProcClass.h
)
