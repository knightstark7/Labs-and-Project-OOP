#pragma once
#include"SortArray.h"
#include"ProgramFrame.h"
template <class T>
class InsertionS : public SortArray<T> {
public:
    void Process(vector<T>& a);
};

template <class T>
void InsertionS<T>::Process(vector<T>& a){
    int i, j;
    T t;
    for (i = 1; i < a.size(); i++) {
        t = a[i];
        for (j = i - 1; j >= 0 && a[j] > t; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = t;
    }
}
