#include <iostream>

void func(void* ptr) {
    std::cout << "void*" << std::endl;
}

void func(int i) {
    std::cout << "int" << std::endl;
}

int main()
{
    // Which function will be called? Which one was intended?
    func(NULL);

    // And now?
    func(0);

    // Why? NULL is a macro for 0. And 0 is considered an int.
    
    // Is there a way to pass a null pointer, but consider it as a pointer?


    // nullptr
    // Show!
}
