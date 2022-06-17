//
// Created by admin on 17.06.22.
//

#include "../main_lib.h"

void select_sort(int arr[], int size) {
//    int M = 0, C = 0;
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
//            ++C;
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
//            ++M;
            swap(arr[i], arr[min]);
        }
    }
//    std::cout << "\nPrakti4eskoe kolvo peresilok - " << 3 * M << "\n" << "Prakti4eskoe kolvo sravneniy - " << C;
    return;
}

void select_sort_from_lesson(int arr[], int size) {
    int j, zm, num; //c = 0, m = 0;
    for (int i = 0; i < size; i++) {
        num = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[num]) {
                num = j;
            }
//            c++;
        }
        zm = arr[num];
        arr[num] = arr[i];
        arr[i] = zm;
//        ++m;
    }
}

