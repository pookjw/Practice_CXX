//
//  main.cpp
//  Ranges
//
//  Created by Jinwoo Kim on 5/30/23.
//

#include <iostream>
#include <vector>
#include <ranges>

int main(int argc, const char * argv[]) {
    // https://en.cppreference.com/w/cpp/ranges
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    auto results = numbers
    | std::views::filter([](int n) { return static_cast<bool>(n % 2); });
    
    for (auto n : results) std::printf("%d\n", n);
    
    return EXIT_SUCCESS;
}
