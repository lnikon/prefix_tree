cmake_minimum_required(VERSION 3.0.0)
project(trie VERSION 0.1.0)

include(CTest)
enable_testing()

set(LIB_LOCAL "include/")
include_directories(${LIB_LOCAL})

file(GLOB SOURCES "src/*.cpp")
file(GLOB INCLUDES "include/*.h")

add_executable(trie ${SOURCES} ${INCLUDES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
