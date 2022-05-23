#include <iostream>

// A function that is declared constexpr potentially yield constant expressions (e.g. compile time).
constexpr int sum(int a, int b) {
    return a + b;
}

int main() {
    // As a result, the function may be used to initialize a constexpr variable or as the bounds of an array.
    constexpr int MySum = sum(10, 20);
    int myArray[sum(10, 20)];

    // It can also be used in if statements

    if constexpr (sum(10, 20) == 30) {
        std::cout << "10 + 20 == 30" << std::endl;
    } else {
        std::cout << "10 + 20 != 30" << std::endl;
    }

    // Guideline:
    // - Replace macros by constexpr functions
    // - Replace const variables by constexpr variables as much as possible

    return 0;
}
