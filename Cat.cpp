//
// File's name: Cat.cpp
// Author: Anh Khoi Do
// Date: 09/28/2015
//
// Description: Implementation file of a class that refers to a cat.
// The latter was defined in a header file called Cat.h.
//===========================================================================



#include "Cat.h"
#include <cstring>
#include <iostream>
#include <string>
#include <new>

Cat::Cat() {
	age = 0;
	name[0] = '\0';
	breed = NULL;
}

Cat::Cat(int a, const char* n, const char* b) {

	breed = new (std::nothrow) char[strlen(b) + 1];
	if (a != 0 && n != NULL && b != NULL) {
		age = a;
		strncpy(name, n, MAX_SIZE + 1);
		strcpy(breed, b);
	}

}


Cat::~Cat() {
	delete[] breed;
	breed = NULL;	
}

bool operator!=(const Cat& left, const Cat& right) {
	bool condition;

	if (((left.getAge() != right.getAge()) && (left.getName() != right.getName()) && (left.getBreed() != right.getBreed())))
		condition = true;
	else
		condition = false;

	return condition;
}

int Cat::getAge() const {
	return age;
}

const char* Cat::getName() const {
	return name;
}

const char* Cat::getBreed() const {
	return breed;
}

std::ostream& Cat::read(std::ostream& os) const {
	os << "Name: " << name << ", Age: " << age << ", Breed: " << breed << std::endl;

	return os;
}

std::istream& Cat::write(std::istream& is) {

	//=======================//
	// Local variables that  //
	// will be sent          //
	// to the setter.        //
	//=======================//
	char nm[50], br[50];
	int a;

	//================================//
	// This input can be with spaces. //
	// Indeed, try to write my first  //
	// name, which is "Anh Khoi".     //
	//================================//
	std::cout << "Type the name of your cat: ";
	is.getline(nm, sizeof(nm));


	std::cout << "Its age: ";
	is >> a;
	std::cout << "Breed: ";
	
	is.ignore();
	is.getline(br, sizeof(br));

	setTheCat(a, nm, br);

	return is;
	
}


Cat::Cat(const Cat& src) {
	setTheCat(src.getAge(), src.getName(), src.getBreed());
}

Cat& Cat::operator=(Cat& src) {
	if (this != &src) {
		setTheCat(src.age, src.name, src.breed);
	}

	return *this;
}

void Cat::setTheCat(int a, const char* n, const char* b) {
	age = a;
	strncpy(name, n, MAX_SIZE + 1);

	breed = new (std::nothrow) char[strlen(b) + 1];
	if (b != NULL)
		strcpy(breed, b);
}


//======================================
// Non-member helper operators.
//======================================
std::ostream& operator<<(std::ostream& os, const Cat& src) {
	src.read(os);

	return os;
}

std::istream& operator>>(std::istream& is, Cat& src) {
	src.write(is);

	return is;
}

bool operator==(const Cat& left, const Cat& right) {
	bool condition;

	if (left.getAge() == right.getAge() && left.getName() == right.getName() && left.getBreed() == right.getBreed()) {
		condition = true;
	} else {
		condition = false;
	}
	return condition;
} // End of the comparison operator.
