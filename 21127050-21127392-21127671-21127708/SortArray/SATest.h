#pragma once
#include"SortArray.h"


class SATest : public ProgramFrame {
    SortArray* mAlg;
    vector<float> Data;
public:
    SATest(SortArray* pAlg);
    void Input(istream& is);
    bool Check();
    void Output(ostream& os);
    void startMessage(ostream& os);
    void Process();
    //operator >> vecto float
    friend istream& operator>>(istream& is, vector<float>& a);
    //operator << vector float
    friend ostream& operator<<(ostream& os, vector<float>& a);
};