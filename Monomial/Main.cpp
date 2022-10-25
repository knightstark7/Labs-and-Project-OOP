#include "Monomial.h"
#include "FigIO.h"


int main() {
	monomial a, b, c;
	cin >> a;
	cout << a; cout << endl;
	cin >> b;
	cout << b; cout << endl;
	//cout << "A compute: " << a.compute(4) << endl;
	//cout << "B compute: " << b.compute(4) << endl;
	c = a.derivative();
	cout << "A derivative: " << c << endl;
	c = b.derivative();
	cout << "B derivative: " << c << endl;
	c = a.anti_deri();
	cout << "A anti-derivative: " << c << endl;
	c = b.anti_deri();
	cout << "B anti-derivative: " << c << endl;
	c = a + b;
	cout << "A + B = "; cout << c;
	if (c == a) {
		cout << " + "; cout << b << endl;
	}
	else cout << endl;
	c = a - b;
	cout << "A - B = " << c;
	if (c == a) {
		cout << " - " << b << endl;
	}
	else cout << endl;
	c = a * b;
	cout << "A * B = " << c << endl;
	c = a / b;
	cout << "A / B = " << c << endl;
	return 0;
}