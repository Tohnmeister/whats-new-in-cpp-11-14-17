#include <iostream>
#include <vector>
#include <memory>

class Person {};

class Car {};

Car getCar() {
    return Car{};
}

std::vector<int> getNumbers() {
    return { 1, 2, 3 };
}

int main() {
    std::vector<int> numbers = getNumbers();
    std::unique_ptr<Person> person = std::make_unique<Person>();
    Car myCar = getCar();

    for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << std::endl;
    }


































    // Above example shows a lot of redundant type information.
    // C++11 introduced the 'auto' keyword for automatic type deduction.
    // Everything is still statically checked. The type cannot be changed. But the compiled deduces the type for you.

    // Example:

    auto numbers2 = getNumbers();
    auto person2 = std::make_unique<Person>();
    auto anotherCar = getCar();
    for (auto it = numbers2.begin(); it != numbers2.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Use it when:
    // - type is already clear from right side of assignment
    // - for iterators
    // - to save a lot of typing

    // Don't use it for numeric types.
}

