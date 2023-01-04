//
//  class_2.cpp
//  Practice_CXX
//
//  Created by Jinwoo Kim on 1/4/23.
//

#include "class_2.hpp"

void Class_2_Demo::show() {
    
}

void Class_2_Demo::non_mutating_method() const {
    // No viable overloaded '='
//    this->name = "T";
}

const Class_2_Demo & Class_2_Demo::self() const {
    return *this; // reference value는 값을 할당해야 하므로 *
}

Class_2_Demo::Class_2_Demo(const std::string id, const std::string name) {
    this->id = id;
    this->name = name;
}

Class_2_Demo::~Class_2_Demo() {
    std::cout << "Destructor!" << std::endl;
}
