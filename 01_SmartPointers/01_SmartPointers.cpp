// 01_SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Person {
public:
	Person(const std::string& name)
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


int main()
{
	AddressBook addressBook;
	Person* pete = new Person("Pete");
	Person* petra = new Person("Petra");
	pete->setPartner(petra);
	addressBook.addPerson(pete);
	addressBook.addPerson(petra);

	// Problem/challenge:
	// - Memory leak. Can of course be solved with delete.
	// - Who is owner of Person memory? Who is reponsible of deleting it?

	// Show possible solution with unique_ptr and weak_ptr.
	// Show possible solution with shared_ptr.
}
