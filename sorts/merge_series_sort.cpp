/*
//
// Created by admin on 17.06.22.
//

#include "../main_lib.h"

// Представим, что список - серия и очередь C пустая по условия
template<typename T>
void merge_series_sort(List<T>& a, List<T>& b, List<T>& c) {
    int q = 0;
    int r = 0;
    c.clear();
    while (q < a.getSize() && r < b.getSize()) {
        if (a.data(q) <= b.data(r)) {
            c.push_back(a.data(q));
            ++q;
        }
        else {
            c.push_back(b.data(r));
            ++r;
        }
    }
    while (q < a.getSize()) {
        c.push_back(a.data(q));
        ++q;
    }
    while (r < b.getSize()) {
        c.push_back(b.data(r));
        ++r;
    }
    return;
}
*/
