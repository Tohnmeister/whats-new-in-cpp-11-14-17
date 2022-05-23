#include <iostream>

// C++11 introduced constructor delegation.

// Consider the following:
class A {
public:
    A(int x, int y, int z) 
        : _x(x)
        , _y(y)
        , _z(z) {
    }

    A(int x, int y)
        : _x(x)
        , _y(y)
        , _z(0) {
    }

    explicit A(int x)
        : _x(x)
        , _y(0)
        , _z(0) {
    }

private:
    int _x;
    int _y;
    int _z;

};

// This can be changed too:
class B {
public:
    B(int x, int y, int z)
        : _x(x)
        , _y(y)
        , _z(z) {
    }

    B(int x, int y)
        : B(x, y, 0) {
    }

    explicit B(int x)
        : B(x, 0, 0) {
    }

private:
    int _x;
    int _y;
    int _z;

};

// Next to that, C++11 introduced inherited constructors.
// Consider the following base class with several constructors:
class Base {
public:
    Base(int x, int y)
        : _x(x)
        , _y(y) {
    }

    explicit Base(int x)
        : Base(x, 0) {
    }

    int getX() const {
        return _x;
    }

    int getY() const {
        return _y;
    }

private:
    int _x;
    int _y;
};

// And a child class that does nothing special in its constructor, just delegating to the base class' constructors.
class Child : public Base {
public:
    Child(int x, int y)
        : Base(x, y) {
    }

    explicit Child(int x)
        : Base(x) {
    }

};

// This causes a lot of boilerplate and can easily add up when having to support all of the base class constructors.
// Inherited constructors solve this. Consider the following class that also inherits from Base.
class AnotherChild : public Base {
    using Base::Base; // Inherits all Base's constructors
};

int main() {
    AnotherChild a{ 3, 4 };

    std::cout << "x = " << a.getX() << std::endl;
    std::cout << "y = " << a.getY() << std::endl;

    return 0;
}
