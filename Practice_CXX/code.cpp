//
//  code.cpp
//  Practice_CXX
//
//  Created by Jinwoo Kim on 12/10/22.
//

#include "code.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <array>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "static_value.hpp"
#include "class_1.hpp"
#include "class_2.hpp"
#include "stringbad.hpp"
#include "stringbad_2.hpp"
#include "const_operator_1.hpp"
#include "string_demo.hpp"

void namespace_1(void) {
    std::cout << "1" << std::endl;
}

void namespace_2(void) {
    using namespace std;
    cout << "2" << endl;
    
    using namespace std; {
        cout << "3" << endl;
    }
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
    
//    cards = {0, 0, 0, 7}; // Array Assignment is not available on C.
    
    int a[4] = {0, 0, 0, 7};
    
//    cards = a; // Array Assignment is not available on C.
    
    memcpy(&cards, &a, sizeof(a)); //
    
    for (int i=0; i<4; i++) {
        std::cout << a[i] << std::endl; // {0, 0, 0, 7}
    }
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

void miscellaneous_1(void) {
    using namespace std;
    cout << "What year was your house build?\n";
    int year;
    cin >> year;
    cout << "What is its street address?\n";
    char address[80];
    
    // You never get the opportunity to enter the address.
    // The fix is to read and discard the newline before reading the address.
    cin.getline(address, 80);
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";
}

void miscellaneous_2(void) {
    using namespace std;
    cout << "What year was your house build?\n";
    int year;
    cin >> year;
    
    cin.get(); // Enter를 대신 먹어줌
    
    cout << "What is its street address?\n";
    char address[80];
    
    cin.getline(address, 80);
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";
}

void string_2(void) {
    char first_date[] = {"Le Chapon Dodu"};
    char second_date[] = {"The Elegant Plate"};
    std::string third_date = {"The Bread Bowl"};
    std::string fourth_date {"Hank's Fine Eats"};
}

void string_3(void) {
    char charr1[20];
    char charr2[20] = "jaguar";
    std::string str1;
    std::string str2 = "panther";
    
//    charr1 = charr2; // Array Assignment is not available on C.
    str1 = str2; // valid: Object Assignment
}

void string_4(void) {
    // Appending Strings
    using namespace std;
    
    string a = "A";
    string b = "B";
    string c = a + b;
    c += a;
    
    cout << c << endl; // ABA
    
    //
    
    char charr1[5] = "Test";
    char charr2[5] = "Test";
    char charr3[9];
    strcpy(charr3, charr1);
    strcat(charr3, charr2);
    
    cout << charr3 << endl; // TestTest
}

void string_5(void) {
    // length of strings
    char charr1[20] = "Test";
    std::string string1 = "Test";
    
    std::cout << sizeof(charr1) << std::endl; // 20
    std::cout << strlen(charr1) << std::endl; // 4
    std::cout << string1.size() << std::endl; // 4
}

void string_6(void) {
    wchar_t title[] = L"Chief Astrogator";
    char16_t name[] = u"Felonia Ripova";
    char32_t car[] = U"Humber Super Snipe";
}

void string_7(void) {
    // Raw String
    // R와 () 괄호가 무조건 있어야 함
    
    std::cout << R"(Jim "King" uses "\n" instead of endl.)" << '\n';
    
    // is equivalent to...
    
    std::cout << "Jim \"King\" uses \"\\n\" instead of endl." << '\n';
    
    // ... 위 문법은 "( /* */ )" 처럼 "와 (로 시작해야 하므로,
    // "(Who wouldn't)"
    // 같은 문장을 표현할 수 없으므로, "와 ( 사이에 +*을 넣으면 더 엄밀하게 정의할 수 있다.
    
    std::cout << R"+*("(Who wouldn't?)", she whispered.)+*" << std::endl;
}

void structure_1(void) {
    struct inflactable {
        char name[20];
        float volume;
        double price;
    };
    
    struct inflactable goose; // keyword struct required in C
    
    // keyword struct not required in C++
    inflactable hat;
    inflactable woopie_cushion;
    inflactable mainframe;
}

void structure_2(void) {
    struct inflactable {
        char name[20];
        std::string name2;
        float volume;
        double price;
    };
    
    inflactable guest = {
        "Glorious Gloria",
        "",
        1.88,
        29.99
    };
    
    inflactable pal = {
        "Andacious Arthur",
        "",
        3.12,
        32.99
    };
    
    inflactable duck {"Daphne", "", 0.12, 9.98}; // can omit the = in C++11
    
    pal = duck; // assign
    
    using namespace std;
    
    cout << guest.name << endl; // Glorious Gloria
    cout << pal.volume << endl; // 0.12
}

void structure_3(void) {
    struct perks {
        int key_number;
        char car[12];
    } mr_smith, ms_jones; // define struct type and assign with zero values.
    
    struct perks_2 {
        int key_number;
        char car[12];
    } mr_glitz = {
        7,
        "Packard"
    }; // define struct type and assign values directly;
    
    struct perks a;
    struct perks_2 b;
    
    // also we can define struct with no tag
    struct {
        int x;
        int y;
    } position = { 0, 0 };
    
    struct {
        int x;
        int y;
    } const position_2 = { 0, 0 };
}

void structure_4(void) {
    struct inflactable {
        char name[20];
        float volume;
        double price;
    };
    
    // Array of struct
    inflactable guests[2] = {
        {"Bambi", 0.5, 21.99},
        {"Godzilla", 2000, 565.99}
    };
    
    inflactable guests_2[4] = {};
    
    inflactable guests_3[5] = {
        {"A", 0.1, 0.4}
    };
    
    struct {
        int x;
        int y;
    } const position[2] = { {0, 0}, {3, 9} };
}

void structure_5(void) {
    // declare bit fields
    struct torgle_register {
        unsigned int SN : 4;
        unsigned int a : 100; // Warning: Width of bit-field 'a' (100 bits) exceeds the width of its type; value will be truncated to 32 bits
        // 경고가 뜨지만 상관 없음 - 데이터 크기만 불필요하게 커지는 것 뿐
        
        unsigned int : 4; // 4 bits unused.
        bool goodIn : 1;
    } torgle = { 4, 5, true };
    
    std::cout << torgle.goodIn << std::endl; // 1
}

void union_1(void) {
    union one4all {
        int int_val;
        long long_val;
        double double_val;
    };
    
    using namespace std;
    
    one4all pail;
    pail.int_val = 15;
    cout << pail.int_val << endl;
    
    pail.double_val = 1.38;
    cout << pail.double_val << endl; // 1.38
    cout << pail.int_val << endl; // -515396076
    
    //
    
    cout << sizeof(static_cast<int>(1)) << endl; // 4
    cout << sizeof(static_cast<long>(1)) << endl; // 8
    cout << sizeof(static_cast<double>(1.0)) << endl; // 8
    
    // 4, 8, 8 -> 8이 최대이므로
    cout << sizeof(pail) << endl; // 8
}

void union_2(void) {
    struct widget {
        char brand[20];
        
        enum data_type {
            num = 0,
            charr = 1
        } type;
        
        union id {
            long id_num;
            char id_char[20];
        } id_val;
    };
    
    widget prize;
    
    char const id_char[5] = "Test";
    
    strcpy(prize.id_val.id_char, id_char);
    // 같음 (길이 정의)
//    strncpy(prize.id_val.id_char, id_char, sizeof(prize.id_val.id_char));
    // 또는 (메모리째로 복사)
//    memcpy(&(prize.id_val.id_char), &id_char, sizeof(prize.id_val.id_char));
    
    prize.type = widget::charr;
    
    switch (prize.type) {
        case widget::num:
            std::cout << prize.id_val.id_num << std::endl; // Never called.
            break;
        case widget::charr:
            std::cout << prize.id_val.id_char << std::endl; // Test
            break;
        default:
            break;
    }
}

void enumeration_1(void) {
    enum spectrum { red = 5, orange, yellow, green, blue, violet, indigo, unltraviolet };
    
    std::cout << orange << std::endl; // 6
    
    spectrum band;
    
    band = blue;
//    band = 3; // Assigning to 'spectrum' from incompatible type 'int'
    band = static_cast<spectrum>(30);
    
    std::cout << band << std::endl; // 30
    
    //
    
    // Type Cast
    band = (spectrum)8;
    band = spectrum(7);
    band = spectrum(3);
    band = spectrum(100);
    band = (spectrum)200;
    
//    ++band; // Cannot increment expression of enum type 'spectrum'
    band = static_cast<spectrum>(band + 1);
    
    
//    band = orange + red; // Assigning to 'spectrum' from incompatible type 'int'
    band = static_cast<spectrum>(orange + red);
    
    //
    
    int color = blue;
    color = 3;
    color = 3 + red;
}

void enumeration_2(void) {
    enum { a = 0, b, c, d, e = 1 };
    std::cout << a << std::endl; // 0
    std::cout << b << std::endl; // 1
    std::cout << c << std::endl; // 2
    std::cout << d << std::endl; // 3
    std::cout << e << std::endl; // 1
}

void malloc_1(void) {
    char *charr;
    void *p = malloc(5);
    charr = static_cast<char *>(p);
    
    char charr_2[5] = "ABCD";
    
    strcpy(charr, charr_2);
//    memcpy(charr, &charr_2, sizeof(&p));
    
    std::cout << charr << std::endl; // ABCD
    
    free(charr);
}

void new_delete_1(void) {
    using namespace std;
    int nights = 1001;
    int * pt = new int;
    *pt = nights;
    
    delete pt;
//    delete pt; // unsafe
    
    int * pt_2 = nullptr;
    delete pt_2; // safe
}

void new_delete_2() {
    int * psome = new int [10];
    delete [] psome;
}

void pointer_1() {
    using namespace std;
    
    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};
    
    // Here are two ways to get the address of an array
    double *pw = wages;
    short *ps = &stacks[0];
    
    // with array element
    cout << *pw << endl; // 10000
    // int는 크기가 4 이므로, 포인터에 1을 더하면 자동으로 4 * 1이 더해짐
    ++pw; // size of double type is 8, incrementing 1 is equal to 8.
    cout << *pw << endl; // 20000
    pw += 1;
    cout << *pw << endl; // 30000
    
    //
    
    cout << *(stacks + 1) << endl; // 2
    *(stacks + 2) = 6;
    cout << *(stacks + 2) << endl; // 6
    stacks[1] = 7;
    cout << *(stacks + 1) << endl; // 7
    cout << stacks[1] << endl; // 7
}

void pointer_2() {
    int tacos[10] = {5, 2, 8, 4, 1, 2, 2, 4, 6, 8};
    int *pt = tacos;
    ++pt;
    int *pe = &tacos[9];
    --pe;
    
    // 28이지만, int는 크기가 4이므로 28 / 4 = 7
    int diff = pe - pt;
    std::cout << diff << std::endl; // 7
}

void pointer_3() {
    struct inflactable {
        char name[20];
        float volume;
        double price;
    } value = {};
    
    struct inflactable *pt = &value;
    
    strcpy(pt->name, "Test");
    
    std::cout << value.name << std::endl; // Test
}

void vector_1() {
    std::vector<int> vi;
    std::vector<double> vd(10);
}

void array_7() {
    // array uses the stack, and requires fixed size.
    std::array<int, 5> ai;
    std::array<double, 4> ad = {1.2, 2.1, 3.43, 4.3};
}

void vector_vs_array_1() {
    using namespace std;
    
    // C, original C++
    double a1[4] = {1.2, 2.4, 3.6, 4.8};
    
    // C+98 STL
    // error - no simple way to initialize in C98
//    vector<double> a2(4) = {1.2, 3.4, 3.4, 3.5};
    vector<double> a2(4);
    a2[0] = 3.0;
    a2[1] = 1.0 / 5.0;
    a2[2] = 0.5;
    a2[3] = 0.1;
    
    // C+11 - array
    array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
    array<double, 4> a4;
    a4 = a3; // valid!
    
    //
    
    cout << a1[2] << endl; // 3.6
    cout << a2[2] << endl; // 0.5
    cout << a3[2] << endl; // 1.62
    cout << a4[2] << endl; // 1.62
    
    cout << a1[-2] << endl; // 5.21502e-310
    cout << a2[-2] << endl; // 3.46668e-32
    cout << a3[-2] << endl; // 1.62
    cout << a4[-2] << endl; // 3.04933e-314
}

void for_loop_1() {
    using namespace std;
    int i;
    
    // for (initialization; test-expression; update-expression)
    for (i = 0; i < 5; i++)
        cout << "C++ knows loops \n";
    cout << "C++ knows when to stop.\n";
}

void for_loop_2() {
    using namespace std;
    cout << "Enter the starting countdown value: ";
    int limit;
    cin >> limit;
    int i;
    for (i = limit; i; i--) // quits when i is 0
        cout << "i = " << i << endl;
    cout << "Done now that i = " << i << endl;
}

void block_1() {
    using namespace std;
    int x = 20;
    {
        cout << x << endl; // 20
        int x = 100;
        cout << x << endl; // 100
    }
    cout << x << endl; // 20
}

void for_loop_5() {
    using namespace std;
    cout << "Enter a word: ";
    string word;
    cin >> word;
    
    // physically modify string object
    char temp;
    unsigned long i, j;
    for (j = 0, i = word.size() - 1; j < i; --i, ++j) {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
    
    // Test -> tesT -> tseT
    cout << word << "\nDone\n";
}

void for_loop_6() {
    using namespace std;
    int quizscores[10] = { 20, 20, 20, 20, 20, 19, 20, 18, 20, 20 };
    int i;
    
    // 6번째가 19이므로, 5번째까지만 출력됨
    for (i = 0; quizscores[i] == 20; i++)
        cout << "quiz " << i << " is a 20\n";
}

void compare_string_1() {
    char word[5] = "?ate";
    
    for (char ch = 'a'; strcmp(word, "mate"); ch++) {
        std::cout << word << std::endl;
        word[0] = ch;
    }
    
    std::cout << word << std::endl;
    
    /*
     ?ate
     aate
     bate
     cate
     date
     eate
     fate
     gate
     hate
     iate
     jate
     kate
     late
     mate
     */
}

void compare_string_2() {
    using namespace std;
    string word = "?ate";
    
    // char[]와 다르게, cpp string은 operator로 바로 비교 가능
    // 하지만 char (문자열 하나)는 ascii 값 비교이므로 단순 operator로 비교 가능
    for (char ch = 'a'; word != "mate"; ch++) {
        cout << word << endl;
        word[0] = ch;
    }
    
    cout << word << endl;
    
    /*
     ?ate
     aate
     bate
     cate
     date
     eate
     fate
     gate
     hate
     iate
     jate
     kate
     late
     mate*/
}

void while_loop_1() {
    int const ArSize = 20;
    using namespace std;
    
    char name[ArSize];
    
    cout << "Ypur first name, please: ";
    cin >> name;
    cout << "Here is your name, verticalized and ASCIIized:\n";
    
    int i = 0;
    while (name[i] != '\0') {
        // int로 type 변환을 하면 ASCII로 변환 가능!
        cout << name[i] << ": " << int(name[i]) << endl;
        i++;
    }
    
    /*
     Ypur first name, please: Test
     Here is your name, verticalized and ASCIIized:
     T: 84
     e: 101
     s: 115
     t: 116
     */
}

void clock_1() {
    using namespace std;
    cout << "Enter the delay time, in seconds: ";
    float secs;
    cin >> secs;
    
    clock_t delay = secs * CLOCKS_PER_SEC;
    
    cout << "starting\a\n";
    
    clock_t start = clock();
    while (clock() - start < delay) {
        // 루프가 계속 돌음
    }
    cout << "done \a\n";
}

void do_loop_1() {
    using namespace std;
    int n;
    
    cout << "Enter numbers in the range 1-10 to find ";
    cout << "my favorite number\n";
    do {
        cin >> n;
    } while (n != 7);
    
    cout << "Yes, 7 is my favorite.\n";
}

void cpp_loop_1() {
    double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49};
    
    // C++ Style
    for (const double x : prices)
        std::cout << x << std::endl;
    
    for (double x : prices)
        x = 0.80; // No Effect
    
    // C Style
    for (int i = 0; i < sizeof(prices) / sizeof(double); i++) {
        std::cout << prices[i] << std::endl;
    }
    
    // Modify value within loop
    for (double &x : prices)
        x = x * 0.80;
    
    for (const double x : prices)
        std::cout << x << std::endl;
}

void cpp_loop_2() {
    for (int x : {3, 5, 2, 8, 6})
        std::cout << x << " ";
    
    // Binding reference of type 'int' to value of type 'const int' drops 'const' qualifier
//    for (int &x : {3, 5, 2, 8, 6})
//        x = 0.8;
    
    std::cout << std::endl;
}

void unadorned_cin_1() {
    using namespace std;
    char ch;

    int count = 0;
    cout << "Enter characters; enter # to quit:\n";
//    cin >> ch;
    cin.get(ch);

    while (ch != '#') {
        cout << ch;
        ++count;
//        cin >> ch;
        cin.get(ch);
    }

    cout << endl << count << " characters read\n";
}

void function_overloading_1() {
    using namespace std;
    char name[30];
    cout << "Enter your name:\n";
    
    cin.get(name, 30).get();
    // is equivalent to...
    cin.get(name, 30);
    cin.get();
}

void cin_fail_1() {
    using namespace std;
    
    char ch;
    int count = 0;
    cin.get(ch);
    
    // Ctrl + D
    while (cin.fail() == false) {
        cout << ch;
        ++count;
        cin.get(ch);
    }
    
    cout << endl << count << " characters read\n";
}

void cin_fail_2() {
    using namespace std;
    
    char ch;
    int count = 0;
    
    // Ctrl + D
    // returns nullptr when failed.
    while (cin.get(ch)) {
        cout << ch;
        ++count;
    }
    
    cout << endl << count << " characters read\n";
}

void cin_eof_1() {
    using namespace std;
    
    int count = 0;
    int ch;
    ch = cin.get();
    
    // EOF = -1
    // Ctrl + D
    // returns EOF when failed
    // get(char_type& __c) returns basic_istream&, but get() returns int_type.
    while (ch != EOF) {
        ch = cin.get();
        cin.get();
        ++count;
    }
    
    cout << endl << count << " characters read\n";
}

void cin_eof_2() {
    using namespace std;
    int ch;
    int count = 0;
    
    while ((ch = cin.get()) != EOF) {
        cout.put(char(ch));
        ++count;
    }
    
    cout << endl << count << " characters read\n";
}

void two_dimensional_array_1() {
    int maxtemps[4][5];
    
    for (int row = 0; row < 4; row++) {
        for (int column = 0; column < 5; column++) {
            maxtemps[row][column] = row + column;
        }
    }
    
    int columnSize = sizeof(maxtemps[0]) / sizeof(int);
    int rowSize = sizeof(maxtemps) / (columnSize * sizeof(int));
    
    std::cout << rowSize << " " << columnSize << std::endl;
    
    for (int row = 0; row < rowSize; row++) {
        for (int column = 0; column < columnSize; column++) {
            std::cout << maxtemps[row][column] << std::endl;
        }
    }
}

void two_dimensional_array_2() {
    using namespace std;
    
    const int Cities = 5;
    const int Years = 4;
    
    const char * cities[Cities] {
        "Gribble City",
        "Gribbletown",
        "New Gribble",
        "San Gribble",
        "Gribble Vista"
    };
    
    int maxtemps[4][5] {
        {96, 100, 87, 101, 105},
        {96, 98, 91, 107, 104},
        {97, 101, 93, 108, 107},
        {98, 103, 95, 109, 108}
    };
    
    cout << "Maximum temperatures for 2008 - 2011\n\n";
    
    for (int city = 0; city < Cities; ++city) {
        cout << cities[city] << ":\t";
        
        for (int year = 0; year < Years; ++year) {
            cout << maxtemps[year][city] << "\t";
        }
        
        cout << endl;
    }
}

void if_else_1() {
    char grade = 'C';
    int total = 0;
    
    if (grade == 'A')
        total++;
    else if (grade == 'B')
        total++;
    else
        total++;
}

void cctype_functions_1() {
    using namespace std;
    
    // isalnum checks whether an input value is alphanumeric, that is, a letter or a digit.
    cout << isalnum(static_cast<int>('$')) << endl; // 0
    cout << isalnum(static_cast<int>('A')) << endl; // 1
    cout << isalnum(static_cast<int>('1')) << endl; // 1
    
    // isalpha checks whether an input value is alphabetic.
    cout << isalpha(static_cast<int>('a')) << endl; // 1
    cout << isalpha(static_cast<int>('1')) << endl; // 0
    
    // isblank checks whether an input value is a space or a horizontal tab.
    cout << isblank(static_cast<int>('\t')) << endl; // 1
    cout << isblank(static_cast<int>(' ')) << endl; // 1
    
    // iscntrl checks whether an input value is a control character.
    cout << iscntrl(static_cast<int>('\0')) << endl; // 1
    
    // isdigit
    cout << isdigit(static_cast<int>('1')) << endl; // 1
    
    // isgraph checks whether an input value is other than s space.
    cout << isgraph(static_cast<int>(' ')) << endl; // 0
    cout << isgraph(static_cast<int>('\n')) << endl; // 0
    cout << isgraph(static_cast<int>('\0')) << endl; // 0
    cout << isgraph(static_cast<int>('\t')) << endl; // 0
    cout << isgraph(static_cast<int>('a')) << endl; // 1
    
    // isspace = !isgraph
    cout << isspace(static_cast<int>(' ')) << endl; // 1
    cout << isspace(static_cast<int>('\n')) << endl; // 1
    cout << isspace(static_cast<int>('\0')) << endl; // 0 - `\0` represents always false
    cout << isspace(static_cast<int>('\t')) << endl; // 1
    cout << isspace(static_cast<int>('a')) << endl; // 0
    
    // isprint = isgraph + ' '
    cout << isprint(static_cast<int>(' ')) << endl; // 1
    cout << isprint(static_cast<int>('\n')) << endl; // 0
    cout << isprint(static_cast<int>('\0')) << endl; // 0
    cout << isprint(static_cast<int>('\t')) << endl; // 0
    cout << isprint(static_cast<int>('a')) << endl; // 1
    
    // islower checks whether an input value is a lowercase letter.
    cout << islower(static_cast<int>('a')) << endl; // 1
    cout << islower(static_cast<int>('A')) << endl; // 0
    cout << islower(static_cast<int>(' ')) << endl; // 0
    cout << islower(static_cast<int>('3')) << endl; // 0
    
    // isupper
    cout << isupper(static_cast<int>('a')) << endl; // 0
    cout << isupper(static_cast<int>('A')) << endl; // 1
    cout << isupper(static_cast<int>(' ')) << endl; // 0
    cout << isupper(static_cast<int>('3')) << endl; // 0
    
    // https://grammarist.com/punctuation-marks/
    cout << ispunct(static_cast<int>('#')) << endl; // 1
    cout << ispunct(static_cast<int>('\\')) << endl; // 1
    cout << ispunct(static_cast<int>('a')) << endl; // 0
    
    // isxdigit checks whether an input value is a hexadecimal digit character. (that is, 0-9, a-f, or A-f)
    cout << isxdigit(static_cast<int>('F')) << endl;; // 1
    cout << isxdigit(static_cast<int>('-')) << endl; // 0
    
    // tolower returns the lowercase version of that character.
    cout << static_cast<char>(tolower(static_cast<int>('A'))) << endl; // a
    
    // toupper
    cout << static_cast<char>(toupper(static_cast<int>('a'))) << endl; // A
}

void ofstream_1() {
    using namespace std;
    
    char automobile[50];
    int year;
    double a_price;
    double d_price;
    
    ofstream outFile; // create object for output
    outFile.open("/Users/pookjw/Desktop/charinfo.txt"); // associate with a file
    
    cout << "Enter the make and model of automobile: ";
    cin.getline(automobile, 50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> a_price;
    
    d_price = 0.913 * a_price;
    
    // display information on screen with cout
    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model: " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << d_price << endl;
    
    outFile << fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model: " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << d_price << endl;
    
    outFile.close();
}

void ifstream_1() {
    // input:
    /*
     18 19 18.5 13.4 14
     16 19.5 20 18 12 18.5
     17.5
     */
    
    // output:
    /*
     Enter name of data file: /Users/pookjw/Desktop/input.txt
     End of file reached.
     Item read: 11
     Sum: 186.9
     Average: 16.9909
     */
    
    using namespace std;
    
    const int SIZE = 60;
    char filename[SIZE];
    ifstream inFile;
    
    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);
    
    if (!inFile.is_open()) {
        cout << "Failed to open file" << endl;
        exit(EXIT_FAILURE); // or EXIT_SUCCESS
    }
    
    double value;
    double sum = 0.0;
    int count = 0;
    
    inFile >> value; // get first value
    while (inFile.good()) { // while input good and not at EOF. It returns bool value; if stream reached at EOF returns false.
        ++count;
        sum += value;
        inFile >> value;
    }
    
    if (inFile.eof())
        cout << "End of file reached.\n";
    else if (inFile.fail())
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reason.\n";
    
    if (count == 0)
        cout << "No data processed.\n";
    else {
        cout << "Item read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }
    
    inFile.close();
}

int function_array_parameter_1_demo(int arr[], int n);
void function_array_parameter_1() {
    using namespace std;
    
    const int ArSize = 8;
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    
    int sum = function_array_parameter_1_demo(cookies, ArSize);
    cout << "Total cookies eaten: " << sum << endl;
}
int function_array_parameter_1_demo(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    return total;
}

// protect value with `const` mark.
int function_array_parameter_2_demo(const int arr[], int n);
void function_array_parameter_2() {
    using namespace std;
    
    const int ArSize = 8;
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    
    int sum = function_array_parameter_1_demo(cookies, ArSize);
    cout << "Total cookies eaten: " << sum << endl;
}
int function_array_parameter_2_demo(const int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    return total;
}

//int function_array_paramter_3(const int (*ar2)[4], const int size);
// or
int function_array_paramter_3_demo(const int ar2[][4], const int size);
void function_array_paramter_3() {
    int data[3][4] {
        {1, 2, 3, 4},
        {9, 8, 7, 6},
        {2, 4, 6, 8}
    };
    
    std::cout << function_array_paramter_3_demo(data, 3) << std::endl;
}
int function_array_paramter_3_demo(const int ar2[][4], const int size) {
    int total = 0;
    
    for (int a = 0; a < size; a++) {
        for (int b = 0; b < 4; b++) {
//            total += ar2[a][b];
            // is equal to...
            total += *(*(ar2 + a) + b);
        }
    }
    
    return total;
}

void cmath_1() {
    using namespace std;
    
    cout << sqrt(4.0) << endl; // 2
    cout << atan(1.0) * 4 << endl;; // 3.14159
}

void string_8() {
    using namespace std;
    const int SIZE = 5;
    
    string list[SIZE];
    cout << "Enter your " << SIZE << " favorite astronomical sights:\n";
    
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << ": ";
        getline(cin, list[i]); // cin for std::string
    }
    
    cout << "Your list:\n";
    
    for (int i = 0; i < SIZE; i++)
        cout << i + 1 << ": " << list[i] << endl;
}

void array_8() {
    const int Seasons = 4;
    const std::array<std::string, Seasons> Snames {
        "Spring", "Summer", "Fall", "Winter"
    };
    
    //
    
    std::array<double, Seasons> expenses;
    for (int i = 0; i < Seasons; i++) {
        std::cout << "Enter " << Snames[i] << " expenses: ";
        std::cin >> expenses[i];
    }
    
    //
    
    double total = 0.0;
    for (int i = 0; i < Seasons; i++) {
        std::cout << Snames[i] << ": $" << expenses[i] << std::endl;
        total += expenses[i];
    }
    
    std::cout << "Total Expenses: $" << total << std::endl;
}

// void *function_pointer_auto_1_demo_1(); 이랑 다름!!!
void (*function_pointer_auto_1_demo_1)();
void function_pointer_auto_1_demo_2();
void function_pointer_auto_1() {
    function_pointer_auto_1_demo_1 = &function_pointer_auto_1_demo_2;
    auto auto_func = &function_pointer_auto_1_demo_2;
    
    // ERROR: *auto_func();
    (*auto_func)();
}
void function_pointer_auto_1_demo_2() {
    std::cout << "Foo" << std::endl;
}

void typedef_1() {
    typedef double real;
    real value = 3.0;
    std::cout << value << std::endl;
}

inline double inline_1_demo_1(double x) { return x * x; }
void inline_1() {
    using namespace std;
    double a, b;
    
    a = inline_1_demo_1(5.0);
    b = inline_1_demo_1(4.5 + 7.5);
}

void reference_variable_1() {
    using namespace std;
    int rats = 101;
    int &rodents = rats; // rodents is a reference
    
    cout << rodents << endl; // 101
    rats += 1;
    cout << rodents << endl; // 102
    rodents += 1;
    cout << rats << endl; // 103
    
    // or
    
    int *pt = &rats;
    rodents += 1;
    cout << *pt << endl; // 104
    
    int a = 3;
    rodents = a; // reference does not change.
    cout << rats << endl; // 3
}

void reference_variable_2_swap_1(int &a, int &b) {
    int temp;
    
    temp = a;
    a = b;
    b = temp;
}
void reference_variable_2_swap_2(int *a, int *b) {
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}
void reference_variable_2() {
    int a = 300;
    int b = 350;
    
    // same
    
    reference_variable_2_swap_1(a, b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    
    reference_variable_2_swap_2(&a, &b);
    std::cout << a << std::endl;
    std::cout << b << std::endl;
}

double reference_variable_3_demo(const double &ra) {
    // ERROR
//    ra = 3;
    return ra * ra * ra;
}
void reference_variable_3() {
    double a = 3.0;
    std::cout << reference_variable_3_demo(a) << std::endl; // 27
}

int & reference_variable_4_demo_1(int &a) {
    return a;
}
int & reference_variable_4_demo_2(int &a) {
    int *b = &a;
    return *b;
}
const int & reference_variable_4_demo_3(int &a) {
    return a;
}
void reference_variable_4() {
    int a = 10;
    int &b = reference_variable_4_demo_1(a);
    a += 10;
    std::cout << b << std::endl; // 20
    
    a = 10;
    int &c = reference_variable_4_demo_2(a);
    a += 10;
    std::cout << c << std::endl; // 20
    
    a = 10;
    int d = reference_variable_4_demo_1(a);
    a += 10;
    std::cout << d << std::endl; // 10
    
    a = 10;
    int e = reference_variable_4_demo_2(a);
    a += 10;
    std::cout << e << std::endl; // 10
    
    a = 10;
    const int &f = reference_variable_4_demo_3(a);
    a += 10;
    std::cout << f << std::endl; // 20
    
    a = 10;
    const int *g = &reference_variable_4_demo_3(a);
    a += 10;
    std::cout << *g << std::endl; // 20
    
    a = 10;
    int *h = const_cast<int *>(&reference_variable_4_demo_3(a));
    a += 10;
    std::cout << *h << std::endl; // 20
    
    a = 10;
    const int &i = a;
    a += 10;
    std::cout << i << std::endl; // 20
}

const std::string & reference_variable_5_demo_1(const std::string &s1) {
    return s1;
}
std::string reference_variable_5_demo_2(std::string s1) {
    return s1;
}
void reference_variable_5() {
    using namespace std;
    
    string a;
    
    a = "1";
    const string b = reference_variable_5_demo_1(a);
    a = "2";
    cout << b << endl; // 1
    
    a = "1";
    string c = reference_variable_5_demo_2(a);
    a = "2";
    cout << c << endl; // 1
    
    a = "1";
    const string d = reference_variable_5_demo_1(a);
    a.erase(0);
    a.insert(0, "2");
    cout << a << endl; // 2
    cout << d << endl; // 1
    
    a = "1";
    const string &e = reference_variable_5_demo_1(a);
    a = "2";
    cout << e << endl; // 2
}

void reference_variable_6_demo_1(std::ostream &os, double fo, const double fe[], int n) {
    std::ios_base::fmtflags initial = os.setf(std::ios_base::fixed); // save initial formatting size
    
    os.precision(0);
    os << "Focal length of objective: " << fo << " mm\n";
    os.setf(std::ios::showpoint);
    os.width(12); // 띄어쓰기 여백
    os << "f.l. eyepiece";
    os.width(15); // 띄어쓰기 여백
    os << "magnification" << std::endl;
    
    for (int i = 0; i < n; i++) {
        os.width(12); // 띄어쓰기 여백
        os << fe[i];
        os.width(15); // 띄어쓰기 여백
        os << int (fo/fe[i] + 0.5) << std::endl;
    }
    
    os.setf(initial); // restore
}
void reference_variable_6() {
    const int LIMIT = 5;
    
    std::ofstream fout;
    fout.open("/Users/pookjw/Desktop/ep-data.txt");
    
    if (!fout.is_open())
        exit(EXIT_FAILURE);
    
    double objective;
    std::cout << "Enter the focal length of your telescope objective in mm: ";
    std::cin >> objective;
    
    double eps[LIMIT];
    std::cout << "Enter the focal lengths, in mm, of " << LIMIT << " eyepieces: ";
    
    for (int i = 0; i < LIMIT; i++) {
        std::cout << "Eyepiece #" << i + 1 << ": ";
        std::cin >> eps[i];
    }
    
    reference_variable_6_demo_1(fout, objective, eps, LIMIT);
    reference_variable_6_demo_1(fout, objective, eps, LIMIT);
    
    std::cout << "Done\n";
    
    /*
     Focal length of objective: 3 mm
     f.l. eyepiece  magnification
               1.              3
               2.              2
               3.              1
               4.              1
               5.              1
     Focal length of objective: 3. mm
     f.l. eyepiece  magnification
               1.              3
               2.              2
               3.              1
               4.              1
               5.              1

     */
}

void function_default_value_1_demo_1(int n, int m = 1);
// ERROR: Missing default argument on parameter 'm'
//void function_default_value_1_demo_2(int n = 3, int m);
void function_default_value_1() {
    function_default_value_1_demo_1(3);
}
void function_default_value_1_demo_1(int n, int m) {
    std::cout << n << m << std::endl;
}

void function_overloading_2_demo_1(int i);
void function_overloading_2_demo_1(double d);
// ERROR: Redefinition of 'function_overloading_2_demo_1'
//void function_overloading_2_demo_1(const int i);
//void function_overloading_2_demo_1(double &d);
void function_overloading_2_demo_2(double &rs);
void function_overloading_2_demo_2(double *rs);
void function_overloading_2_demo_2(const double &rs);
void function_overloading_2() {
    function_overloading_2_demo_1(3); // int
    function_overloading_2_demo_1(3.0); // double
    
    double d;
    function_overloading_2_demo_2(d); // double &
    function_overloading_2_demo_2(&d); // double *
    function_overloading_2_demo_2(const_cast<const double &>(d)); // const double &
}
void function_overloading_2_demo_1(int i) {
    i = 3;
    std::cout << "int" << std::endl;
}
void function_overloading_2_demo_1(double d) {
    std::cout << "double" << std::endl;
}
//void function_overloading_2_demo_1(const int i) {
//    std::cout << "const int" << std::endl;
//}
//void function_overloading_2_demo_1(double &d) {
//    d = 1.0;
//    std::cout << "double &" << std::endl;
//}
void function_overloading_2_demo_2(double &rs) {
    std::cout << "double &" << std::endl;
}
void function_overloading_2_demo_2(double *rs) {
    std::cout << "double *" << std::endl;
}
void function_overloading_2_demo_2(const double &rs) {
    std::cout << "const double &" << std::endl;
}

template <typename TEMPLATE_1_DEMO_TEMPLATE>
void template_1_demo_1(TEMPLATE_1_DEMO_TEMPLATE &a, TEMPLATE_1_DEMO_TEMPLATE &b) {
    TEMPLATE_1_DEMO_TEMPLATE temp = a;
    a = b;
    b = temp;
}
void template_1() {
    int a = 3;
    int b = 4;
    template_1_demo_1(a, b);
    std::cout << a << b << std::endl; // 43
    
    std::string c = "A";
    std::string d = "B";
    template_1_demo_1(c, d);
    std::cout << c << d << std::endl; // BA
}

template <typename TEMPLATE_2_TEMP_TEMPLATE> // original template
void template_2_demo_1(TEMPLATE_2_TEMP_TEMPLATE &a, TEMPLATE_2_TEMP_TEMPLATE &b) {
    TEMPLATE_2_TEMP_TEMPLATE temp = a;
    a = b;
    b = temp;
}
template <typename TEMPLATE_2_TEMP_TEMPLATE> // new template
// & -> *
void template_2_demo_1(TEMPLATE_2_TEMP_TEMPLATE *a, TEMPLATE_2_TEMP_TEMPLATE *b) {
    TEMPLATE_2_TEMP_TEMPLATE temp = *a;
    *a = *b;
    *b = temp;
}
void template_2() {
    int a = 3;
    int b = 2;
    template_2_demo_1(a, b);
    std::cout << a << b << std::endl;
    
    template_2_demo_1(&a, &b);
    std::cout << a << b << std::endl;
}

template <typename T>
void template_3(T);
// ERROR: Unknown type name 'T'
//void template_3(T a) { }

template <typename T>
void template_4(T);
template <typename T>
void template_4(T a) {
    std::cout << a << std::endl;
}

template <typename T>
void template_5_demo_1(T);
// explicit
template <> void template_5_demo_1<int>(int a) {
    std::cout << "int" << std::endl;
}
template <> void template_5_demo_1<double>(double a) {
    std::cout << "double" << std::endl;
}
void template_5() {
    template_5_demo_1(3); // int
    template_5_demo_1(3.0); // double
}

template <class T>
T template_6_demo_1(T a, T b) {
    return a + b;
}
void template_6() {
    std::cout << template_6_demo_1((std::string)"A", static_cast<std::string>("B")) << std::endl; // AB
}

template <class T1, class T2>
T1 template_7_demo_1(T1 a, T2 b) {
    return a + b;
}
int template_7_demo_1(int a, int b) {
    return a + b;
}
void template_7() {
    using namespace std;
    
    cout << template_7_demo_1(static_cast<string>("A"), static_cast<string>("B")) << endl; // AB
    cout << template_7_demo_1(1, 2) << endl; // 3
    
    // explicit
    cout << template_7_demo_1<string, string>(static_cast<string>("A"), static_cast<string>("B")) << endl; // AB
    cout << template_7_demo_1<int>(1, 2) << endl; // 3
}

void decltype_1() {
    using namespace std;
    
    // https://stackoverflow.com/questions/14130774/difference-between-decltype-and-typeof
    // C++11
    // typeof와 비슷하지만 더 확장성이 있음
    
    int a = 3;
    int &b = a;
    
    typeof(b) c = b; // int
    decltype(b) d = b; // int &
    
    a = 4;
    
    cout << c << endl; // 3
    cout << d << endl; // 4
}

template <class T1, class T2>
// ERROR
//decltype(x + y) decltype_2_demo_1(T1 x, T2 y) {
auto decltype_2_demo_1(T1 x, T2 y) -> decltype(x + y) {
    // C++11
    // 만약에 decltype을 return type으로 하고 싶으면, auto랑 -> 기호를 쓰면 됨
    return x + y;
}
void decltype_2() {
    // AB
    std::cout << decltype_2_demo_1((std::string)"A", (std::string)"B") << std::endl;
}

void auto_stroage_type_1() {
    // 안 써도 자동으로 되지만, stack에 값을 저장해서 메모리를 관리하도록 명시
    // 'auto' storage class specifier is not permitted in C++11, and will not be supported in future releases
    auto int a = 1;
    
    // ERROR: Cannot combine with previous 'auto' declaration specifier
//    auto auto b = 1;
}

void register_type_1() {
    // CPU Register에 저장하는 것이기 때문에 메모리 주소가 존재하지 않음
    // 접근이 더 빨랐다고 함 근데 요즘은 컴파일러가 자동으로 해줌
    // ERROR: ISO C++17 does not allow 'register' storage class specifier
//    register int a = 1;
}

void extern_value_1() {
    // extern_value.cpp에 있고 hpp에 정의 안해도 값을 가져 올 수 있음
    extern int extern_value;
    std::cout << extern_value << std::endl;
}

void extern_value_2() {
    // extern_value.cpp
    extern const int extern_const_value;
    // ERROR
//    extern_const_value = 3;
}

void static_value_1() {
    // static_value.hpp
    std::cout << static_value << std::endl; // 3
    static int static_value = 4; // overrides external
    std::cout << static_value << std::endl; // 4
}

void mutable_value_1() {
    struct data {
        char name[30];
        mutable int accesses;
    };
    
    const data veep = {"Claybourne Clodde", 0};
    veep.accesses = 3; // const이어도 mutable이기 때문에 값을 변경할 수 있음
}

void language_linking_1_demo_1() {
    std::cout << "C++" << std::endl;
}
extern "C" {
void language_linking_1_demo_2() {
    std::cout << "C" << std::endl;
}
}
extern "C++" {
void language_linking_1_demo_3() {
    std::cout << "C++" << std::endl;
}
}
extern "C" void language_linking_1_demo_4() {
    std::cout << "C" << std::endl;
}
void language_linking_1() {
    language_linking_1_demo_4();
}

void new_operator_1() {
    int *pi = new int(6); // *pi set to 6
    double *pd = new double (99.99);
    
    delete pi;
    delete pd;
}

void delete_operator_1() {
    int *pi = new int;
    
    delete pi;
    // or
//    delete(pi);
}

char new_operator_2_buffer_1[500];
void new_operator_2() {
    int *p1 = new int[20]; // place int array in heap
    delete [] p1;
    
    // buffer 영역에 메모리 alloc
    int *p2 = new (new_operator_2_buffer_1) int[20];
    
    // Runtime Error: Thread 1: signal SIGABRT
    // delete는 heap에 있는 메모리만 지워줌
//    delete [] p2;
}

namespace namespace_4_demo_1 {
int a;
void foo() {
    
}
};
void namespace_4() {
    int a1 = namespace_4_demo_1::a;
    using namespace namespace_4_demo_1;
    int b1 = a;
}

namespace namespace_5_demo_1 {
int a;
};
void namespace_5() {
    using namespace_5_demo_1::a;
    int a1 = a;
    
    using std::cout;
    using std::endl;
    
    cout << a << endl;
}

namespace namespace_6_demo_1 {
struct Person {
    std::string fname;
    std::string lname;
};
std::string concat_names(Person person) {
    return person.fname + person.lname;
}
};
void namespace_6() {
    namespace_6_demo_1::Person person = {"A", "B"};
    std::cout << namespace_6_demo_1::concat_names(person) << std::endl;
}

namespace {
int unnamed_namespace_1_int; // static storage, internal linkage
};
void unnamed_namespace_1() {
    unnamed_namespace_1_int = 3;
}

void class_1() {
    Class_1_Demo demo;
    demo.refresh_id();
    demo.refresh_name();
    
    Class_1_Demo *p = &demo;
    p->refresh_name();
    
    std::cout << p->concat_id_and_name() << std::endl;
}

void class_2() {
    Class_2_Demo demo_1 = Class_2_Demo("Test", "Test");
    Class_2_Demo demo_2;
    Class_2_Demo demo_3 = Class_2_Demo("Test");
    
    // double만 있는 constructor가 불림
    Class_2_Demo demo_4 = 3.0;
    Class_2_Demo demo_5 = static_cast<Class_2_Demo>(5.0);
    Class_2_Demo demo_6 = (Class_2_Demo)4.0;
    
    demo_4.name = "Demo 4";
    demo_5.name = "Demo 5";
    demo_6.name = "Demo 6";
    
    std::cout << demo_4.name << std::endl;
    std::cout << demo_5.name << std::endl;
    std::cout << demo_6.name << std::endl;
}

void class_3() {
    const Class_2_Demo demo = Class_2_Demo("Test");
    
    // const에서는 값을 바꾸거나 method 실행이 안 됨
//    demo.show();
//    demo.name = "2";
    
    // mutable은 됨
    demo.group = "G";
    
    // const로 정의된 method는 됨
    demo.non_mutating_method();
}

void class_4() {
    Class_2_Demo *demo = new Class_2_Demo("Test");
    delete demo;
    
    // 기본 constructor가 3번 불리고
    Class_2_Demo *demos_1 = new Class_2_Demo[3];
    // Destructor가 3번 불림
    delete[] demos_1;
    
    Class_2_Demo demo_2("Test");
    
    // C++11
    Class_2_Demo demo_3 = {"Test", "Test"};
    Class_2_Demo demo_4{"Test", "Test"};
    Class_2_Demo *demo_5 = new Class_2_Demo{"Test", "Test"};
    delete demo_5;
    
    Class_2_Demo *demo_6 = new Class_2_Demo[3] {{"Test", "Test"}};
    delete [] demo_6;
}

void class_5() {
    // 기본 constructor가 4번 불리고
    Class_2_Demo arr[4];
    // stack이 소멸되면서 Destructor가 3번 불림
    
    arr[0].show();
    arr[3].show();
    
    Class_2_Demo arr2[4] {
        {"Test"},
        {"Test", "Test"},
        {"Test", "Test"}
    };
}

void class_operator_1() {
    Class_2_Demo first;
    Class_2_Demo second;
    
    Class_2_Demo result1 = first + second;
    Class_2_Demo result4 = second.operator+(first);
    
    Class_2_Demo result2 = 3.0 + first;
    Class_2_Demo result6 = operator+(2.0, first);
    int result3 = second + 4.0;
    int result5 = operator+(first, 4.0);
    
    first << std::cout;
}

void class_type_casting_1() {
    // Constructor가 불림
    Class_2_Demo demo_1 = 3.0;
    Class_2_Demo demo_2 = static_cast<Class_2_Demo>(5.0);
    Class_2_Demo demo_3 = (Class_2_Demo)4.0;
    
    // operator가 불림
    int demo_4 = demo_1;
    double demo_5 = (double)demo_2;
    
    std::cout << demo_4 << std::endl; // 3
    std::cout << demo_5 << std::endl; // 3
    
    // explicit - demo_4 같은 암시적 변환을 막음
    // ERROR
//    std::string demo_6 = demo_1;
    std::string demo_6 = (std::string)demo_1;
    std::string demo_7 = static_cast<std::string>(demo_1);
    
    std::cout << demo_6 << demo_7 << std::endl;
}

// 원래는 enum에서 이름이 겹치면 안 되지만, class를 쓰면 namespace 처럼 충돌을 피할 수 있음
enum class scoped_enumerations_1_demo_1 { Small, Medium, Large, Jumbo };
enum class scoped_enumerations_1_demo_2 { Small, Medium, Large, Jumbo };
void scoped_enumerations_1() {
    scoped_enumerations_1_demo_1 size = scoped_enumerations_1_demo_1::Small;
    
    // Not allowed
//    std::cout << size << std::endl;
    // Allowed
    std::cout << static_cast<int>(size) << std::endl; // 0
}

// 별 문제 없이 StringBad::num_strings이 잘 카운팅 됨
void stringbad_1() {
    using namespace std; {
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
    }
}

void stringbad_2_demo_1(StringBad &rsb) {
}
StringBad & stringbad_2_demo_2(StringBad &rsb) {
    return rsb;
}
void stringbad_2_demo_3(StringBad sb){
}
StringBad stringbad_2_demo_4(StringBad &rsb) {
    return rsb;
}
void stringbad__2() {
    using namespace std; {
        StringBad headline1("Celery Stalks at Midnight");
        
        // 문제가 없음 - reference type
        stringbad_2_demo_1(headline1);
        StringBad headline2 = stringbad_2_demo_2(headline1);
        
        // Runtime 에러
        // stringbad_1_demo_2()가 불리면서 StringBad이 복사가 되는데, str의 포인터가 그대로 복사되므로, destrcutor가 original, copy에서 불리면서 str에 delete가 두번 불리는 현상이 발생
//        stringbad_2_demo_3(headline1);
        
        // Runtime 에러 : 객체 복사가 되면서 위랑 같은 문제
//        StringBad headline3 = headline1;
        StringBad headline4 = stringbad_2_demo_4(headline1);
    }
}

void stringbad_3_demo_1(StringBad_2 &rsb) {
}
void stringbad_3_demo_2(StringBad_2 sb){
}
void stringbad_3() {
    StringBad_2 headline1("Celery Stalks at Midnight");
    
    // copy constructor가 불리면서 복사 - str에 새로운 pointer가 할당되므로 문제가 사라짐
    stringbad_3_demo_2(headline1);
    
    // = operator
    StringBad_2 headline2 = headline1;
}

void const_oerator_1() {
    Const_Operator_1 first { "First" };
    Const_Operator_1 second { "Second" };
    
    Const_Operator_1 third;
    third = (first + second);
    std::cout << third << std::endl; // FirstSecond
    
    Const_Operator_1 fourth;
    // 원리
    /*
     operator+에 의해 Const_Operator_1 &가 반환됨
     반환된 값에 fourth 할당
     결론 : fourth에는 아무 변화가 없음
     */
    (first + second) = fourth;
    std::cout << third << std::endl; // 아무것도 안 나옴
    
    /*
     만약에 operator+의 반환 타입에 const를 붙였을 경우, (first + second)는 const를 반환하기 때문에 = fourth에서 에러가 남
     */
}

void string_mock_demo_1() {
    String_Demo str1 = "1";
    String_Demo str2 = "245";
    std::cout << (str1 < str2) << std::endl;
    std::cout << (str1 == str2) << std::endl;
    std::cout << (String_Demo("1") > str2) << std::endl;
    
    // char & operator[] (int i);
    std::cout << str2[1] << std::endl;
    
    const String_Demo str3 {"12345"};
    // const char & operator[](int i) const;
    std::cout << str3[2] << std::endl;
    
    std::cout << str3.length() << std::endl;
    
    std::cout << String_Demo::HowMany() << std::endl;
    
    // <<, >> operators
    std::cout << str3 << std::endl;
    
    String_Demo str4;
    std::cin >> str4;
    std::cout << str4 << std::endl;
}

void run(void) {
    const_oerator_1();
    string_mock_demo_1();
}
