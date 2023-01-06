//
//  class_2.hpp
//  Practice_CXX
//
//  Created by Jinwoo Kim on 1/4/23.
//

#ifndef class_2_hpp
#define class_2_hpp

#include <iostream>
#include <string>

class Class_2_Demo {
    std::string id; // private implicity
    
    // Declaring Constants
    const int Months = 12;
    enum { Months2 = 12 };
public:
    std::string name;
    void show();
    
    mutable std::string group;
    void non_mutating_method() const;
    const Class_2_Demo & self() const;
    
    // Constructors
    Class_2_Demo(const std::string id, const std::string name = "Test");
    Class_2_Demo(const double m);
    
    Class_2_Demo() {
        // Class_2_Demo demo; 이렇게만 쳐도 이 constructor가 불림
        std::cout << "inline?" << std::endl;
    }
    
    // Destructors
    ~Class_2_Demo();
    
    // Operators
    Class_2_Demo operator+(const Class_2_Demo & other) const;
    
    friend Class_2_Demo operator+(double m, const Class_2_Demo &other);
    friend int operator+(const Class_2_Demo &other, double m);
    // inline
    friend int operator*(const Class_2_Demo &other, int m) {
        return 3;
    }
    
    void operator<<(std::ostream &os);
    
    // Type Casts
    operator int() const;
    operator double() const;
    // 암시적 변환을 막아 줌
    explicit operator std::string() const;
};

#endif /* class_2_hpp */
