#include <iostream>
#include <vector>

class Person {
public:
    Person(const std::string& name)
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

int main()
{
    auto person = createPerson("Pete");
    AddressBook addressBook;
    addressBook.addPerson(person);

    // How many copies are made of the Person?

    // And how many of them are really needed?

    
    
    
    
    
    
    // Explain rvalue references and move semantics. Slowly change Person to support move and change functions accepting Person references and std::string references.


    return 0;
}
