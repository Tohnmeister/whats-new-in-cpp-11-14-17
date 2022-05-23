#include <iostream>
#include <vector>
#include <algorithm>

bool isOdd(int i) {
    return i % 2 != 0;
}

bool isEven(int i) {
    return i % 2 == 0;
}

int main() {
    // C++11 introduced a few new algorithms for quickly checking if a collection:
    // - has only elements that satisfy a predicate
    // - has atleast one element that satisfies a predicate
    // - has no elements that satisfy a predicate

    std::vector<int> oddNumbers = { 1, 3, 5, 7, 9 };

    // Check if all elements are odd.
    bool areAllOdd = std::all_of(oddNumbers.begin(), oddNumbers.end(), &isOdd);
    // Check if it contains any even element.
    bool containsEven = std::any_of(oddNumbers.begin(), oddNumbers.end(), &isEven);
    // Check if none are even.
    bool areNoneEven = std::any_of(oddNumbers.begin(), oddNumbers.end(), &isOdd);

    std::cout << "areAllOdd: " << areAllOdd << "\n";
    std::cout << "containsEven: " << containsEven << "\n";
    std::cout << "areNoneEven: " << areNoneEven << "\n";

    return 0;
}
