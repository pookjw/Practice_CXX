//
//  main.cpp
//  CPP
//
//  Created by Jinwoo Kim on 4/1/23.
//

#include <iostream>
#include <memory>
#include <algorithm>
#include <fstream>

void practice_std(void) {
    std::cout << "1" << std::endl;
    
    using namespace std; {
        cout << "2" << std::endl;
    }
    
    using std::cout;
    cout << "4" << std::endl;
    
    using std::endl; {
        std::cout << "5" << endl;
    }
    
    using namespace std; {
        int carrots;
        cout << "How many carrots do you have?" << endl;
        cin >> carrots;
        cout << "Here are two more. ";
        carrots += 2;
        cout << "Now you have " << carrots << " carrots." << endl;
    }
}

void simon(int); // function prototype for simon()
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
    
    using namespace std;
    cout << sizeof wide_of_short << endl;
    cout << __SIZEOF_SHORT__ << endl;
    cout << sizeof wide_of_int << endl;
    cout << sizeof(wide_of_int) << endl;
    cout << sizeof wide_of_long << endl;
    cout << sizeof wide_of_long_long << endl;
}

void max_integers(void) {
    using namespace std;
    cout << SHRT_MAX << endl;
    cout << INT_MAX << endl;
    cout << LONG_MAX << endl;
    cout << LONG_LONG_MAX << endl;
    cout << CHAR_MAX << endl;
    cout << UCHAR_MAX << endl;
    cout << ULONG_MAX << endl;
    cout << ULLONG_MAX << endl;
}

void initialization_1(void) {
    int owls = 101;
    int wren(432); // C++ syntax
    std::cout << owls + wren << std::endl;
}

void initialization_2(void) {
    int hamburgers = {24}; // array initialization
    int apples[4] = {1, 2, 3, 4};
    int bananas[3] = {1}; // {1, 0, 0}
    int enums{8}; // not array, just value 8
    int rocs = {}; // {0} not array, just value 0
    
    for (int i = 0; i < sizeof(apples) / __SIZEOF_INT__; i++) {
        std::cout << *(apples + i) << std::endl;
    }
    
    int phychics{};
    std::cout << phychics << std::endl; // 0 - only once!
}

void cin_char_1(void) {
    using namespace std;
    
    char ch;
    
    cout << "Enter a character: ";
    cin >> ch;
    cout << "Hola! ";
    cout << "Thank you for the " << ch << " character." << endl;
}

void cin_char_2(void) {
    using namespace std;
    char ch;
    cout << "Enter a character: " << endl;
    cin >> ch;
    cout.put(ch) << endl; // put == <<
}

void new_line(void) {
    using namespace std;
    cout << endl;
    cout << '\n';
    cout << "\n";
}

void size_chars(void) {
    using namespace std;
    char ch1{'a'};
    wchar_t ch2{L'A'};
    char16_t ch3{u'a'};
    char32_t ch4{U'a'};
    
    cout << sizeof ch1 << endl; // 1
    cout << sizeof ch2 << endl; // 4
    cout << sizeof ch3 << endl; // 2
    cout << sizeof ch4 << endl; // 4
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
    
    cout << a << endl; // 2.52 * 10^8 = 252000000
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
    
    float tree = 3;
    int guess(3.8932);
    int debt = 7.2E12;
    
    cout << "tree = " << tree << endl;
    cout << "guess = " << guess << endl;
    cout << "debt = " << debt << endl;
}

void initialization_3(void) {
    const int code = 66;
    int x = 6;
    
    //    char c1{32325}; // overflow
    char c3 { code };
    //    const char c4 { x }; // error
    const int &c = const_cast<const int &>(x);
    x = 9;
    std::cout << c << std::endl;
    const char c4 { static_cast<const char>(c) };
    const char c5 { code };
    
    std::cout << c4 << std::endl;
}

void type_casting_1(void) {
    int a = 1;
    int b = (int)a;
    char c = 'A';
    int ci = (int)c;
    
    std::cout << ci << std::endl;
}

void static_cast_1(void) {
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    
    const int a = 1;
    float b = static_cast<float>(a);
    b += 0.5f;
    
    cout << b << endl;
}

