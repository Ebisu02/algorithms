cmake_minimum_required(VERSION 3.22)
project(SIAOD_sem2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories("finding alghs")
include_directories("other alghs")
include_directories(sorts)
include_directories(structures)

add_executable(SIAOD_sem2
        "finding alghs/bin_find.cpp"
        "finding alghs/finding_alghs.h"
        "other alghs/fill_array_decrements.cpp"
        "other alghs/fill_array_increment.cpp"
        "other alghs/fill_array_randoms.cpp"
        "other alghs/get_array_run_series.cpp"
        "other alghs/get_int_array_sum.cpp"
        "other alghs/other_algs.h"
        "other alghs/print_array.cpp"
        sorts/bubble_sort.cpp
        sorts/digital_sort.cpp
        sorts/heap_sort.cpp
        sorts/insert_sort.cpp
        sorts/merge_series_sort.cpp
        sorts/merge_sort.cpp
        sorts/quick_sort.cpp
        sorts/select_sort.cpp
        sorts/shaker_sort.cpp
        sorts/shell_sort.cpp
        sorts/sorts.h
        structures/List.cpp
        structures/List.h
        structures/Stack.cpp
        structures/Stack.h
        main.cpp
        main_lib.h)
