#include"Array.h"

istream& operator>>(istream& is, Array& arr) {
    int n;
    cout << "Input size: ";
    is >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Element at position " << i << ": ";
        is >> a[i];
    }
    arr.setArr(a, n);
    delete[] a;
    return is;
}

ostream& operator<<(ostream& os, const Array& arr) {
    for (int i = 0; i < arr.size; i++) {
        os << arr.pArr[i] << " ";
    }
    cout << endl;
    return os;
}

int main() {
    Array arr1(0);
    cout << arr1;
    cout << "Input array 1: " << endl;
    cin >> arr1;
    cout << "Array 1: " << arr1;
    cout << "Element at position 3 is: " << arr1[3] << endl;
    Array arr2(arr1);
    cout << "Array has been copied from Array 1: " << arr2;
    Array arr3;
    arr3 = arr1;
    cout << "Array has been assigned from Array 1: " << arr3; 
    return 0;
}