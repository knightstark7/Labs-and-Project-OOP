#include<iostream>
#pragma once
using namespace std;
class ProgramFrame {
protected:
    virtual void startMessage(ostream&);
    virtual void Input(istream&) = 0;
    virtual bool Check() = 0;
    virtual void errorMessage(ostream&);
    virtual void Output(ostream&) = 0;
    virtual void Process() = 0;
    virtual bool askContinue(istream&, ostream&);
public:
    void run(istream&, ostream&);
};

void ProgramFrame::startMessage(ostream& os) {
    os << "Welcome, entering data: ";
}
void ProgramFrame::errorMessage(ostream& os) {
    os << "Input data error!" << endl;
}
bool ProgramFrame::askContinue(istream& is, ostream& os) {
    os << "Press y to continue, others to stop: ";
    char ch;  is >> ch;
    return (ch == 'Y' || ch == 'y');
}

void ProgramFrame::run(istream& is, ostream& os) {
    bool b = true;
    do {
        startMessage(os);
        Input(is);
        if (!Check()) {
            errorMessage(os);
            continue;
        }
        Process();
        Output(os);
        b = askContinue(is, os);
    } while (b);
}

