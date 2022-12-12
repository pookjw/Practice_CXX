//
//  code.cpp
//  Practice_CXX
//
//  Created by Jinwoo Kim on 12/10/22.
//

#include "code.hpp"
#include <iostream>

void namespace_1(void) {
    std::cout << "1" << std::endl;
}

void namespace_2(void) {
    using namespace std;
    cout << "2" << endl;
}

void namespace_3(void) {
    using std::cout;
    using std::endl;
    
    cout << "3" << endl;
}

void cin_1(void) {
    using namespace std;
    
    int carrots;
    
    cout << "How many carrots do you have?" << endl;
    cin >> carrots;
    cout << "Here are two more. ";
    carrots += 2;
    cout << "Now you have " << carrots << " carrots." << endl;
}

void simon(int); // function prototype for simin()
void function_prototype(void) {
    using namespace std;
    simon(3);
    int count;
    cin >> count;
    simon(count);
    cout << "Done!" << endl;
}
void simon(int n) {
    using namespace std;
    cout << "Simon says touch your toes " << n << " times." << endl;
}

void size_integers(void) {
    short wide_of_short;
    int wide_of_int;
    long wide_of_long;
    long long wide_of_long_long;
    
    std::cout << sizeof(wide_of_short) << std::endl; // 2
    std::cout << sizeof(wide_of_int) << std::endl; // 4
    std::cout << sizeof(wide_of_long) << std::endl; // 8
    std::cout << sizeof(wide_of_long_long) << std::endl; // 8
}

void max_integers(void) {
    using namespace std;
    cout << SHRT_MAX << endl; // 32767
    cout << INT_MAX << endl; // 2147483647
    cout << LONG_MAX << endl; // 9223372036854775807
    cout << LONG_LONG_MAX << endl; // 9223372036854775807
    cout << CHAR_MAX << endl; // 127
}

void max_unsigned_integers(void) {
    using namespace std;
    cout << UCHAR_MAX << endl; // 255
    cout << ULONG_MAX << endl; // 18446744073709551615
    cout << ULLONG_MAX << endl; // 18446744073709551615
}

void initialization_1(void) {
    int owls = 101;
    int wrens(432); // C++ syntax;
    std::cout << owls + wrens << std::endl;
}

void initialization_2(void) {
    int humburgers = {24}; // array initialization
    int apples[4] = {1, 2, 3, 4};
    int bananas[3] = {1}; // {1, 0, 0}
    int enums{8};
    int rocs = {}; // {0}
    int psychics{};
}

void cin_char_1(void) {
    using namespace std;
    char ch;
    cout << "Enter a character: " << endl;
    cin >> ch;
    cout << "Hola! ";
    cout << "Thank you for the " << ch << " character." << endl;
}

void cin_char_2(void) {
    using namespace std;
    char ch;
    cout << "Enter a character: " << endl;
    cin >> ch;
    cout.put(ch) << endl;;
}

void new_line(void) {
    using namespace std;
    cout << endl;
    cout << '\n';
    cout << "\n";
}

void size_chars(void) {
    using namespace std;
    char     ch1{ 'a' };  // or { u8'a' }
    wchar_t  ch2{ L'a' };
    char16_t ch3{ u'a' };
    char32_t ch4{ U'a' };
    
    char character;
    wchar_t wide_character;
    char16_t wider_character;
    char32_t more_wider_character;
    cout << sizeof(character) << endl;
    cout << sizeof(wide_character) << endl;
    cout << sizeof(wider_character) << endl;
    cout << sizeof(more_wider_character) << endl;
}

void big_integers(void) {
    using namespace std;
    unsigned long long a = 2.52e+8;
    float b = 8.33E-4;
    unsigned long long c = 7E5;
    long long d = -18.32e13;
    unsigned long long e = 1.69e12;
    unsigned long long f = 5.98E10;
    float g = 9.11e-31;
    
    cout << a << endl; // 252000000
    cout << b << endl; // 0.000833
    cout << c << endl; // 700000
    cout << d << endl; // -183200000000000
    cout << e << endl; // 1690000000000
    cout << f << endl; // 59800000000
    cout << g << endl; // 9.11e-31
}

void change_ios_base(void) {
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    float tree = 3; // int converted to float
    int guess(3.8932); // double converted to int
    int debt = 7.2E12; // too big
    
    // without `setf()` it will print 3, but if you set floatfield will print 3.000000.
    cout << "tree = " << tree << endl;
    
    cout << "guress = " << guess << endl;
    cout << "debt = " << debt << endl;
}

void initialization_3(void) {
    int const code = 66;
    int x = 6;
    
//    char c1 {32325}; // overflow
    char c2 {66};
    char c3 { code };
//    char c4 { x }; // error because x int not a constant.
    char c5 = x;
}

