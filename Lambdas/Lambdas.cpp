#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int square(int i) {
    return i * i;
}

int incrementBy(int addition, int i) {
    return i + addition;
}

int main()
{
    // Recognize this?
    std::vector<int> numbers = { 1, 2, 3 };

    std::vector<int> squaredNumbers;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(squaredNumbers), &square);
    for (auto number : squaredNumbers) {
        std::cout << number << std::endl;
    }

    // Or this?
    std::vector<int> incrementedByTwo;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(incrementedByTwo), std::bind(&incrementBy, 2, std::placeholders::_1));
    for (auto number : incrementedByTwo) {
        std::cout << number << std::endl;
    }

    // Wouldn't it be nice if, for these simple functions, it could be done in place?
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    std::cout.setstate(std::ios_base::failbit);
    // Welcome lambdas.
    std::vector<int> incrementedByThree;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(incrementedByThree), [](int number) {
        return number + 3;
    });
    for (auto number : incrementedByThree) {
        std::cout << number << std::endl;
    }






    std::cout.setstate(std::ios_base::failbit);
    // In lambdas you can use 'external' variables, by capturing them.
    // E.g.:
    std::vector<int> multipliedByFour;
    const int multiplier = 4;
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(multipliedByFour), [multiplier](int number) {
        return number * multiplier;
    });
    for (auto number : multipliedByFour) {
        std::cout << number << std::endl;
    }

















    std::cout.setstate(std::ios_base::failbit);
    // If you want to modify the captured variable, it must be captured by reference:
    int i;
    auto myLambda = [&i] {
        i = 17;
    };
    myLambda();
    std::cout << i << std::endl;


    return 0;
}
