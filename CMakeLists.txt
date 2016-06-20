project(lg-java)
cmake_minimum_required(VERSION 2.8)
include_directories("./include" $ENV{PATH})
aux_source_directory(./src SRC_LIST)

find_package (Threads REQUIRED)

IF (CMAKE_COMPILER_IS_GNUCXX)
  add_definitions( "-std=gnu11 -Wall -pedantic -ansi -O0" )
ELSEIF (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_definitions( "-std=c11 -Wall -pedantic -ansi -O0" )
ELSEIF (MSVC)
  # On by default
ENDIF ()

if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(WINDOWS TRUE)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(LINUX TRUE)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(MACOSX TRUE)
endif()

add_executable(lg-java ${SRC_LIST})

if (WINDOWS)
	target_link_libraries(lg-java ${CMAKE_THREAD_LIBS_INIT})
else(WINDOWS)
	# nothing to do here
endif(WINDOWS)


