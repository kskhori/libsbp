cmake_minimum_required(VERSION 2.8.9)
project(libsbp_example)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_C_FLAGS "-Wall -Werror -Wno-error=deprecated-declarations -std=gnu99")

add_executable(libsbp_example example.c)

find_package(PkgConfig)
pkg_check_modules(LIBSERIALPORT libserialport)
link_directories(${LIBSERIALPORT_LIBRARY_DIRS})
include_directories(${LIBSERIALPORT_INCLUDE_DIRS})

link_directories("/usr/local/lib/")
include_directories("/usr/local/include/")

target_link_libraries(libsbp_example serialport sbp)
