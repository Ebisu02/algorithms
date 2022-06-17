//
// Created by admin on 17.06.22.
//

#include "../main_lib.h"

void merge(int arr[], int sizeForArr, int L[], int sizeForL, int R[], int sizeForR)
{
    int i = 0;
    int j = 0;
    while (i < sizeForL || j < sizeForR)
    {
        if (i < sizeForL && j < sizeForR)
        {
            if (L[i] <= R[j])
            {
                arr[i + j] = L[i];
                ++i;
            }
            else
            {
                arr[i + j] = R[j];
                ++j;
            }
        }
        else if (i < sizeForL)
        {
            arr[i + j] = L[i];
            ++i;
        }
        else if (j < sizeForR)
        {
            arr[i + j] = R[j];
            ++j;
        }
    }
}

void merge_sort(int arr[], int size)
{
    if (size > 1)
    {
        int middle = size / 2;
        int rem = size - middle;
        int* L = new int[middle];
        int* R = new int[rem];
        for (int i = 0; i < size; ++i)
        {
            if (i < middle)
            {
                L[i] = arr[i];
            }
            else
            {
                R[i - middle] = arr[i];
            }
        }
        merge_sort(L, middle);
        merge_sort(R, rem);
        merge(arr, size, L, middle, R, rem);
    }
}
