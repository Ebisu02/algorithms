//
// Created by admin on 17.06.22.
//

#include "../main_lib.h"

void shaker_sort(int* arr, int size)
{
//    int M = 0, C = 0;
    int left = 0, right = size - 1;
    int flag = 1;
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)
        {
            //++C;
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                flag = 1;
                //++M;
            }
        }
        right--;
        for (int i = right; i > left; i--)
        {
            //++C;
            if (arr[i - 1] > arr[i])
            {
                swap(arr[i], arr[i - 1]);
                flag = 1;
                //++M;
            }
        }
        left++;
    }
}
