#include"InterchangeS.h"

void InterchangeS::Process(vector<float>& a) {
    int i, j;
    float t;
    for (i = 0; i < a.size(); i++) {
        for (j = i + 1; j < a.size(); j++) {
            if (a[j] < a[i]) {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
}