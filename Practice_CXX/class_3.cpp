//
//  class_3.cpp
//  Practice_CXX
//
//  Created by Jinwoo Kim on 1/6/23.
//

#include "class_3.hpp"

Class_3_Demo::Class_3_Demo() {
    // class는 포인터에 대한 값만 가지므로, 포인터가 지칭하는 메모리는 직접 관리해야함
    this->str = new char[6];
}

Class_3_Demo::~Class_3_Demo() {
    delete [] this->str;
}
