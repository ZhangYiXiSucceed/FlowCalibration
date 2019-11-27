cmake_minimum_required(VERSION 3.7)
project(VST20191105 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXE_LINKER_FLAGS "-lpthread ${CMAKE_EXE_LINKER_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "-lpthread ${CMAKE_EXE_LINKER_FLAGS}")

file(GLOB SOURCES
        main.c
        Mythread.c
        Mythread.h
        Net.c
        Net.h
        Queue.c
        Queue.h
        ReadConfig.c
        ReadConfig.h
        timer.c
        timer.h)
add_executable(VST20191105 main.c ${SOURCE_FILES} ${SOURCES})