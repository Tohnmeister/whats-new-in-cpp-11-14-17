#include <iostream>
#include <vector>
#include <map>

int main()
{
    // Many STL containers now support initialization through initializer lists.
    // E.g. instead of:
    std::vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);

    // One can write:
    std::vector<int> numbers2 = { 1, 2, 3 };
    
    // And instead of:
    std::map<int, int> squares;
    squares[1] = 1;
    squares[2] = 4;
    squares[4] = 16;

    // One can write:
    std::map<int, int> squares2 = {
        { 1, 1 },
        { 2, 4 },
        { 4, 16 }
    };

    return 0;
}
