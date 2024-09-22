cmake_minimum_required(VERSION 3.16.3)

project(
    "simpleConfigParser"
    VERSION 1.0.0
    LANGUAGES C CXX)

# Global CMake variables are set here
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Project/Library Names
set(EXECUTABLE_NAME "main")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(JSONParser)

set(APPLICATION_CONFIG_FILE "testfile2")
add_subdirectory(configured)
add_subdirectory(app)
