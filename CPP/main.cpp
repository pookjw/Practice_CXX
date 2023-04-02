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

void vector_1() {
    // heap
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
    
    double a1[4] = {1.2, 2.4, 3.6, 4.8};
    
    vector<double> a2;
//    vector<double> a2(4); // fixing size
    a2[0] = 3.;
    a2[1] = 1.0 / 5.0;
    a2[2] = 0.5;
    a2[3] = 0.1;
}

int main(int argc, const char * argv[]) {
    pointer_3();
    return EXIT_SUCCESS;
}