void type_casting_1(void) {
    int a = 1;
    int b = (int)a;
    int c = int(a);
}

// Check that type casting is legal AT COMPILE TIME!!!
void static_cast_1(void) {
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    
    int const a = 1;
    float b = static_cast<float>(a);
    b += 0.5f;
    
    // illegal
//    char *c = static_cast<char *>(a); // ERROR: Cannot cast from type 'int' to pointer type 'char *'
    
    cout << b << endl;
}

// Add or Remove const declaration
void const_cast_1(void) {
    using namespace std;
    
    // int const와 const int는 같다.
    // 근데 const int는 헷갈림...
    
    // 값이 불변
    int const a = 1;
    int *b = const_cast<int *>(&a);
    cout << *b << endl; // 1
    
    // Pointer가 불변, 값은 가변
    int const * c = const_cast<int const *>(&a);
//    c = &a;
//    *c = 4;
    cout << *c << endl; // 1
    
    // Pointer, 값 둘다 불변
    int const * const d = const_cast<int const * const>(&a);
    cout << *d << endl; // 1
}

// Casts by force
void reinterpret_cast_1(void) {
    int const a = 3;
    char *b = reinterpret_cast<char *>(a);
    std::cout << b << std::endl; // CRASH!!!
}

// Swift의 as? 같은거
// 아직 Class를 안 배웠기에 나중에...
// https://ence2.github.io/2020/11/c-캐스팅-총정리스마트포인터-캐스팅-포함/
// pointer casting도 보면 좋음
void dynamic_cast_1(void) {
    // TODO
}

void auto_1(void) {
    auto a = 'a';
    std::cout << typeid(a).name() << std::endl; // c
}

void array_1(void) {
    short const months[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::cout << months[5] << std::endl; // 6
}

void array_2(void) {
    int cards[4] = {}; // {0, 0, 0, 0}
    cards[2] = 4; // legal
//    cards[10] = 5; // Warning: Array index 10 is past the end of the array (which contains 4 elements)
//    cards = {0, 0, 0, 0}; // illegal
}

void array_3(void) {
    int cards[] = {3, 6, 8, 10};
//    cards[4] = 11; // Warning: Array index 4 is past the end of the array (which contains 4 elements)
}

void array_4(void) {
//    int cards[]; // ERROR: Definition of variable with array type needs an explicit size or an initializer
}

void size_of_array_1(void) {
    int cards[4];
    std::cout << sizeof(cards) / sizeof(int) << std::endl; // 4
    std::cout << sizeof cards / sizeof (int) << std::endl; // 4
}

void array_5(void) {
    int cards[4] {3, 5, 7, 9}; // ok with C++11
}

void array_6(void) {
    int a = 3;
    int const b = 3;
    
    a = 9;
    
    int c[a];
    int d[b];
    
    std::cout << sizeof c / sizeof (int) << std::endl; // 9
}

void string_1(void) {
    using namespace std;
    
    char a[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'i'};
    cout << a << endl; // abcdefgi\327 -> \327 is random
    
    char b[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', '\0'}; // '\0'으로 끝나야함!!!
    cout << b << endl; // abcdefg
    
    char c[6] = "abcde"; // 맨 뒤에 '\0'이 달리므로, 사이즈가 6이어도 5글자만 넣어야함!!!
    cout << c << endl; // abcde
    
    char d[6] = "abc"; // {'a', 'b', 'c', '\0', '\0', '\0'}
    cout << d << endl; // abc
    
    char e[6]; // {'\0', '\0', '\0', '\0', '\0', '\0'}
    cout << e << endl; // Nothing
    
    char f[] = "abc";
    cout << sizeof f / sizeof (char) << endl; // 4 - 마지막 `\0` 때문!!!
}

void strlen_1(void) {
    char a[6] = "abcde";
    char b[6];
    
    std::cout << strlen(a) << std::endl; // 5
    std::cout << strlen(b) << std::endl; // 0
}

void cin_string_1(void) {
    using namespace std;
    int const ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    
    cout << "Enter your name:\n";
    cin >> name;
    cout << "Enter your favorite dessert:\n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
}

void cin_getline_1(void) {
    using namespace std;
    int const ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    
    cout << "Enter your name:\n";
    cin.getline(name, ArSize);
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert, ArSize);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
}

void cin_get_1(void) {
    using namespace std;
    cout << "return 4 times to return." << endl;
    cin.get();
    cin.get();
    cin.get();
    cin.get();
}

void cin_getline_returns_cin_1(void) {
    using namespace std;
    int const ArSize = 20;
    char name[ArSize];
    
    cout << "Enter name and return twice to return." << endl;
    cin.getline(name, ArSize).get();
    cout << name << endl;
}

void cin_clear_1(void) {
    using namespace std;
    cout << "return to clear." << endl;
    cin.get();
    cin.clear();
}
