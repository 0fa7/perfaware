cmake_minimum_required(VERSION 3.20)

project(perfaware)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(perfaware)
target_sources(perfaware PRIVATE main.cpp)

add_executable(listing_1 listing_1.cpp)
target_sources(listing_1 PRIVATE listing_1.cpp)

add_executable(bench)
target_sources(bench PRIVATE bench.cpp)
target_link_libraries(bench benchmark)