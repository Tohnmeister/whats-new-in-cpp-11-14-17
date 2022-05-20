#include <iostream>
#include <vector>
#include <memory>

class Person {};

class Car {};

Car getCar() {
    return Car{};
}

int main()
{
    std::vector<int> numbers = { 1, 2, 3 };
    std::unique_ptr<Person> person = std::make_unique<Person>();
    Car myCar = getCar();

    for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // See below.
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // Above example shows a lot of redundant type information.
    // C++11 introduced the 'auto' keyword for automatic type deduction.
    // Everything is still statically checked. The type cannot be changed. But the compiled deduces the type for you.

    // Example:

    auto person2 = std::make_unique<Person>();
    auto anotherCar = getCar();
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

