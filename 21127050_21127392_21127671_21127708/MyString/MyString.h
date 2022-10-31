#include <iostream>
using namespace std;

class MyString {
private:
	char* str;
	int len;
public:
	int get_len();
	char* get_str();
	void assign(int, char*);
	char* subString(int, int);
	char* operator+(const MyString&);
	char* insert(int, char*);
	char* deleteSubString(int, int);
	char* replace(int, int, char*);
	char* findSubString(int, char*);
	friend istream& operator>>(istream&, MyString&);
	friend ostream& operator<<(ostream&, MyString&);
};
