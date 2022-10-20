
#include <iostream> 

using namespace std;

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

    void outputFraction();
};


int main(){


    return 0;
}