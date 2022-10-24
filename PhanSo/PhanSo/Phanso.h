#include <iostream>
using namespace std;

class Phanso {
private:
    int tuso;
    int mauso;
public:
    int getTuso();
    int getMauso();
    void setTuso(int num);
    void setMauso(int num);
    void inversion();
    void reduction();
    Phanso add(Phanso b);
    Phanso sub(Phanso b);
    Phanso mul(Phanso b);
    Phanso div(Phanso b);
    friend istream& operator >> (istream& in, Phanso& ps);
    friend ostream& operator << (ostream& os, const Phanso& ps);
};
