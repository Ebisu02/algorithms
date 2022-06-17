//
// Created by admin on 17.06.22.
//
#include "../main_lib.h"

int get_array_sum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}
