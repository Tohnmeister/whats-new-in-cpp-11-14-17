#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = { 1, 2, 3 };

    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << std::endl;
    }























































    // Use range based for loops.
    // By value
    for (auto number : numbers) {
        std::cout << number << std::endl;
    }



    // Or for more complex types by (const) reference
    std::vector<std::string> names = { "Pete", "Petra", "Charles" };
    for (const auto& name : names) {
        std::cout << name << std::endl;
    }


    return 0;
}
