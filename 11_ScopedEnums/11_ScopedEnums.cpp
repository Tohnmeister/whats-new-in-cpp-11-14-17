#include <iostream>

// Enums pre-C++11 had several flaws:
// - Their constants shared the scope of the enum's parent.
// - They could be implicitly casted to ints, leading to sometimes strange/unexpected behavior.

// E.g. the following does not compile

/*
enum MyEnum1 {
    VALUE
};

enum MyEnum2 {
    VALUE // Triggers a redefinition error
};
*/

// Instead, the enums have to be wrapped in classes or different namespaces:

namespace Foobar {
    enum MyEnum {
        VALUE
    };
};

namespace Barfoo {
    enum MyEnum {
        VALUE
    };
};

enum State {
    OFF,
    SOFT_OFF,
    AVAILABLE,
    STANDBY,
    LOW_POWER
};

void myFunc(int i) {
    std::cout << "myFunc(int)" << std::endl;
    std::cout << i << std::endl;
}

int main()
{
    // Calls myFunc(int). Desired? Maybe not.
    myFunc(SOFT_OFF);

    // Show enum class!

    return 0;
}
