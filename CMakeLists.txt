cmake_minimum_required(VERSION 3.16)

project(study_courses CXX)

FILE(GLOB subdirectories "./*")

foreach (subdirectory IN ITEMS ${subdirectories})
    IF (IS_DIRECTORY ${subdirectory} AND EXISTS ${subdirectory}/CMakeLists.txt)
        add_subdirectory(${subdirectory})
    endif ()
endforeach ()