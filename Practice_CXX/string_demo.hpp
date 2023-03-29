//
//  string_demo.hpp
//  Practice_CXX
//
//  Created by Jinwoo Kim on 1/8/23.
//

#ifndef string_demo_hpp
#define string_demo_hpp

#include <iostream>

class String_Demo {
private:
    /// length of string
    int len;
    
    /// number of objects
    static int num_strings;
public:
    static const int CINLIM = 80;
    
    /// pointer to string
    char *str;
    
    String_Demo(const char *s);
    String_Demo();
    ~String_Demo();
    
    friend std::ostream & operator<<(std::ostream &os, const String_Demo &st);
    
    // copy constructor
    String_Demo(const String_Demo &);
    String_Demo & operator=(const String_Demo &other);
    
    int length() const { return len; }
    friend bool operator<(const String_Demo &st1, const String_Demo &st2);
    friend bool operator>(const String_Demo &st1, const String_Demo &st2);
    friend bool operator==(const String_Demo &st1, const String_Demo &st2);
    char & operator[] (const int i);
    const char & operator[](const int i) const;
    static int HowMany() { return num_strings; };
    
    friend std::ostream & operator<<(std::ostream &os, String_Demo &st);
    friend std::istream & operator>>(std::istream &is, String_Demo &st);
};

#endif
