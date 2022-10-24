#include"Complex.h"

double Complex::getReal() {
    return real;
}

double Complex::getImag() {
    return imag;
}

void Complex::setReal(double r) {
    real = r;
}

void Complex::setImag(double i) {
    imag = i;
}

float Complex::computeModule() {
    return sqrt(real * real + imag * imag);
}

Complex Complex::operator+(const Complex& c) {
    Complex temp;
    temp.real = real + c.real;
    temp.imag = imag + c.imag;
    return temp;
}

Complex Complex::operator-(const Complex& c) {
    Complex temp;
    temp.real = real - c.real;
    temp.imag = imag - c.imag;
    return temp;
}

Complex Complex::operator*(const Complex& c) {
    Complex temp;
    temp.real = real * c.real - imag * c.imag;
    temp.imag = real * c.imag + imag * c.real;
    return temp;
}

Complex Complex::operator/(const Complex& c) {
    Complex temp;
    temp.real = (real * c.real + imag * c.imag) / (c.real * c.real + c.imag * c.imag);
    temp.imag = (imag * c.real - real * c.imag) / (c.real * c.real + c.imag * c.imag);
    return temp;
}

// Path: Complex.h