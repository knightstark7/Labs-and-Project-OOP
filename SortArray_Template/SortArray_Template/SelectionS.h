#pragma once
#include"SortArray.h"
#include"ProgramFrame.h"
template <class T>
class SelectionS : public SortArray<T> {
public:
    void Process(vector<T>& a);
};

template <class T>
void SelectionS<T>::Process(vector<T>& a) {
    int i, j, k;
    T t;
    for (i = 0; i < a.size(); i++) {
        k = i;
        for (j = i + 1; j < a.size(); j++) {
            if (a[j] < a[k]) k = j;
        }
        t = a[i];
        a[i] = a[k];
        a[k] = t;
    }
}