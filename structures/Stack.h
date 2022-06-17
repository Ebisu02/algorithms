/*
//
// Created by admin on 17.06.22.
//
#pragma once

#include "../main_lib.h"

template <typename T>
class Stack {

public:

    Stack();
    ~Stack();

    void pop();
    void push(T data);
    int getSize();
    void clear();
    //
    void fillInc(int size);
    void fillDec(int size);
    void fillRand(int size);
    void print();
    int checkSum();
    int runNumber();

private:

    template <typename T>
    class Node {

    public:
        Node* pNext;
        T data;
        Node(T data = T(), Node* pNext = NULL) {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T>* head;
};
*/
