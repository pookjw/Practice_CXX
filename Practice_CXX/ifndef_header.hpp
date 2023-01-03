//
//  ifndef_header.hpp
//  Practice_CXX
//
//  Created by Jinwoo Kim on 1/3/23.
//

// ifndef로 중복 정의를 막음
/*
 1. 하나의 파일에 중복된 header 파일을 정의하거나
 2. first.hpp를 만들고, second.hpp를 만들어서 이 안에 #include <first.hpp>를 만들고, third.cpp를 만들어서 first.hpp와 second.hpp를 모두 include할 경우 에러를 방지
 */
#ifndef ifndef_header_h
#define ifndef_header_h

static void ifndef_header_function() {
    
}

#endif /* ifndef_header_h */
