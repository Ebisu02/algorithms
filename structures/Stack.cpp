/*
//
// Created by admin on 17.06.22.
//

#include "Stack.h"

template <typename T>
Stack<T>::Stack() {
    Size = 0;
    head = nullptr;
}


template <typename T>
Stack<T>::~Stack() {
    clear();
}

template<typename T>
void Stack<T>::pop()
{
    Node<T>* Temp;
    Temp = head;
    if (Temp != nullptr && Size > 1) {
        head = Temp->pNext;
        delete Temp;
    }
    else {
        delete Temp;
    }
    --Size;
}

template<typename T>
void Stack<T>::push(T data)
{
    Node<T>* Temp;
    Temp = new Node<T>;
    Temp->data = data;
    if (head == nullptr) {
        head = Temp;
    }
    else {
        Temp->pNext = head;
        head = Temp;
    }
    ++Size;
}

template<typename T>
void Stack<T>::clear()
{

    while (Size) {
        pop();
    }

}

template<typename T>
int Stack<T>::getSize()
{
    return Size;
}

template<typename T>
void Stack<T>::fillInc(int size)
{
    int count = 0;
    while (count < size) {
        push(count + 1);
        ++count;
    }
}

template<typename T>
void Stack<T>::fillDec(int size)
{
    int count = 0;
    while (count < size) {
        push(size - count);
        ++count;
    }
}

template<typename T>
void Stack<T>::fillRand(int size)
{
    int count = 0;
    srand(time(nullptr));
    while (count < size) {
        push(rand() % size);
        ++count;
    }
}

template<typename T>
void Stack<T>::print()
{
    Node<T>* Temp = head;
    while (Temp) {
        cout << Temp->data << " ";
        Temp = Temp->pNext;
    }
}

template<typename T>
int Stack<T>::checkSum()
{
    int sum = 0;
    Node<T>* Temp = head;
    while (Temp) {
        sum += Temp->data;
        Temp = Temp->pNext;
    }
    return sum;
}

template<typename T>
int Stack<T>::runNumber()
{
    int run = 1;
    Node<T>* Temp = head;
    while (Temp->pNext) {
        if (Temp->data < Temp->pNext->data) {
            ++run;
        }
        Temp = Temp->pNext;
    }
    return run;
}

*/
