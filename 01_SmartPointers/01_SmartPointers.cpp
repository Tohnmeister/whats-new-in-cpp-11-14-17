// 01_SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <memory>

class Person {
public:
    explicit Person(const std::string& name)
        : _name(name) {
    }

    ~Person() {
        std::cout << _name << " destructed." << std::endl;
    }

    void setPartner(Person* partner) {
        _partner = partner;
    }

private:
    std::string _name;
    Person* _partner = nullptr;

};

class AddressBook {
public:
    void addPerson(Person* person) {
        _persons.push_back(person);
    }

private:
    std::vector<Person*> _persons;

};


int main() {
    AddressBook addressBook;
    Person* pete = new Person("Pete");
    Person* petra = new Person("Petra");
    pete->setPartner(petra);
    petra->setPartner(pete);
    addressBook.addPerson(pete);
    addressBook.addPerson(petra);

    // Problem/challenge:
    // - Memory leak. Can of course be solved with delete.
    // - Who is owner of Person memory? Who is reponsible of deleting it?

    // Possible solution is using unique_ptr or shared_ptr.

    // unique_ptr indicates unique ownership of resource. When unique_ptr goes out of scope, it will free the memory 'attached' to it.

    // Example:
    // std::unique_ptr<Person> pete{ new Person("Pete") };
    // 
    // Or better, by using factory functions:
    // 
    // std::unique_ptr<Person> petra = std::make_unique<Person>("Petra");
    //


    // shared_ptr indicates shared ownership of resource. It reference counts the number of shared_ptr instances referring to the same memory and will free memory once the reference count reaches 0.

    // Example:
    // std::shared_ptr<Person> pete{ new Person("Pete") };
    //
    // Or better again:
    //
    // std::shared_ptr<Person> petra = std::make_shared<Person>("Petra");

    // Raw pointer can still be fetched from unique_ptr and shared_ptr with .get member function. E.g.:
    // Person* rawPtr = pete.get();

    // Live exercise: Rebuild above code with unique_ptr or shared_ptr.
}
