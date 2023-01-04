//
//  class_1.hpp
//  Practice_CXX
//
//  Created by Jinwoo Kim on 1/4/23.
//

#ifndef class_1_hpp
#define class_1_hpp

#include <string>

class Class_1_Demo {
private: // 이 keyword가 없을 경우 자동으로 private 처리
    std::string id;
public:
    std::string name;
    void refresh_id();
    void refresh_name();
    
    // inline by default
    std::string concat_id_and_name() {
        return id + name;
    }
};

#endif /* class_1_hpp */
