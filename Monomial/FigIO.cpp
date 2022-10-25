#include "FigIO.h"

istream& operator>>(istream& in, monomial& mono) {
	float coef, power;
	cout << "Enter coefficient: "; in >> coef;
	cout << "Enter power number: "; in >> power;
	mono.assign_coef(coef);
	mono.assign_pow(power);
	return in;
}

ostream& operator<<(ostream& out, monomial& mono) {
	out << mono.get_coef() << "x^" << mono.get_pow();
	return out;
}
