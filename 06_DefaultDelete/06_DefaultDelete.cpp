#include <iostream>
#include <string>

class Car {
public:
    explicit Car(std::string brand)
        : _brand(std::move(brand)) {
    }

    ~Car() {
        // does nothing
    }

    Car(const Car& other) 
        : _brand(other._brand) {
    }

    Car& operator=(const Car& other) {
        if (this != &other) {
            _brand = other._brand;
        }
        return *this;
    }

    Car(Car&& other)
        : _brand(std::move(other._brand)) {
    }

    Car& operator=(Car&& other) {
        if (this != &other) {
            _brand = std::move(other._brand);
        }
        return *this;
    }

private:
    std::string _brand;
};

class ComplexThingWhichShouldNotBeCopied {
public:

private:
    // Make copying impossible by making functions private.
    ComplexThingWhichShouldNotBeCopied(const ComplexThingWhichShouldNotBeCopied&);
    ComplexThingWhichShouldNotBeCopied& operator=(const ComplexThingWhichShouldNotBeCopied&);

};

int main() {
    // Consider the Car class above. It has:
    // - a constructor
    // - a default destructor
    // - a default copy constructor
    // - a default copy assignment operator
    // - a default move constructor
    // - a default move assignment operator

    // Five out of six member functions are behaving like the default compiler generated one.
    // One could omit them, so the compiler generates them. But sometimes being explicit is nice.
    // Wouldn't it be nice if one could be explicit about wanting the default implementation?

    // Show!





    // Now consider the ComplexThingWhichShouldNotBeCopied. It should not be copied. Pre-C++11 this would typically be
    // done by making the functions private.
    //
    // Wouldn't it be nice if you could be more explicit about not wanting these member functions?
    //
    // Show!

    std::cout << "Hello World!\n";

    return 0;
}
