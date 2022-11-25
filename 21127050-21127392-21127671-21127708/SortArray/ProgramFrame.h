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