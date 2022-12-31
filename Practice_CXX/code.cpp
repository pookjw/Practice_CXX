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
    // 같음
//    strncpy(prize.id_val.id_char, id_char, sizeof(prize.id_val.id_char));
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
    
    // char와 다르게, cpp string은 operator로 바로 비교 가능
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

void run(void) {
    cin_eof_2();
}
