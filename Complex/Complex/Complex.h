#pragma once
#include<iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
public:
    double getReal();
    double getImag();
    void setReal(double r);
    void setImag(double i);
    float computeModule();
    Complex operator+(const Complex& c);
    Complex operator-(const Complex& c);
    Complex operator*(const Complex& c);
    Complex operator/(const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);
    friend ostream& operator<<(ostream& out, const Complex& c);
};

