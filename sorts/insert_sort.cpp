//
// Created by admin on 17.06.22.
//

#include "../main_lib.h"

void insertSort(int arr[], int size) {
    for (int i = 1; i < size; i++)
    {
        //++c;
        int buf = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > buf)
        {
            //++c;
            arr[j + 1] = arr[j];
            j = j - 1;
            //++m;
        }
        arr[j + 1] = buf;
        //m += 2;
    }
    return;
}
