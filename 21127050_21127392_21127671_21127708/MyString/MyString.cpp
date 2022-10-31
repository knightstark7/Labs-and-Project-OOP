#include "MyString.h"

int MyString::get_len() {
    return this->len;
}

char* MyString::get_str() {
    return this->str;
}

void MyString::assign(int l, char* s) {
    this->len = l;
    this->str = new char[l];
    for (int i = 0; i < l; i++) {
        str[i] = s[i];
    }
}

char* MyString::subString(int pos, int num) {
    char* n_str = new char[num + 1];
    for (int i = 0; i < num; i++) {
        n_str[i] = *(this->str + pos + i);
        n_str[num] = '\0';
    }
    return n_str;
}

char* MyString::operator+(const MyString& b) {
    char* c = new char[len + b.len + 1];
    for (int i = 0; i < len; i++)
        c[i] = str[i];
    for (int i = len; i < len + b.len; i++)
        c[i] = b.str[i - len];
    c[len + b.len] = '\0';
    return c;
}

char* MyString::insert(int pos, char* str) {
    int sublen = 0;
    while (str[sublen] != '\0') {
        sublen++;
    }

    char* newStr = new char[len + sublen + 1];
    for (int i = 0; i < pos; i++) {
        newStr[i] = this->str[i];
    }
    for (int i = 0; i < sublen; i++) {
        newStr[pos + i] = str[i];
    }
    for (int i = pos; i < len; i++) {
        newStr[sublen + i] = this->str[i];
    }
    newStr[len + sublen] = '\0';
    this->str = new char[len + sublen + 1];
    for (int i = 0; i < len + sublen; i++)
        this->str[i] = newStr[i];
    this->str[len + sublen] = 0;
    this->len = len + sublen;
    return newStr;
}

char* MyString::deleteSubString(int pos, int numChar) {
    char* newStr = new char[len - numChar + 1];
    for (int i = 0; i < pos; i++) {
        newStr[i] = this->str[i];
    }
    for (int i = pos + numChar; i < len; i++) {
        newStr[i - numChar] = this->str[i];
    }
    newStr[len - numChar] = '\0';
    this->str = new char[len - numChar + 1];
    for (int i = 0; i < len - numChar; i++)
        this->str[i] = newStr[i];
    this->str[len - numChar] = 0;
    this->len = len - numChar;
    return newStr;
}

char* MyString::replace(int pos, int numChar, char* str) {
    int sublen = 0;
    while (str[sublen] != '\0') {
        sublen++;
    }
    char* newStr = new char[len - numChar + sublen + 1];
    for (int i = 0; i < pos; i++) {
        newStr[i] = this->str[i];
    }
    for (int i = 0; i < sublen; i++) {
        newStr[pos + i] = str[i];
    }
    for (int i = pos + numChar; i < len; i++) {
        newStr[sublen + i - numChar] = this->str[i];
    }
    newStr[len - numChar + sublen] = '\0';
    this->str = new char[len - numChar + sublen + 1];
    for (int i = 0; i < len - numChar + sublen; i++)
        this->str[i] = newStr[i];
    this->str[len - numChar + sublen] = 0;
    this->len = len - numChar + sublen;
    return newStr;
}

char* MyString::findSubString(int pos, char* str) {
    int sublen = 0;
    while (str[sublen] != '\0') {
        sublen++;
    }
    int i = pos;
    while (i < len) {
        if (this->str[i] == str[0]) {
            int j = 0;
            while (j < sublen) {
                if (this->str[i + j] != str[j]) {
                    break;
                }
                j++;
            }
            if (j == sublen) {
                return this->str + i;
            }
        }
        i++;
    }
    return NULL;
}