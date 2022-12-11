#pragma once
#include"SortArray.h"
#include"ProgramFrame.h"
template <class T>
class InterchangeS : public SortArray<T> {
public:
    void Process(vector<T>& a);
};

template <class T>
void InterchangeS<T>::Process(vector<T>& a){
	int i, j;
	T t;
	for (i = 0; i < a.size() - 1; i++) {
		for (j = i + 1; j < a.size(); j++) {
			if (a[i] > a[j]) {
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
}
