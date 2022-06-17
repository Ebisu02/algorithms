//
// Created by admin on 17.06.22.
//

#include "../main_lib.h"

void heapify(int arr[], int n, int i)
{
    // Функция чтобы скопировать поддерево с корневым узлом i,
    // которая является индексом в массиве arr[].
    // n - размер дерева
    int largest = i; // Задаем наибольший как корень дерева
    int left = 2 * i + 1; // Левый = 2 * i + 1
    int right = 2 * i + 2; // Правый = 2 * i + 2
    // Если левый ребенок больше, чем корень
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    // Если правый ребенок на данный момент больше самого большого
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    // Если наибольший не корень
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Рекурсивно скопируем поддерево
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    // Строим дерево
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Один за другим извлекаем элемент из дерева
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий элемент корень в конец
        swap(arr[0], arr[i]);
        // Вызываем построение новой кучи
        heapify(arr, i, 0);
    }
}

void heapify_lesson(int arr[], int left, int right) {
    int x = arr[left];
    int i = left;
    while (1) {
        int j = 2 * i;
        if (j > right) {
            break;
        }
        if ((j < right) && (arr[j + 1] <= arr[j])) {
            ++j;
        }
        if (x <= arr[j]) {
            break;
        }
        arr[i] = arr[j];
        i = j;
    }
    arr[i] = x;
}

void heap_sort_lesson(int arr[], int size) {
    int left = (size / 2);
    while (left >= 0) {
        heapify(arr, left, size);
        --left;
    }
    int right = size;
    while (right >= 1) {
        swap(arr[0], arr[right]);
        --right;
        heapify(arr, 0, right);
    }
    return;
}
