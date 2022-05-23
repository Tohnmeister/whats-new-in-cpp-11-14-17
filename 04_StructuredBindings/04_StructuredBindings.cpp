#include <iostream>
#include <map>

int main() {
    std::pair<int, std::string> pair = { 1, "one" };
    std::cout << pair.first << " : " << pair.second << std::endl;


















































    // Alternatively, use structured binding.
    const auto& [number2, name2] = pair;
    std::cout << number2 << " : " << name2 << std::endl;

    // Works for arrays too.
    int numbers[] = { 1, 2, 3, 4 };
    auto [nr1, nr2, nr3, nr4] = numbers;
    std::cout << nr1 << ", " << nr2 << ", " << nr3 << ", " << nr4 << std::endl;


    std::map<int, std::string> idCustomerMap = {
        { 1, "Pete" },
        { 2, "Petra" },
        { 3, "Kendra" }
    };

    // Combined with automatic type deduction and ranged based for loops, the following:














    for (std::map<int, std::string>::const_iterator it = idCustomerMap.begin(); it != idCustomerMap.end(); ++it) {
        std::cout << it->first << " : " << it->second << std::endl;
    }
























    // Can be turned into:












    for (const auto& [id, name] : idCustomerMap) {
        std::cout << id << " : " << name << std::endl;
    }
}

