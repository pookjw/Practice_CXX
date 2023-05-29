//
//  main.cpp
//  Cxx20
//
//  Created by Jinwoo Kim on 5/28/23.
//

#include <iostream>

void needInt(int i) {
    std::cout << "int: " << i << std::endl;
}

template <typename T>
int add(T first, T second) {
    return first + second;
}

#pragma mark - Requires Concept

template<>
int add<bool>(bool first, bool second) {
    return static_cast<int>(first) + static_cast<int>(second);
}

template<typename T> requires std::integral<T>
auto gcd(T a, T b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

template<typename T>
auto gcd1(T a, T b) requires std::integral<T> {
    if (b == 0) return a;
    else return gcd1(b, a % b);
}

template<std::integral T>
auto gcd2(T a, T b) {
    if (b == 0) return a;
    else return gcd2(b, a % b);
}

auto gcd3(std::integral auto a, std::integral auto b) {
    if (b == 0) return a;
    else return gcd3(b, a % b);
}

auto gcd7(auto a, auto b) {
    if (b == 0) return a;
    else return gcd7(b, a % b);
}


#pragma mark - Requires Clause

// Compile-time predicate
// Usage: sum<3>(300);
template<unsigned int i>
requires (i <= 20)
int sum(int j) {
    return i + j;
}


#pragma mark - Concepts as Return Type of a Function

template<typename T> requires std::integral<T>
std::integral auto gcd4(T a, T b) {
    if (b == 0) return a;
    else return gcd4(b, a % b);
}

std::integral auto gcd5(std::integral auto a, std::integral auto b) {
    if (b == 0) return a;
    else return gcd5(b, a % b);
}

#pragma mark - Compile-time predicates

void foo() {
    if constexpr(std::three_way_comparable<int>)
        std::cout << "True" << std::endl;
    
    if constexpr(!std::three_way_comparable_with<int, std::string>)
        std::cout << "False" << std::endl;
}

#pragma mark - Class Templates

template <std::regular T>
class MyVector {};

void class_template() {
    MyVector<int> myVec1;
//    MyVector<int &> myVec2;
}

template<typename T> requires std::regular<T>
void class_template_2() {
    MyVector<T> myVec;
}

#pragma mark - Struct Templates

template<typename T>
struct Vector {
    Vector() {
        std::cout << "Vector <T>" << std::endl;
    }
};

template<std::regular Reg>
struct Vector<Reg> {
    Vector () {
        std::cout << "Vector<std::regular>" << std::endl;
    }
};

#pragma mark - Generic Member Functions

struct NotCopyable {
    NotCopyable() = default; // 기본 동작을 컴파일러가 생성
    NotCopyable(const NotCopyable &) = delete; // 복사 동작을 삭제
};

template <typename T>
struct CopyableVector {
    void push_back(const T&) requires std::copyable<T> {}
};

void test_not_copyable() {
    CopyableVector<int> myVec;
    myVec.push_back(2020);
    
    CopyableVector<NotCopyable> myVec2;
//    myVec2.push_back(NotCopyable()); // Invalid reference to function 'push_back': constraints not satisfied
}

#pragma mark - Variadic Templates

/*
 ... : Fold Expressions
 */
template<std::integral... Args>
bool all(Args... args) { return (... && args); }

template<std::integral... Args>
bool any(Args... args) { return (... || args); }

// bool result = not value; == !value == not(value)
template<std::integral... Args>
bool none(Args... args) { return not(... || args); }


#pragma mark - Overloading

template<std::forward_iterator I>
void advance(I& iter, int n) {
}

template<std::bidirectional_iterator I>
void advance(I& iter, int n) {
}

template<std::random_access_iterator I>
void advance(I& iter, int n) {
}

#pragma mark - Multiple Concepts

template<typename Iter, typename IterValueType, typename Val> requires std::input_iterator<Iter> && std::equality_comparable_with<IterValueType, Val>
Iter find(Iter b, Iter e, Val v) {
    return b;
}

#pragma mark - Language-related concepts

struct MyStructA {
    operator int() const { return 0; }
};

template<typename T>
class MyObjectA {
public:
    MyStructA sa;
    MyObjectA() noexcept;
    
    operator std::string() const {
        return "";
    }
    
    operator MyStructA() { return {}; }
    
    int foo() { return 3; }
};

template<typename T>
class MyObjectB: public MyObjectA<T> {};

template<typename T>
class MyObjectC: protected MyObjectA<T> {};

template<typename T>
class MyObjectD: private MyObjectA<T> {};

void default_initializable() {
    if constexpr(std::default_initializable<MyObjectA<int>>) {
        std::printf("qq\n"); // custom을 지우고 default로 정의
    }
}

void same_as() {
    // type 같은지
    if constexpr(not std::same_as<MyObjectA<int>, MyObjectB<int>>) {
        std::printf("false\n");
    }
    
    if constexpr(not std::is_same<MyObjectA<int>, MyObjectA<double>>::value) {
        std::printf("false\n");
    }
}

void derived_from() {
    // only returns true when inherits as public level
    /*
     template<class _Dp, class _Bp>
     concept derived_from =
       is_base_of_v<_Bp, _Dp> &&
       is_convertible_v<const volatile _Dp*, const volatile _Bp*>;
     */
    if constexpr(std::derived_from<MyObjectB<int>, MyObjectA<int>>) {
        std::printf("true\n");
    }
    
    if constexpr(std::is_base_of<MyObjectA<int>, MyObjectB<int>>::value) {
        std::printf("true\n");
    }
    
    if constexpr(std::is_convertible<MyObjectB<int>, MyObjectA<int>>::value) {
        std::printf("true\n");
    }
    
    if constexpr(not std::derived_from<MyObjectC<int>, MyObjectA<int>>) {
        std::printf("false\n");
    }
    
    if constexpr(not std::derived_from<MyObjectD<int>, MyObjectA<int>>) {
        std::printf("false\n");
    }
}

void conversion() {
    if constexpr(std::convertible_to<double, int>) {
        std::printf("true\n");
    }
    
    // downcasting
    if constexpr(std::convertible_to<MyObjectB<int>, MyObjectA<int>>) {
        std::printf("true\n");
    }
    
    // convert using operator
    if constexpr(std::convertible_to<MyObjectA<int>, std::string>) {
        std::printf("true\n");
    }
}

void common_reference() {
    // common: MyObjectA<int>
    if constexpr(std::common_reference_with<MyObjectA<int>, MyObjectB<int>>) {
        std::printf("true\n");
    }
    
    if constexpr(not std::common_reference_with<MyObjectA<int>, int>) {
        std::printf("false\n");
    }
    
    if constexpr(not std::common_reference_with<MyObjectA<int>, int>) {
        std::printf("false\n");
    }
    
    // operator 때문
    if constexpr(std::common_reference_with<MyObjectA<int>, std::string>) {
        std::printf("true\n");
    }
    
    // operator 때문
    if constexpr(std::common_reference_with<MyObjectA<int>, MyStructA>) {
        std::printf("true\n");
    }
    
    if constexpr(std::common_reference_with<MyStructA, int>) {
        std::printf("true\n");
    }
    
    MyStructA a {};
    const int n = static_cast<const int>(a);
    int n2 = static_cast<int>(a);
    
    if constexpr(std::common_with<MyStructA, int>) {
        std::printf("true\n");
    }
}

namespace assignable_from {

class MyObjectB;
class MyObjectA {
public:
    MyObjectA& operator=(const MyObjectB&) {
        return *this;
    };
};
class MyObjectB {
public:
    MyObjectB& operator=(const MyObjectA&) {
        return *this;
    };
};

struct Foo {
    int x;
    Foo& operator=(const Foo&) = default;
};

struct Bar {
    double x;
    
    Bar& operator=(const Foo& foo) {
        this->x = static_cast<double>(foo.x);
        return *this;
    }
};

void foo() {
    MyObjectA a {};
    MyObjectB b {};
    
//    a = b;
    b = a;
    
    if constexpr(std::assignable_from<MyObjectA, const MyObjectB&>) {
        std::printf("True\n");
    }
    
    if constexpr(std::assignable_from<Bar&, const Foo&>) {
        std::printf("True\n");
    }
    
//    static_assert(std::assignable_from<const Foo&, Bar&>, "fail");
}

};

#pragma mark - std::swappable
// namespace의 std에 추가로 정의할 때 true

namespace my_swap {

class MyObjectA {
public:
    int x;
};

void foo() {
    static_assert(std::swappable<MyObjectA>, "fail");
    static_assert(std::swappable_with<MyObjectA&, MyObjectA&>, "fail");
}
};
template<>
void std::swap(my_swap::MyObjectA& a, my_swap::MyObjectA& b) noexcept {
    
}

#pragma mark - Arithmetic Concepts

namespace arithmetic_concepts {

void foo() {
    if constexpr(std::integral<std::uint8_t>) {
        std::printf("True\n");
    }
    
    if constexpr(not std::signed_integral<std::uint8_t>) {
        std::printf("False\n");
    }
    
    if constexpr(std::unsigned_integral<std::uint8_t>) {
        std::printf("True\n");
    }
    
    if constexpr(std::floating_point<std::double_t>) {
        std::printf("True\n");
    }
    
    if constexpr(std::floating_point<std::float_t>) {
        std::printf("True\n");
    }
}

};

#pragma mark - Lifetime Concepts

namespace lifetime_concepts {

class MyObject {
public:
    int x2;
    MyObject(int x): x2{x} {}  // User-defined constructor.
    MyObject(MyObject&) {}
    MyObject(int, double, std::string) {};
//    ~MyObject() = delete;
};


void foo() {
//    MyObject object {}; // ERROR: Attempt to use a deleted function
    MyObject *pObject = new MyObject {0, 0., ""};
//    delete pObject; // ERROR: Attempt to use a deleted function
    
    static_assert(std::constructible_from<MyObject, int>);
    
    if constexpr(std::destructible<MyObject>) {
        std::printf("True\n");
    }
    
    if constexpr(std::constructible_from<MyObject, int, double, std::string>) {
        std::printf("True\n");
    }
    
    if constexpr(not std::move_constructible<MyObject>) {
        std::printf("True\n");
    }
    
    if constexpr(std::copy_constructible<MyObject>) {
        std::printf("True\n");
    }
}

};

#pragma mark - Comparison Concepts

namespace comparison_concepts {

class MyObjectA {
public:
    friend bool operator==(const MyObjectA&, const MyObjectA&) { return true; }
};

class MyObjectB: public MyObjectA {
public:
    friend bool operator==(const MyObjectB&, const MyObjectB&) { return true; }
    friend bool operator==(const MyObjectB&, const MyObjectA&) { return true; }
    friend bool operator==(const MyObjectA&, const MyObjectB&) { return true; }
};

void foo() {
    if constexpr(std::equality_comparable<MyObjectA>) {
        std::printf("True\n");
    }
    
    if constexpr(std::equality_comparable_with<MyObjectA&, MyObjectA&>) {
        std::printf("True\n");
    }
    
    if constexpr(std::equality_comparable<MyObjectB>) {
        std::printf("True\n");
    }
    
    // requires common_reference
    if constexpr(std::equality_comparable_with<MyObjectA&, MyObjectB&>) {
        std::printf("True\n");
    }
}

};

int main(int argc, const char * argv[]) {
    comparison_concepts::foo();
    
    return EXIT_SUCCESS;
}

