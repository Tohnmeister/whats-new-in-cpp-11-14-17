// 01_SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Person {
public:
	Person(const std::string& name)
		: _name(name) {
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
	Person* tonni = new Person("Tonni");
	Person* diana = new Person("Diana");
	tonni->setPartner(diana);
	addressBook.addPerson(tonni);
	addressBook.addPerson(diana);

	// Problem/challenge:
	// - Memory leak.
	// - Who is owner of Person memory? Who is reponsible of deleting it?

}
