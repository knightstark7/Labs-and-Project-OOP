#include"Complex.h"



istream& operator>>(istream& in, Complex& c) {
    cout << "Please input real part: ";
    in >> c.real;
    cout << "Please input imaginary part: ";
    in >> c.imag;
    return in;
}

ostream& operator<<(ostream& out, const Complex& c) {
    if (c.real != 0) out << c.real;
    if (c.imag != 0)
    {
        if (c.imag == -1) out << "-i";
        else if (c.imag == 1)
        {
            if (c.real == 0) out << "i";
            else out << "+i";
        }
        else
        {
            if (c.real != 0 && c.imag > 0)
                out << "+" << c.imag << "i" << endl;
            else
                out << c.imag << "i" << endl;
        }
    }
    if (c.real == 0 && c.imag == 0)
        out << "0" << endl;
    return out;
}

int main() {
    Complex c1, c2, c3;
    cout << "Enter the first complex number: " << endl;
    cin >> c1;
    cout << endl;
    cout << "Enter the second complex number: " << endl;
    cin >> c2;
    cout << endl;
    cout << "The modulus of the first complex numbers is: " << c1.computeModule() << endl;
    cout << "The modulus of the second complex numbers is: " << c2.computeModule() << endl << endl;
    c3 = c1 + c2;
    cout << "The sum of the two complex numbers is: " << c3 << endl;
    c3 = c1 - c2;
    cout << "The difference of the two complex numbers is: " << c3 << endl;
    c3 = c1 * c2;
    cout << "The product of the two complex numbers is: " << c3 << endl;
    c3 = c1 / c2;
    cout << "The quotient of the two complex numbers is: " << c3 << endl;
    return 0;
}