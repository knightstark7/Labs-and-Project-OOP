#include<iostream>
using namespace std;

class Array {
private:
    int* pArr;
    int size;
public:
    Array();
    Array(int n);
    Array(int a[], int n);
    Array(const Array& arr);
    Array& operator=(const Array& arr);
    int& operator[](int index);
    operator int* ();
    int getSize();
    void setSize(int n);
    int* getArr();
    void setArr(int* pArr, int n);
    friend istream& operator>>(istream& is, Array& arr);
    friend ostream& operator<<(ostream& os, const Array& arr);
    ~Array();
};


