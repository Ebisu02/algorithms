/*
//
// Created by admin on 17.06.22.
//

#include "../main_lib.h"

template <typename T>
class List {

public:

    List();
    ~List();

    void pop_front();
    void push_back(T data);
    int getSize();
    void clear();
    //
    void fillInc(int size);
    void fillDec(int size);
    void fillRand(int size);
    void print();
    int checkSum();
    int runNumber();
    T data(int index);
    T& operator[](const int index);


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
    Node<T>* tail;
    Node<T>* head;


    void DestroyList(List<T>& list, Node<T>* a, Node<T>* b, int n)
    {
        a = list.head;
        b = list.head->pNext;
        Node<T>* k = a;
        Node<T>* p = b;
        n = 1;
        while (p)
        {
            ++n;
            k->pNext = p->pNext;
            k = p;
            p = p->pNext;
        }
    }

    void MergeList(Node<T>* a, int q, Node<T>* b, int r, List<T>& c)
    {
        c.clear();
        while (q > 0&& r > 0)
        {
            if (a->data <= b->data)
            {
                c.push_back(a->data);
                --q;
                a = a->pNext;
            }
            else
            {
                c.push_back(b->data);
                --r;
                b = b->pNext;
            }
        }
        while (q > 0)
        {
            c.push_back(a->data);
            --q;
            a = a->pNext;
        }
        while (r > 0)
        {
            c.push_back(b->data);
            --r;
            b = b->pNext;
        }
    }

    void MergeSort(List<T>& list)
    {
        int n = list.getSize();
        Node<T>* a = head, * b = head->pNext;
        DestroyList(list, a, b, n);
        List<T> c[2];
        int p, q, r, m, i;
        p = 1;
        while (p < n)
        {
            i = 0;
            m = n;
            while (m > 0)
            {
                if (m >= p)
                {
                    q = p;
                }
                else
                {
                    q = m;
                }
                m -= q;
                if (m >= p)
                {
                    r = p;
                }
                else
                {
                    r = m;
                }
                m -= r;
                MergeList(a, q, b, r, c[i]);
                i = 1 - i;
            }
            a = c[0].head;
            b = c[1].head;
            p = 2 * p;
        }
        list = c[0];
    }

};

*/
