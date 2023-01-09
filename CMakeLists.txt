cmake_minimum_required(VERSION 3.16)
project(APA)

set(CMAKE_CXX_STANDARD 17)

add_executable(APA
        programa/src/main.cpp
        programa/src/headers/InputHandler.h++
        programa/src/bodies/InputHandler.cpp
        programa/src/bodies/fileNotFoundError.cpp
        programa/src/headers/fileNotFoundError.h++
        programa/src/bodies/Present.cpp
        programa/src/headers/Present.h++
        programa/src/bodies/FactoryPresent.cpp
        programa/src/headers/FactoryPresent.h++
        programa/src/bodies/guloso.cpp
        programa/src/headers/guloso.h++
        programa/src/bodies/OutputHandler.cpp
        programa/src/headers/OutputHandler.h++
        programa/src/headers/Sled.h
        programa/src/bodies/Sled.cpp
        programa/src/headers/Solution.h
        programa/src/bodies/Solution.cpp
        programa/src/headers/Vnd.h
        programa/src/bodies/Vnd.cpp
        )