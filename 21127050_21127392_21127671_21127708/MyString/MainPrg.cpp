#include "MyString.h"

istream& operator>>(istream& in, MyString& s) {
	char* temp = new char[256];
	int count = 0;
	in.getline(temp, 256);
	while (temp[count] != '\0') {
		count++;
	}
	temp[count] = 0;
	s.assign(count, temp);
	delete[] temp;
	return in;
}

ostream& operator<<(ostream& out, MyString& s) {
	char* tmp = s.get_str();
	for (int i = 0; i < s.get_len(); i++) {
		out << tmp[i];
	}
	cout << endl;
	return out;
}

int main() {
	char temp[] = "!";
	MyString s, t;
	cin >> s >> t;
	cout << s;
	cout << s.get_len() << endl;
	cout << s.subString(2, 3) << endl;
	cout << s + t << endl;
	cout << s.insert(1, temp) << endl;
	cout << s.deleteSubString(0, 2) << endl;
	cout << s.replace(0, 2, temp) << endl;
	cout << s.findSubString(0, temp) << endl;
	return 0;
}