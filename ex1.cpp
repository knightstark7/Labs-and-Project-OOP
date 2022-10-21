
#include <iostream> 1

using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(a, a % b);
}

class fraction{
private:
    int numerator;
    int denominator;

public:
    void inputFraction(){
        cout << "Please enter the numerator: ";
        cin >> numerator;
        cout << "Please enter the denominator: ";
        cin >> denominator;
    }

    void outputFraction(){
        cout << "The faction is: " << numerator << " / " << denominator;
    }

    int getNumerator(){
        return numerator;
    }

    int getDenominator(){
        return denominator;
    }

    void assignNumerator(int a){
        numerator = a;
    }

    void assignDenominator(int b){
        denominator = b;
    }

    fraction inversion(){
        fraction a;
        a.numerator = denominator;
        a.denominator = numerator;
        return a;
    }
    void reduction(){
        int temp = gcd(numerator, denominator);
        numerator /= temp;
        denominator /= temp;
    }

    fraction add(fraction b){
        fraction c;
        c.numerator = numerator * b.denominator + denominator * b.numerator;
        c.denominator = denominator * b.denominator;
        c.reduction();
        return c;
    }

    fraction sub(fraction b){
        fraction c;
        c.numerator = numerator * b.denominator - denominator * b.numerator;
        c.denominator = denominator * b.denominator;
        c.reduction();
        return c;
    }

    fraction mul(fraction b){
        fraction c;
        c.numerator = numerator * b.numerator;
        c.denominator = denominator * b.denominator;
        c.reduction();
        return c;
    }

    fraction div(fraction b){
        fraction c;
        c.numerator = numerator * b.denominator;
        c.denominator = denominator * b.numerator;
        c.reduction();
        return c;
    }

};



int main(){
    fraction a, b, c;
    a.inputFraction();
    b.inputFraction();
    c = a.mul(b);
    c.outputFraction();

    return 0;
}