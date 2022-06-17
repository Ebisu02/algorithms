//
// Created by admin on 17.06.22.
//

#include "../main_lib.h"

void quick_sort_lesson(int arr[], int size, int left) {
    int right = size;
    int x = arr[left];
    int i = left;
    int j = right;
    while ( i <= j) {
        while (arr[i] < x) {
            ++i;
        }
        while (arr[j] > x) {
            --j;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
    if (left < j) {
        quick_sort_lesson(arr, j, left);
    }
    if (i < right) {
        quick_sort_lesson(arr, right, i);
    }
    return;
}
