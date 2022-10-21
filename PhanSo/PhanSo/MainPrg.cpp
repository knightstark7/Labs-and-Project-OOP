#include "Phanso.h"

istream& operator >> (istream& in, Phanso& ps) {
	int tu, mau;
	cout << "Vui long nhap tu so: ";
	in >> tu;
	ps.setTuso(tu);
	do {
		cout << "Vui long nhap mau so: ";
		in >> mau;
	} while (mau == 0);
	ps.setMauso(mau);
	return in;
}

ostream& operator << (ostream& os, Phanso& ps) {
	os << ps.tuso << "/" << ps.mauso << endl;;
    return os;
}

int main() {
	Phanso a, b, c;
	cin >> a >> b;
	cout << a << b;
	c = a.add(b);
	//cout << c;
	//c = a.sub(b);
	//cout << c;
	//c = a.mul(b);
	//cout << c;
	//c = a.div(b);
	c.inversion();
	cout << c;
	system("pause");
	return 0;
}