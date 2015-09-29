//
// File's name: Dog.cpp
// Author: Dan Brennan
// Date: 09/28/2015
//
// Description: Implementation file of a class that refers to a Dog.
// The latter was defined in a header file called Dog.h.
//===========================================================================

#include "Dog.h"

Dog::Dog() {
		age = 0;
}

Dog::Dog(int a, const string n, const string b) :name(n), breed(b) {
	if (a > 0)
		age = a;
}

Dog::~Dog() {}

ostream& Dog::read(ostream& os) const {
	os << "Name: " << name << ", Age: " << age << ", Breed: " << breed << "\n";
	return os;
}

Dog::Dog(const Dog& src) {
	*this = src;
}

/*Dog& Dog::operator=(const Dog& src) {
	if (this != &src) {
		name = src.name;
		breed = src.breed;
		age = src.age;
	}
	return *this;
}*/


//======================================
// Non-member helper operators.
//======================================
ostream& operator<<(ostream& os, const Dog& src) {
	src.read(os);
	return os;
}
