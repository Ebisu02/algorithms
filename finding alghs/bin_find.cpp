//
// Created by admin on 17.06.22.
//

#include "../main_lib.h"

int bin_find_mod(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
        if (arr[right] == key) {
            return right;
        }
    }
    return -1;
}

int bin_find(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}