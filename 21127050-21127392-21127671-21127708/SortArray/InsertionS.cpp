#include"InsertionS.h"

void InsertionS::Process(vector<float>& a) {
    int i, j;
    float t;
    for (i = 1; i < a.size(); i++) {
        t = a[i];
        for (j = i - 1; j >= 0 && a[j] > t; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = t;
    }
}