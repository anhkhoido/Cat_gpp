//
// File's name: Dog.cpp
// Author: Dan Brennan
// Date: 09/28/2015
//
// Description: Implementation file of a class that refers to a Dog.
// The latter was defined in a header file called Dog.h.
//===========================================================================

#include "Dog.h"
Dog::Dog() {}
Dog::~Dog() {}

void Dog::setName(const string n) {
	name = n;
}
void Dog::setBreed(const string b) {
	breed = b;
}
void Dog::setAge(const int a) {
	age = a;
}

ostream& Dog::read(ostream& os) const {
	os << "Name: " << name;
	os << ", Age: " << age;
	os << ", Breed: " << breed << "\n";
	return os;
}

istream& Dog::write(istream& is) {
	int a;
	string na, br;

	std::cout << "What is the name of your Dog: ";
	is >> na;
	setName(na);
	std::cout << "Its age: ";
	is >> a;
	setAge(a);
	std::cout << "Breed: ";
	is >> br;
	setBreed(br);
	return is;
}

Dog::Dog(Dog& rhs) {
	*this = rhs;
}

Dog& Dog::operator=(const Dog& rhs) {
	if(this != &rhs) {
		name = rhs.name;
		age = rhs.age;
		breed = rhs.breed;
	}
	return *this;
}

//======================================
// Non-member helper operators.
//======================================
ostream& operator<<(ostream& os, const Dog& src) {
	src.read(os);
	return os;
}

istream& operator>>(istream& is, Dog& src) {
	src.write(is);
	return is;
}