void const_cast_1(void) {
    using namespace std;
    
    const int a = 1;
    int b = a;
    int *b2 = const_cast<int *>(&a);
    
    // Pointer가 불변, 값은 가변
    int * const c = &b;
    *c = 3;
    cout << b << endl; // 3
}

void reinterpret_cast_1(void) {
    const int a = 65;
    int *b = const_cast<int *>(&a);
    //    char *c = static_cast<char *>(b); // Static_cast from 'int *' to 'char *' is not allowed
    char *c = reinterpret_cast<char *>(b);
    const char *c2 = reinterpret_cast<const char *>(&a);
    std::cout << c << std::endl; // A
    std::cout << c2 << std::endl; // A
}

void auto_1(void) {
    auto a = 'a';
    std::cout << typeid(a).name() << std::endl; // c
}

void array_1(void) {
    const short months[12] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::cout << months[5] << std::endl;
}

void array_2(void) {
    int cards[4]; // {0, 0, 0, 0}
    
    //    cards = {0, 0, 0, 7}; // Array type 'int[4]' is not assignable
    
    const int a[4] = {0, 0, 0, 7};
    memcpy(&cards, &a, sizeof cards);
    
    for (int i = 0; i < sizeof a / __SIZEOF_INT__; i++) {
        std::cout << a[i] << std::endl;
    }
}

void array_3(void) {
    int cards[] = {3, 6, 8, 10};
    for (int i : cards) {
        std::cout << i << std::endl; // 3, 6, 8, 10
    }
    
    //    int cards2[]; // Definition of variable with array type needs an explicit size or an initializer
}

void array_4(void) {
    int a = 3;
    const int b = 3;
    
    a = 9;
    
    int c[a];
    int d[b];
    //    const int e[b]; // Default initialization of an object of const type 'const int[3]'
    const int f[b] = {0, 0, 0};
    //    const int g[a] = {0, 0, 0}; // Variable-sized object may not be initialized
}    

