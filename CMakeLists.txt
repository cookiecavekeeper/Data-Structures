cmake_minimum_required(VERSION 3.2)
project(DataStructures)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c)
add_executable(DataStructures ${SOURCE_FILES} queue.h queue.c sort.h sort.c list_sort.h list_sort.c hash_table.h hash_table.c)