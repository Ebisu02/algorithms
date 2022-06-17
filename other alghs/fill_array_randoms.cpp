//
// Created by admin on 17.06.22.
//
#include "../main_lib.h"

void fill_randoms(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % size;
    }
    return;
}
