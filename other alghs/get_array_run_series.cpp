//
// Created by admin on 17.06.22.
//
#include "../main_lib.h"

int get_run_series(int arr[], int size) {
    int run = 0;
    for (int i = 0; i < size; ++i) {
        if (i == size - 1) {
            if (arr[i] <= arr[i - 1]) {
                ++run;
            }
        }
        else if (arr[i] <= arr[i + 1] && i != size - 1) {
            continue;
        }
        else {
            ++run;
            continue;
        }
    }
    if (run == 0) {
        ++run;
    }
    return run;
}
