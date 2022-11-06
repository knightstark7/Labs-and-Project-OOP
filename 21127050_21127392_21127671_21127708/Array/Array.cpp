#include "Array.h"

Array::Array() {
    this->size = 0;
    this->pArr = NULL;
}

Array::Array(int n) {
    this->setSize(n);
    this->pArr = new int[size];
    for (int i = 0; i < size; i++) {
        pArr[i] = 0;
    }
}

Array::Array(int a[], int n) {
    this->setSize(n);
    this->pArr = new int[size];
    for (int i = 0; i < size; i++) {
        pArr[i] = a[i];
    }
}

Array::Array(const Array& arr) {
    this->size = arr.size;
    this->pArr = new int[size];
    for (int i = 0; i < arr.size; i++) {
        this->pArr[i] = arr.pArr[i];
    }
}

Array::~Array() {
    if (size > 0) {
        size = 0;
        delete[] pArr;
        pArr = NULL;
    }
}

Array& Array::operator=(const Array& arr) {
    if (this != &arr) {
        if (size > 0) {
            size = 0;
            delete[] pArr;
            pArr = NULL;
        }
        this->size = arr.size;
        this->pArr = new int[size];
        for (int i = 0; i < size; i++) {
            this->pArr[i] = arr.pArr[i];
        }
    }
    return *this;
}

int& Array::operator[](int index) {
    if (index < 0 || index >= size) {
        cout << "Index out of range!" << endl;
        exit(1);
    }
    return this->pArr[index];
}

Array::operator int* () {
    int* a = pArr;
    return a;
}

int Array::getSize() {
    return this->size;
}

void Array::setSize(int n) {
    if (n <= 0) {
        size = 0;
        pArr = NULL;
        return;
    }
    else
        size = n;
}

int* Array::getArr() {
    int* a = new int[size];
    for (int i = 0; i < size; i++) {
        a[i] = pArr[i];
    }
    return a;
}

void Array::setArr(int* Arr, int n) {
    if (size > 0) {
        size = 0;
        delete[] pArr;
        pArr = NULL;
    }
    this->setSize(n);
    pArr = new int[size];
    for (int i = 0; i < n; i++) {
        pArr[i] = Arr[i];
    }
}

