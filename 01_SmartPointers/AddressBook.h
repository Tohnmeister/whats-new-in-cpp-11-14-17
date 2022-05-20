#pragma once

#include <vector>



class AddressBook {
public:
	void addPerson(Person* person);
	
private:
	std::vector<Person*> _persons;

};
