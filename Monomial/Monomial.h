#pragma once

class monomial {
private:
	float coef, power;
public:
	monomial() { } // constructor 1
	monomial(float coef, float power) { // constructor 2
		this->coef = coef;
		this->power = power;
	}
	float get_coef() {
		return this->coef;
	}
	float get_pow() {
		return this->power;
	}
	void assign_coef(float coef) {
		this->coef = coef;
	}
	void assign_pow(float pow) {
		this->power = pow;
	}
	float compute(float x);
	monomial derivative();
	monomial anti_deri();
	bool operator== (monomial);
	monomial operator+ (monomial);
	monomial operator- (monomial);
	monomial operator* (monomial);
	monomial operator/ (monomial);
	~monomial() { };
};