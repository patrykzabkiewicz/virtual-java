project(lg-java)
cmake_minimum_required(VERSION 2.8)
include_directories("./include")
aux_source_directory(./src SRC_LIST)

add_executable(lg-java ${SRC_LIST})
