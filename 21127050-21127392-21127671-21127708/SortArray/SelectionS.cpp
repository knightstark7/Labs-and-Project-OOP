#include"SelectionS.h"

void SelectionS::Process(vector<float>& a) {
    int i, j, k;
    float t;
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