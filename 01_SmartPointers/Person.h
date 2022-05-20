#pragma once

#include <string>

class Person {
public:
	Person(int age)
		: _age(age) {

	}

	void setPartner(Person* partner) {
		_partner = partner;
	}

private:
	int _age;
	Person* _partner = nullptr;

};
