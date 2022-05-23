#include <iostream>

// Pre-C++11 class members had to be defaultly initialized in the constructor. E.g.:

class A {
public:
    A();

private:
    int _x;
    int _y;
    int _z;

};

A::A()
    : _x(0)
    , _y(0)
    , _z(0) {
}

// C++11 introduced support for initialization in the class's declaration. E.g.:
class B {
public:
    B() = default;

    int _x = 0; // By using =
    int _y{ 0 }; // Or by using braces
    int _z{ 0 };
    std::string _name{ "something" }; // Can be anything constructable at runtime.
    std::string _otherName{ _name }; // And can depend on other member fields.

};

int main()
{
    B b;

    std::cout << b._otherName << std::endl;
}
