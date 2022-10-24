#include "Phanso.h"

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);   
}

int Phanso::getTuso() {
    return tuso;
}

int Phanso::getMauso() {
    return mauso;
}

void Phanso::setTuso(int tu) {
    tuso = tu;
}

void Phanso::setMauso(int mau) {
    if (mau != 0) {
        mauso = mau;
    }
}

void Phanso::inversion() {
    int temp = tuso;
    tuso = mauso;
    mauso = temp;
}
void Phanso::reduction() {
    int temp = gcd(tuso, mauso);
    tuso /= temp;
    mauso /= temp;
}

Phanso Phanso::add(Phanso b) {
    Phanso c;
    c.tuso = tuso * b.mauso + mauso * b.tuso;
    c.mauso = mauso * b.mauso;
    c.reduction();
    return c;
}

Phanso Phanso::sub(Phanso b) {
    Phanso c;
    c.tuso = tuso * b.mauso - mauso * b.tuso;
    c.mauso = mauso * b.mauso;
    c.reduction();
    return c;
}

Phanso Phanso::mul(Phanso b) {
    Phanso c;
    c.tuso = tuso * b.tuso;
    c.mauso = mauso * b.mauso;
    c.reduction();
    return c;
}

Phanso Phanso::div(Phanso b) {
    Phanso c;
    c.tuso = tuso * b.mauso;
    c.mauso = mauso * b.tuso;
    c.reduction();
    return c;
}
