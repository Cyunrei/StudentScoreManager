cmake_minimum_required(VERSION 3.15)
project(StudentScoreManager)
set(CMAKE_CXX_STANDARD 20)

if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fexec-charset=GBK")
endif (WIN32)

add_executable(StudentScoreManager main.cpp Layout.cpp Layout.h Check.cpp Check.h Encryption.cpp Encryption.h Data.cpp Data.h Coding.cpp Coding.h view.h Protection.cpp Protection.h)
