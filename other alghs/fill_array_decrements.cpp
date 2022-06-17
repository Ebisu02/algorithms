//
// Created by admin on 17.06.22.
//
#include "../main_lib.h"

void fill_decrements(int arr[], int size) {
    for (int j = size, i = 0; i < size; --j, ++i) {
        arr[i] = j;
    }
    return;
}
