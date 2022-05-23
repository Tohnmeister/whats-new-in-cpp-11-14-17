#include <iostream>

// Inheritance is often misused.

// Consider you're developing a class as part of a library, which you do not intend to be inherited from (problems like slicing, etc.).
//
// Or consider you're designing an inheritance tree with polymorphic behavior, but you do not want clients to inherit any further.
//
// Pre-C++11 there was no way to achieve this. Anybody could inherit from any existing class.
//
// C++11 introduced final.
// 
// Example:
struct IAnimal {
    virtual ~IAnimal() = default;

    virtual void makeNoise() = 0;
};

// Dog is marked as final. Inheriting from Dog is not possible.
class Dog final : public IAnimal {
public:
    virtual void makeNoise() {
        std::cout << "Woof" << std::endl;
    }
};

// E.g. this will not compile:
//class SpecialKindOfDog : public Dog {
//
//};

// Alternatively final can be put on method level too. Indicating that the class can be inherited from, but the method
// cannot be overriden any further.
class Cat : public IAnimal {
public:
    virtual void makeNoise() final {
        std::cout << "Meow" << std::endl;
    }
};

// So, now Cat can still be inherited from
class SpecialCat : public Cat {
    // But this method will not compile.
    /*virtual void makeNoise() {
    }*/
};


int main() {
    std::cout << "Hello World!\n";
}
