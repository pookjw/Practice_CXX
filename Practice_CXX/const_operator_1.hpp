//
//  const_operator_1.hpp
//  Practice_CXX
//
//  Created by Jinwoo Kim on 1/8/23.
//

#ifndef const_operator_1_hpp
#define const_operator_1_hpp

#import <iostream>

class Const_Operator_1 {
public:
    std::string string;
//    const Const_Operator_1 & operator+(Const_Operator_1 &other) {
//        this->string = this->string + other.string;
//        return *this;
//    }
    
    Const_Operator_1 & operator+(Const_Operator_1 &other) {
        this->string = this->string + other.string;
        return *this;
    }
    
    friend std::ostream & operator<<(std::ostream &os, Const_Operator_1 &other) {
        os << other.string;
        return os;
    }
};

#endif /* const_operator_1_hpp */
