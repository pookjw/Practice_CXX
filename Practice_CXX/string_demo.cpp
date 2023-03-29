//
//  string_demo.cpp
//  Practice_CXX
//
//  Created by Jinwoo Kim on 1/8/23.
//

#include "string_demo.hpp"
#include <cstring>

// class methods

int String_Demo::num_strings = 0;

// construct String_Demo from C string
String_Demo::String_Demo(const char *s) {
    len = static_cast<int>(std::strlen(s));
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String_Demo::String_Demo() {
    len = 0;
    str = new char[1];
    str[0] = '\0';
    
    // or
//    str = (char *)0;
//    str = nullptr;
    
    num_strings++;
}

String_Demo::~String_Demo() {
    delete [] str;
    --num_strings;
}

std::ostream & operator<<(std::ostream &os, const String_Demo &st) {
    os << st.str;
    return os;
}

String_Demo::String_Demo(const String_Demo &other) {
    len = other.len;
    str = new char[len + 1];
    std::strcpy(str, other.str);
}

String_Demo & String_Demo::operator=(const String_Demo &other) {
    if (this == &other) {
        return *this;
    }
    
    delete [] str; // delete old string - replacing
    
    len = other.len;
    str = new char[len + 1];
    std::strcpy(str, other.str);
    return *this;
}

bool operator<(const String_Demo &st1, const String_Demo &st2) {
    std::cout << std::strcmp(st1.str, st2.str) << std::endl;
    // 알파벳 순서 비교
    if (std::strcmp(st1.str, st2.str) < 0) {
        return true;
    } else {
        return false;
    }
}

bool operator>(const String_Demo &st1, const String_Demo &st2) {
    return st2 < st1;
}

bool operator==(const String_Demo &st1, const String_Demo &st2) {
    return (std::strcmp(st1.str, st2.str) == 0);
}

char & String_Demo::operator[](const int i) {
    return str[i];
}

const char & String_Demo::operator[](const int i) const {
    return str[i];
}

std::ostream & operator<<(std::ostream &os, String_Demo &st) {
    os << st.str;
    return os;
}

std::istream & operator>>(std::istream &is, String_Demo &st) {
    char temp[String_Demo::CINLIM];
    is.get(temp, String_Demo::CINLIM);
    
    // nullptr 확
    if (is) {
        st = temp;
    }
    
    // newline 제거
    while (is && is.get() != '\n') {
        continue;
    }
    
    return is;
}
