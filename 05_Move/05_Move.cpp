#include <iostream>
#include <vector>

class Person {
public:
    explicit Person(const std::string& name)
        : _name(name) {
    }

    Person(const Person& person) {
        std::cout << "copy constructor" << std::endl;

        _name = person._name;
    }

    Person& operator=(const Person& person) {
        if (this != &person) {
            std::cout << "copy assignment" << std::endl;

            _name = person._name;
        }

        return *this;
    }

private:
    std::string _name;

};

class AddressBook {
public:
    void addPerson(const Person& person) {
        _persons.push_back(person);
    }

private:
    std::vector<Person> _persons;

};

Person createPerson(const std::string& name) {
    Person person{ name };
    return person;
}

int main() {
    auto person = createPerson("Pete");
    AddressBook addressBook;
    addressBook.addPerson(person);

    // How many copies are made of the Person?

    // And how many of them are really needed?






















    // First, a bit about lvalues vs rvalues.
    // Below, i is an lvalue, and 7 is an rvalue.
    int i = 7;












    // And here, person is an lvalue, and createPerson("Jack") is an rvalue.
    Person person = createPerson("Jack");















    // Overly simplified, think of it like this:
    // - An lvalue is something that is typically on the left side of an assignment. It can be assigned to and from. It persists beyond the expression that uses it.
    // - An rvalue is something that is typically on the right side of an assignment. It can only be assigned from. It does not persist beyond the expression that uses it. E.g. a temporary.













    // Before C++11, would create a temporary Person, which would then be placed inside's Person's copy constructor to initialize Person.
    Person person1 = createPerson("Jack");

    // But considering that the right side is a temporary and isn't needed anymore, wouldn't it be nice if there was a mechanism that allowed you to
    // move the temporary inside the newly created Person, rather than copying it?


    // C++11 introduced rvalue references and move semantics.



    // First, important to understand is, that one can create a reference to an rvalue:
    Person&& person2 = createPerson("Jack");

    // Now the lifetime of the temporary is extended to the scope of person2.




    // Second, C++11 introduced two new types of functions for a class, namely a move constructor and a move assignment operator.
    // E.g.
    // Person(Person&& other); // Move constructor
    // Person& operator=(Person&& other); // Move assignment operator.

    // As can be seen, they accept a rvalue reference. Meaning, if such a function is available, the following:
    Person person3 = createPerson("Jack");
    // would not call the copy constructor, but the move constructor instead.

    // Move functions should, instead of bluntly copying members, move resources in an efficient way. E.g. by simply swapping
    // pointers to dynamically allocated arrays, etc. And are thus far more efficient than their copy equivalents.



    // Now let's say someone is done with person3 and wants to move it to another Person. What will the following statement do?
    Person person4 = person3;
















    // It copies. Why? person3 is an lvalue. And for lvalues the copy constructor will be called.

    // std::move to the rescue. In order to actually move person3 into person4, person3 has to be cast into an rvalue reference, by doing the following:
    Person person5 = std::move(person3);




















    // Now, let's slowly change Person to support move and change functions accepting Person references and std::string references.


    return 0;
}
