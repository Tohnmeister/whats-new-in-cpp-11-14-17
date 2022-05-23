#include <iostream>
#include <map>
#include <string>

// Pre-C++11 the following had to be written when an alias for a type was needed:
typedef std::map<int, std::string> NumberMap;
typedef int Number;

// C++11 introduced type aliases. The above can be rewritten:
using NumberMap2 = std::map<int, std::string>;
using Number2 = int;

// Why is this better than typedef?

// It supports templates. E.g.
template <typename T>
using IntMap = std::map<int, T>;

int main() {
    IntMap<double> intToDouble = {
        { 1, 1.0 },
        { 2, 2.0 },
        { 3, 3.0 },
    };
}