void string_1(void) {
    using namespace std;
    
    char a[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    cout << a << endl; // abcdefgh\310 - 마지막은 \0이어야 하는데 아니기에 랜덤 숫자
    
    char b[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', '\0'};
    cout << b << endl; // abcdefg
    
    char c[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'}; // 그냥 비워두면 \0으로 자동으로 채워짐
    cout << c << endl; // abcdefg
    
    char d[6] = "abcde"; // 맨 뒤에 \0이 달려야 하므로 5글자
    
    char e[6] = "abc"; // {'a', 'b', 'c', '\0', '\0', '\0'}
    char f[6]; // {'\0', '\0', '\0', '\0', '\0', '\0'}
    cout << f << endl; // Nothing
    
    char g[] = "abc"; // {'a', 'b', 'c', '\0'}
    for (char c : g) {
        if (c == '\0') {
            break;
        }
        cout << c << endl;
    }
}

void strlen_1(void) {
    char a[6] = "abcde";
    char b[6] = {'a', 'a', '\0', 'b', 'c', '\0'};
    char c[6];
    
    std::cout << strlen(a) << std::endl; // 5
    std::cout << strlen(b) << std::endl; // 2
    std::cout << strlen(c) << std::endl; // 0
}

void cin_string_1(void) {
    using namespace std;
    
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your favorite dessert: ";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
}

void cin_getline_1(void) {
    using namespace std;
    
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];
    
    cout << "Enter your name: ";
    cin.getline(name, ArSize);
    cout << "Enter your favorite dessert: ";
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

void cin_getline_returns_cin(void) {
    using namespace std;
    const int ArSize = 20;
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
    cout << "What is tis street address?\n";
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
    cout << "What is tis street address?\n";
    char address[80];
    
    
    cin.getline(address, 80);
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";
}

void string_2(void) {
    char first_date[] = "Le Chapon Dodu";
    char second_date[] ("The Elegant Plate");
    std::string third_date ("The Bread Bowl");
    std::string fourth_date {"Hank's Fine Eats"};
}

void string_3(void) {
    char char1[20];
    char char2[20] = "jaguar";
    
//    char1 = char2; // Array type 'char[20]' is not assignable
    memcpy(char1, char2, sizeof(char1));
    
    std::string str1;
    std::string str2 = "panther";
    
    str1 = str2; // Valid
}

void string_4(void) {
    using namespace std;
    
    string a = "A";
    string b = "B";
    string c = a + b;
    
    c += a;
    
    cout << c << endl; // "ABA"
    
    char char1[5] = "Test";
    char char2[5] = "Test";
    char char3[9];
    strcpy(char3, char1);
    strcat(char3, char1);
    
    cout << char3 << endl; // TestTest
}

void string_5(void) {
    char char1[20] = "Test";
    std::string string1 = "Test";
    
    using namespace std; {
        cout << sizeof char1 << endl; // 20
        cout << strlen(char1) << endl; // 4
        cout << string1.size() << endl; // 4
    }
}

void string_6(void) {
    wchar_t title[] = L"Chief Astrogator";
    char16_t name[] = u"Felonia Ripova";
    char32_t car[] = U"Humber Super Snipe";
}

void string_7(void) {
    using namespace std;
    
    std::cout << R"(Hello")" << std::endl;
    std::cout << "Hello\"" << std::endl;
    std::cout << R"+*((Hello)~~~~~+*)+*" << std::endl;
}

void structure_1(void) {
    struct inflactable {
        char name[20];
        float volume;
        double price;
    };
    
    struct inflactable goose; // keyword struct required in C
    
    inflactable hat;
    inflactable woopie_cushion;
    inflactable mainframe;
}

void structure_2(void) {
    struct inflacture {
        char name[20];
        std::string name2;
        float volume;
        double price;
    };
    
    inflacture guest = {
        "Glorious Gloria",
        "",
        1.88,
        29.99
    };
    
    inflacture pal = {
        "Andacious Arthur",
        "",
        3.12,
        32.99
    };
    
    inflacture duck {"Daphne", "", 0.12, 9.98};
    
    pal = duck;
    
    std::cout << guest.name << std::endl;
    std::cout << pal.volume << std::endl;
}

void structure_3(void) {
    struct perks {
        int key_number;
        char car[12];
    };
    
    struct perks_2 {
        int key_number;
        char car[12];
    } mr_glitz = {
        7, "Packard"
    };
    
    struct perks a;
    struct perks_2 b;
    
    // no tag
    struct {
        int x;
        int y;
    } position = {0, 0};
    
    struct {
        int x;
        int y;
    } const position_2 {}; // {0, 0}
}

void structure_4(void) {
    struct inflactable {
        char name[20];
        float volume;
        double price;
    };
    
    inflactable guests[2] = {
        {"Bambi", 0.5, 21.99},
        {"Godzilla"}
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
        unsigned int a : 100;
        
        unsigned int : 4;
        bool goodIn : 1;
    } torgle = { 4, 5, true };
    
    std::cout << torgle.goodIn << std::endl;
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
    
    (&pail)->int_val = 3;
    
    cout << __SIZEOF_INT__ << endl; // 4
    cout << __SIZEOF_LONG__ << endl; // 8
    cout << __SIZEOF_DOUBLE__ << endl; // 8
    cout << sizeof(one4all) << endl; // 8
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
    
    const char id_char[5] = "Test";
    
//    strcpy(prize.id_val.id_char, id_char);
//    strncpy(prize.id_val.id_char, id_char, 3);
    memcpy(prize.id_val.id_char, id_char, sizeof id_char);
    
    prize.type = widget::data_type::charr;
    
    switch (prize.type) {
        case widget::data_type::num:
            std::cout << prize.id_val.id_num << std::endl;
            break;
        case widget::data_type::charr:
            std::cout << prize.id_val.id_char << std::endl; // Never called.
            break;
        default:
            break;
    }
}

void enumeration_1(void) {
    using namespace std;;
    enum spectrum { red = 5, orange = 8, yellow, green, blue, violet, indigo, unltraviolet };
    
    cout << spectrum::orange << endl; // 8
    cout << orange << endl; // 8
    
    cout << yellow << endl; // 9
    
    spectrum band;
    cout << band << endl; // 0
    
    band = blue;
//    band = 6; // Assigning to 'spectrum' from incompatible type 'int'
    
    // Type castings
    band = static_cast<spectrum>(6);
    band = (spectrum)8;
    band = spectrum(8);
    
//    ++band; // Cannot increment expression of enum type 'spectrum'
    band = static_cast<spectrum>(band + 1);
    band = static_cast<spectrum>(band + orange);
    
    int a = 3;
    a += band;
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
    char charr_2[5] = "ABCD";
    void *p = malloc(sizeof(charr_2));
    charr = static_cast<char *>(p);
    
    using namespace std;
    
    cout << sizeof(p) << endl;
    
    strcpy(charr, charr_2);
    
    cout << charr << endl;
    free(p);
}

void new_delete_1(void) {
    using namespace std;
    int night = 1001;
    int *pt = new int;
    *pt = night;
    
    delete pt;
    
    int *pt2 = nullptr;
    delete pt2;
    
    int *psome = new int[10];
    delete [] psome;
}

void pointer_1() {
    using namespace std;
    
    double wages[] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};
    
    double *pw = wages;
    short *ps = &stacks[0];
    
    cout << *pw << endl; // 10000
    ++pw; // 8만큼 증가
    cout << *pw << endl; // 20000
    pw++;
    cout << *pw << endl; // 30000
    pw++;
    cout << *pw << endl; // (random) 3.82415e-205
    
    //
    
    cout << *(stacks + 1) << endl; // 2
    *(stacks + 2) = 6;
    cout << *(stacks + 2) << endl; // 6
    stacks[1] = 7;
    cout << *(stacks + 1) << endl; // 7
    cout << stacks[1] << endl; // 7
}

void pointer_2(void) {
    int tacos[10] = {5, 2, 8, 4, 1, 2, 2, 4, 6, 8};
    int *pt = tacos;
    ++pt;
    int *pe = &tacos[9];
    --pe;
    
    int diff = pe - pt;
    std::cout << diff << std::endl; // 7
}

void pointer_3(void) {
    struct inflactable {
        char name[20];
        float volume;
        double price;
    } value = {};
    
    struct inflactable *pt = &value;
    strcpy(pt->name, "Test");
    
    std::cout << value.name << std::endl; // Test
}

void array_7() {
    // array uses the stack, and requires fixed size.
    std::array<int, 5> ai;
    std::array<double, 4> ad = {1.2, 2.1, 3.43, 4.3};
}

void vector_1() {
    using namespace std;
    
    // heap
    vector<int> a2;
    a2.push_back(3);
    a2.push_back(4);
    a2.push_back(5);
    a2.push_back(6);
    a2.push_back(7);
    a2.push_back(8);
    a2.push_back(9);
    
    for (int i : a2) {
        cout << i << endl;
    }
    
    for (std::vector<int>::iterator it = a2.begin(); it != a2.end(); it++) {
        cout << *it << endl;
    }
    
    for (std::vector<int>::reverse_iterator it = a2.rbegin(); it != a2.rend(); it++) {
        cout << *it << endl;
    }
    
    cout << "---" << endl;
    
    a2.clear();
    cout << a2.size() << endl; // 0
    cout << a2.capacity() << endl; // 8
    
    a2.shrink_to_fit();
    cout << a2.capacity() << endl; // 0
    
    a2.resize(__SIZEOF_INT__);
    cout << a2.capacity() << endl; // 4
    cout << a2.empty() << endl; // 0
    a2.clear();
    cout << a2.empty() << endl; // 1
    
    a2.push_back(3);
    cout << a2.at(0) << endl; // 3
    a2.push_back(5);
    cout << a2.at(1) << endl; // 5
    
    cout << a2.size() << endl; // 2
    a2.pop_back();
    cout << a2.size() << endl; // 1
    
    a2.clear();
    for (int i = 0; i < 10; i++) {
        a2.push_back(i);
    }
    a2.erase(a2.begin() + 5);
    cout << a2.size() << endl; // 9
    
    //    a2[0] = 3.;
    //    a2[1] = 1.0 / 5.0;
    //    a2[2] = 0.5;
    //    a2[3] = 0.1;
    //    a2[4] = 0.3;
    //    
    //    for (double a : a2) {
    //        cout << a << endl;
    //    }
    //    cout << a2[4] << endl;
    //    cout << a2.capacity() << endl;
    //    cout << a2.size() << endl;
    //    a2.clear();
    //}
}

void vector_erase_1() {
    std::vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    for (std::vector<int>::iterator iterator = numbers.begin(); iterator != numbers.end(); iterator++) {
        std::cout << &(*iterator) << std::endl;
    }
    
    numbers.erase(numbers.begin() + 3);
    
    std::cout << "-----" << std::endl;
    
    for (std::vector<int>::iterator iterator = numbers.begin(); iterator != numbers.end(); iterator++) {
        std::cout << &(*iterator) << std::endl;
    }
}

void vector_remove_1() {
    // remove는 capacity를 바꾸지 않고 해당 position에 empty data를 삽입하는데
    // erase는 capacity를 줄이고 뒤에 있는 모든 메모리 주소들 값을 바꿈
    // 성능이나 메모리 효율 둘중 하나를 택하면 되는 문제
    std::vector<int> numbers(10);
    
    for (int i = 0; i < 10; i++) {
        numbers.at(i) = i;
    }
    
    for (std::vector<int>::iterator iterator = numbers.begin(); iterator != numbers.end(); iterator++) {
        std::cout << &(*iterator) << std::endl;
    }
    
    // requires `#include <algorithm>`
    remove(numbers.begin(), numbers.end(), 4);
    
    std::cout << "-----" << std::endl;
    
    for (std::vector<int>::iterator iterator = numbers.begin(); iterator != numbers.end(); iterator++) {
        std::cout << &(*iterator) << std::endl;
    }
    
    for (std::vector<int>::iterator iterator = numbers.begin(); iterator != numbers.end(); iterator++) {
        std::cout << *iterator << std::endl;
    }
}

void unique_ptr_1_foo(std::unique_ptr<int> number) {
    
}
void unique_ptr_1() {
    // allocate memory to heap
    // stack이 소멸되면 메모리가 자동으로 해제되며 다른 stack과 공유 불가능
    std::unique_ptr<int> number(new int);
    *number = 3;
    
    // Call to implicitly-deleted copy constructor of 'std::unique_ptr<int>'
//    unique_ptr_1_foo(number);
    
    // automatically deleted!
}

void shared_ptr_1_foo(std::shared_ptr<int> number) {
    std::cout << *number << std::endl;
}
void shared_ptr_1() {
    // ARC 느낌
    std::shared_ptr<int> number(new int);
    *number = 4;
    shared_ptr_1_foo(number);
}

void shared_ptr_2() {
    int *a = new int;
    std::shared_ptr<int> number(a);
    
//    delete a; // ERROR!
}


std::weak_ptr<int> number;
void weak_ptr_1() {
    {
        std::shared_ptr<int> number2(new int);
        number = number2;
        *(number.lock()) = 7;
        
        if (std::shared_ptr<int> n = number.lock()) {
            std::cout << *n << std::endl; // 4
        } else {
            std::cout << "expired!" << std::endl;
        }
    }
    
    if (std::shared_ptr<int> n = number.lock()) {
        std::cout << n << std::endl; // 4
    } else {
        std::cout << "expired!" << std::endl;
    }
}

void block_1() {
    int x = 20;
    {
        std::cout << x << std::endl; // 20
        int x = 200;
        std::cout << x << std::endl; // 200
    }
    
    std::cout << x << std::endl; // 20
}

void do_loop_1() {
    int n = 10;
    
    do {
        std::cout << n << std::endl;
    } while (--n);
}

void cin_fail_1() {
    using namespace std;
    
    // Ctrl + D
    while (cin.fail() == false) {
        cin.get();
    }
    
    cout << "Done" << endl;
}

void cin_eof_1() {
    using namespace std;
    
    int ch = cin.get();
    
    // Ctrl + D
    while (ch != EOF) {
        ch = cin.get();
    }
    
    cout << "Done" << endl;
}

void char_functions_1() {
    using namespace std;
    
    // check that value is alphanumeric, that is, a letter or a digit.
    cout << isalnum(static_cast<int>('$')) << endl; // 0
    cout << isalnum(static_cast<int>('A')) << endl; // 1
    cout << isalnum(static_cast<int>('3')) << endl; // 1
    
    // alphabetic
    cout << isalpha(static_cast<int>('a')) << endl; // 1
    cout << isalpha(static_cast<int>('0')) << endl; // 0
    
    // isblank checks whether an input value is a space or a horizontal tab.
    cout << isblank(static_cast<int>('\t')) << endl; // 1
    cout << isblank(static_cast<int>(' ')) << endl; // 1
    cout << isblank(static_cast<int>('\n')) << endl; // 0
    
    // iscntrl checks whether an input value is a control character.
    cout << iscntrl(static_cast<int>('\0')) << endl; // 1
    
    // is digit
    cout << isdigit(static_cast<int>('0')) << endl; // 1
    cout << isdigit(static_cast<int>('A')) << endl; // 0
    
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
    
    filesystem::path path("/Users/pookjw/Desktop/test.txt");
    ofstream outFile;
    outFile.open(path);
    
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile << 3.12 << endl; // 3.1
    outFile << 3.34 << endl; // 3.1
    outFile << 3.56 << endl; // 3.1
    outFile << 3.78 << endl; // 3.1
    
    outFile.close();
}

void ifstream_1() {
    using namespace std;
    
    filesystem::path path("/Users/pookjw/Desktop/test.txt");
    ifstream inFile;
    inFile.open(path);
    
    while (inFile.good()) {
        double value;
        inFile >> value;
        cout << "Value: " << value << endl;
    }
    
    inFile.close();
}

inline double inline_1_foo(double x) { return x * x; };
void inline_1() {
    using namespace std;
    double a, b;
    
    a = inline_1_foo(5.0);
    b = inline_1_foo(8.0);
}

void reference_variable_1() {
    using namespace std;
    int rats = 101;
    int &rodents = rats;
    
    cout << rodents << endl; // 101
    rodents += 1;
    cout << rats << endl; // 102
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
    int b = 500;
    
    reference_variable_2_swap_1(a, b);
    std::cout << a << " " << b << std::endl;
    
    reference_variable_2_swap_2(&a, &b);
    std::cout << a << " " << b << std::endl;;
}

double reference_variable_3_foo(const double &a = 4) {
//    a = 4; // Cannot assign to variable 'a' with const-qualified type 'const double &'
    return a * a * a;
}
void reference_variable_3() {
    std::cout << reference_variable_3_foo(3.0) << std::endl;
    std::cout << reference_variable_3_foo() << std::endl;
}

template <typename TEMPLATE_1>
void template_1_foo(TEMPLATE_1 &a, TEMPLATE_1 &b) {
    TEMPLATE_1 temp = a;
    a = b;
    b = temp;
}
void template_1() {
    int a = 3;
    int b = 4;
    template_1_foo(a, b);
    std::cout << a << " " << b << std::endl;
    
    std::string c = "c";
    std::string d = "d";
    template_1_foo(c, d);
    std::cout << c << " " << d << std::endl;
}

template <typename T>
void template_3(T);
template <typename T> // prototype에서는 한 번 더 명시해야함
void template_3(T a) { }

template <typename T>
T template_4_foo(T a) { // explicit
    std::cout << "T" << std::endl;
    return a;
}
template <> int template_4_foo<int>(int a) { // explicit
    std::cout << "int" << std::endl;
    return a;
}
void template_4() {
    template_4_foo("C");
    template_4_foo(3);
}

void decltype_1() {
    int a = 3;
    int &b = a;
    
    typeof(b) c = b; // int
    decltype(b) d = b; // int &
    
    a = 4;
    
    std::cout << c << " " << d << std::endl;
}

template <class T1, class T2>
auto decltype_2_foo(T1 x, T2 y) -> decltype(x + y) {
    // 자동으로 return type을 지정하려면 auto랑 decltype 기호를 같이 쓰면 된다.
    return x + y;
}

// unnamed namespace https://jogamja.tistory.com/121


int main(int argc, const char * argv[]) {
    decltype_1();
    return EXIT_SUCCESS;
}
