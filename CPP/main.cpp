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
    
}

int main(int argc, const char * argv[]) {
    new_line();
    return EXIT_SUCCESS;
}
