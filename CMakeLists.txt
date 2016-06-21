project(lg-java)
cmake_minimum_required(VERSION 2.8)
include_directories("./include" $ENV{PATH})

IF (WIN32)
  LINK_DIRECTORIES($ENV{PATH})
ENDIF()

find_library(PTHREAD pthread)
add_definitions( "-std=c11 -Wall -pedantic -O0" )
aux_source_directory(./src SRC_LIST)

add_executable(lg-java ${SRC_LIST})
target_link_libraries (lg-java ${PTHREAD})

