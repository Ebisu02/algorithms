//
// Created by admin on 17.06.22.
//

#include "../main_lib.h"

void shell_sort(int arr[], int size) {
    int* h;
    h = new int[size];
    int k, t, j;
    int m = log(size) / log(2) - 1;
    h[0] = 1;
    for (int i = 1; i < m; ++i) {
        h[i] = 2 * h[i - 1] + 1;
    }
    for (; m >= 1; --m) {
        k = h[m - 1];
        for (int i = k; i < size; i++) {
            t = arr[i];
            for (j = i - k; j >= 0 and t < arr[j]; j = j - k) {
                arr[j + k] = arr[j];
            }
            arr[j + k] = t;
        }
    }
    return;
}

void shell_sort_lesson(int arr[], int size) {
    int* h;
    h = new int[size];
    int k, t, j;
    int m = log(size) / log(2) - 1;
    h[0] = 1;
    for (int i = 1; i < m; ++i) {
        h[i] = 2 * h[i - 1] + 1;
    }
    for (; m >= 1; --m) {
        k = h[m - 1];
        for (int i = k; i < size; i++) {
            t = arr[i];
            for (j = i - k; j >= 0 && t < arr[j]; j = j - k) {
                arr[j + k] = arr[j];
            }
            arr[j + k] = t;
        }
    }
    return;
}

void shell_sort_adv_lesson(int arr[], int size) {
    for (int i = size / 2; i > 0; i /= 2)
    {
        for (int j = i; j < size; j += 1)
        {
            int temp = arr[j];
            int z;
            for (z = j; z >= i && arr[z - i] > temp; z -= i) {
                arr[z] = arr[z - i];
            }
            arr[z] = temp;
        }
    }
    return;
}
