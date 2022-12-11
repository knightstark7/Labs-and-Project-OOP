#pragma once
template <class T>
istream& operator>>(istream& is, vector<T>& a) {
    T f{};
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

template <class T>
ostream& operator<<(ostream& os, vector<T>& a) {
    for (int i = 0; i < a.size(); i++) {
        os << a[i] << " ";
    }
    os << "\n";
    return os;
}

template <class T>
class SATest : public ProgramFrame {
    SortArray<T> * mAlg;
    vector<T> Data;
public:
    SATest(SortArray<T> *pAlg){
            mAlg = pAlg;
    }
    void Input(istream& is) {
        is >> Data;
    }
    bool Check() {
        return Data.size() > 0;
    }
    void Output(ostream& os) {
        os << "Result after sorting: ";
        os << Data;
        Data.clear();
    }
    void startMessage(ostream& os) {
        os << "Please input the T array to be sorted: " << endl;
    }
    void Process() {

            if (mAlg != NULL) mAlg->Process(Data);
    }
    //operator >> vecto T
    friend istream& operator>>(istream& is, vector<T>& a);
    //operator << vector T
    friend ostream& operator<<(ostream& os, vector<T>& a);
};

