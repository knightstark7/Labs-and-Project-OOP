#include"SATest.h"

istream& operator>>(istream& is, vector<float>& a) {
    float f;
    int n;
    do {
        cout << "Enter size of array: ";
        is >> n;
    } while (n <= 0);
    for (int i = 0; i < n; i++) {
        cout << "Input element " << i + 1 << " of the array: ";
        is >> f;
        a.push_back(f);
    }
    return is;
}

ostream& operator<<(ostream& os, vector<float>& a) {
    for (int i = 0; i < a.size(); i++) {
        os << a[i] << " ";
    }
    os << "\n";
    return os;
}

SATest::SATest(SortArray* pAlg) {
    mAlg = pAlg;
}

void SATest::Input(istream& is) {
    is >> Data;
}

bool SATest::Check() {
    return Data.size() > 0;
}

void SATest::Output(ostream& os) {
    os << "Result after sorting: ";
    os << Data;
    Data.clear();
}

// 
void SATest::startMessage(ostream& os) {
    os << "Please input the float array to be sorted: " << endl;
}

void SATest::Process() {
    if (mAlg != NULL) mAlg->Process(Data);
}