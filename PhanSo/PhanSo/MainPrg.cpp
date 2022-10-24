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

ostream& operator << (ostream& os, const Phanso& ps) {
	os << ps.tuso << "/" << ps.mauso;
    return os;
}

int main() {
	Phanso a, b, c;
	cout << "Hay nhap phan so dau tien\n";
	cin >> a;
	cout << "\nHay nhap phan so thu hai\n";
	cin >> b;
	cout << "\nBan vua nhap 2 phan so la: " << a << " va " << b << "\n";
	cout << "Cac phep tinh duoc thuc hien voi cac phan so ban vua nhap: \n";

	c = a.add(b);
	c.reduction();
	cout << a << " + " << b << " = " << c << "\n";

	c = a.sub(b);
	c.reduction();
	cout << a << " - " << b << " = " <<	c << "\n";

	c = a.mul(b);
	c.reduction();
	cout << a << " * " << b << " = " << c << "\n"; 

	c = a.div(b);
	c.reduction();
	cout << a << " / " << b << " = " << c << "\n";

	cout << "\n";
	system("pause");
	return 0;
}