if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "FATAL: In-source builds are not allowed.
                        You should create a separate directory for build files.")
endif()


CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(discloner
        LANGUAGES CXX
        VERSION 0.1
        DESCRIPTION "A multithread cloning tool")

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -DDEBUG")

ADD_EXECUTABLE(discloner src/main.cpp src/config.cpp)

