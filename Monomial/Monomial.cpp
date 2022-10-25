#include "Monomial.h"
#include "FigIO.h"


float monomial::compute(float x) {
	return (float)this->coef * pow(x, this->power);
}

monomial monomial::derivative() {
	monomial x;
	x.coef = this->coef * this->power;
	x.power = this->power - 1;
	return x;
}
monomial monomial::anti_deri() {
	monomial x;
	x.coef = this->coef / (this->power + 1);
	x.power = this->power + 1;
	return x;
}
bool monomial::operator== (monomial b) {
	if (coef == b.coef && power == b.power) return true;
	return false;
}
monomial monomial::operator+(monomial b) {
	if (power != b.power) return *this;
	else return monomial(coef + b.coef, power);
}
monomial monomial::operator-(monomial b) {
	if (power != b.power) return *this;
	else return monomial(coef - b.coef, power);
}
monomial monomial::operator*(monomial b) {
	return monomial(coef * b.coef, power + b.power);
}
monomial monomial::operator/(monomial b) {
	return monomial(coef / b.coef, power - b.power);
}

