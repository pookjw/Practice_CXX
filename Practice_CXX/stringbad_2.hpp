//
//  stringbad.hpp
//  Practice_CXX
//
//  Created by Jinwoo Kim on 1/7/23.
//

#ifndef stringbad_2
#define stringbad_2

#include <iostream>

class StringBad_2 {
private:
    /// pointer to string
    char *str;
    
    /// length of string
    int len;
    
    /// number of objects
    static int num_strings;
public:
    StringBad_2(const char *s);
    StringBad_2();
    ~StringBad_2();
    
    friend std::ostream & operator<<(std::ostream &os, const StringBad_2 &st);
    
    // copy constructor
    StringBad_2(const StringBad_2 &);
    StringBad_2 & operator=(const StringBad_2 &other);
};

#endif
