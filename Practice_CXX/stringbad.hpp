//
//  stringbad.hpp
//  Practice_CXX
//
//  Created by Jinwoo Kim on 1/7/23.
//

#ifndef stringbad
#define stringbad

#include <iostream>

class StringBad {
private:
    /// pointer to string
    char *str;
    
    /// length of string
    int len;
    
    /// number of objects
    static int num_strings;
public:
    StringBad(const char *s);
    StringBad();
    ~StringBad();
    
    friend std::ostream & operator<<(std::ostream &os, const StringBad &st);
};

#endif
