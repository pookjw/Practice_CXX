//
//  main.cpp
//  CPP
//
//  Created by Jinwoo Kim on 4/1/23.
//

#include <iostream>

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

int main(int argc, const char * argv[]) {
    string_7();
    return EXIT_SUCCESS;
}
