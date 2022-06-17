//
// Created by admin on 17.06.22.
//

#include "../main_lib.h"

void bubble_sort(int arr[], int size) {
//    int M = 0; int C = 0;
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++) {
//            ++C;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
//                ++M;
            }
        }
//    std::cout << "\nPrakti4eskoe kolvo peresilok - " << M << "\n" << "Prakti4eskoe kolvo sravneniy - " << C;
    return;
}

