/*
//
// Created by admin on 17.06.22.
//

#include "List.h"

template <typename T>
List<T>::List() {
    Size = 0;
    head = nullptr;
    tail = nullptr;
}


template <typename T>
List<T>::~List() {
    clear();
}

template<typename T>
void List<T>::pop_front()
{
    Node<T>* Temp = head;
    head = head->pNext;
    delete Temp;
    --Size;
}

template<typename T>
void List<T>::push_back(T data)
{

    if (head == nullptr) {
        head = new Node<T>(data);
        tail = head;
    }
    else {
        tail->pNext = new Node<T>(data);
        tail = tail->pNext;
        tail->pNext = nullptr;
    }

    ++Size;
}

template<typename T>
void List<T>::clear()
{

    while (Size) { // ���� Size > 0
        pop_front();
    }

}

template<typename T>
int List<T>::getSize()
{
    return Size;
}

template<typename T>
void List<T>::fillInc(int size)
{
    int count = 0;
    while (count < size) {
        push_back(count + 1);
        ++count;
    }
}

template<typename T>
void List<T>::fillDec(int size)
{
    int count = 0;
    while (count < size) {
        push_back(size - count);
        ++count;
    }
}

template<typename T>
void List<T>::fillRand(int size)
{
    int count = 0;
    srand(time(nullptr));
    while (count < size) {
        push_back(rand() % size);
        ++count;
    }
}

template<typename T>
void List<T>::print()
{
    if (Size > 0) {
        Node<T>* Temp = head;
        while (Temp) {
            cout << Temp->data << " ";
            Temp = Temp->pNext;
        }
    }
    else {
        return;
    }
}

template<typename T>
int List<T>::checkSum()
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
int List<T>::runNumber()
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

template<typename T>
T List<T>::data(int index)
{
    if (index >= Size || index < 0) {
        return 0;
    }
    if (index == 0)
    {
        return head->data;
    }
    Node<T>* Temp;
    Temp = head;
    int Current = 0;
    while (Temp)
    {
        if (Current == index) {
            return Temp->data;
        }
        Temp = Temp->pNext;
        ++Current;
    }
}

template<typename T>
T& List<T>::operator[](const int index) {

    Node<T>* Current = this->head;
    int counter = 0;
    while (Current != nullptr) {			// Пока это не конец списка
        if (counter == index) {				// Если мы попали в нужный элемент списка
            return Current->data;			// Возвращаем данные
        }
        Current = Current->pNext;			// Если не попали, то переходим к следующему
        ++counter;							// Увеличиваем индекс на котором мы сейчас находимся на 1
    }
}
*/
