//
//  stringbad.cpp
//  Practice_CXX
//
//  Created by Jinwoo Kim on 1/7/23.
//

#include "stringbad_2.hpp"
#include <cstring>

int StringBad_2::num_strings = 0;

// class methods

// construct StringBad from C string
StringBad_2::StringBad_2(const char *s) {
    len = static_cast<int>(std::strlen(s));
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    std::cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad_2::StringBad_2() {
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    std::cout << num_strings << ": \"" << str << "\" defualt object created\n";
}

StringBad_2::~StringBad_2() {
    std::cout << "\"" << str << "\" object deleted, ";
    --num_strings;
    std::cout << num_strings << " left\n";
    delete [] str;
}

std::ostream & operator<<(std::ostream &os, const StringBad_2 &st) {
    os << st.str;
    return os;
}

StringBad_2::StringBad_2(const StringBad_2 &other) {
    num_strings++;
    len = other.len;
    str = new char[len + 1];
    std::strcpy(str, other.str);
    std::cout << num_strings << ": \"" << str << "\" object created\n";
}

StringBad_2 & StringBad_2::operator=(const StringBad_2 &other) {
    if (this == &other) {
        return *this;
    }
    
    delete [] str; // delete old string - replacing
    
    len = other.len;
    str = new char[len + 1];
    std::strcpy(str, other.str);
    return *this;
}
