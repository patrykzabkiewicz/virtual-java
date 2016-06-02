project(testdroid-api-cpp)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

add_executable(lg-java ${SRC_LIST})
