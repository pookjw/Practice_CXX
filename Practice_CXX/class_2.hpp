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
public:
    std::string name;
    void show();
    
    mutable std::string group;
    void non_mutating_method() const;
    const Class_2_Demo & self() const;
    
    // Constructors
    Class_2_Demo(const std::string id, const std::string name = "Test");
    
    Class_2_Demo() {
        // Class_2_Demo demo; 이렇게만 쳐도 이 constructor가 불림
        std::cout << "inline?" << std::endl;
    }
    
    // Destructors
    ~Class_2_Demo();
};

#endif /* class_2_hpp */
