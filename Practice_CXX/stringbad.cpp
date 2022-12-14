//
//  stringbad.cpp
//  Practice_CXX
//
//  Created by Jinwoo Kim on 1/7/23.
//

#include "stringbad.hpp"
#include <cstring>

int StringBad::num_strings = 0;

// class methods

// construct StringBad from C string
StringBad::StringBad(const char *s) {
    len = static_cast<int>(std::strlen(s));
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    std::cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad::StringBad() {
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    std::cout << num_strings << ": \"" << str << "\" defualt object created\n";
}

StringBad::~StringBad() {
    std::cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    std::cout << num_strings << " left\n";
    delete [] str;
}

std::ostream & operator<<(std::ostream &os, const StringBad &st) {
    os << st.str;
    return os;
}
