#include <iostream>

// Consider the following:
class Animal {
public:
    virtual ~Animal() = default;

    virtual void makeNoise() {}
};

















// And let's say you're developing Dog in a completely different part of the code, assuming 'makeNoise' is and stays a
// virtual method.
class Dog : public Animal {
public:
    virtual void makeNoise() {
        std::cout << "Woof" << std::endl;
    }
};



















int main()
{
    Animal* animal = new Dog();
    animal->makeNoise();
    delete animal;

    // Question: What happens when somebody decides that makeNoise in IAnimal is not virtual anymore?


















    // Is there a way to prevent this?








    return 0;
}

