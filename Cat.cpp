//
// File's name: Cat.cpp
// Author: Anh Khoi Do
// Date: 09/28/2015
//
// Description: Implementation file of a class that refers to a cat.
// The latter was defined in a header file called Cat.h.
//
// Revision history:
// 
// Name            Date          Version     Reason(s)
// Anh Khoi Do     09/28/2015    1           Creation of the file.
//
// Anh Khoi Do     09/10/2015    2           Addition of a move copy constructor
//                                           and a move assignment operator.
//
// Anh Khoi Do     11/05/2015    3           Removal of the setter in the copy
//					     constructor, assignment operator, move
//                                           copy constructor and move assignment
//                                           operator. All of these now send the data
//                                           of their parameter to pointer *this.
//
// Anh Khoi Do      11/26/2015   4           Adding the update of the header in the
//					     implementation file.
//======================================================================================

#include "Cat.h"
#include <cstring>
#include <new>

Cat::Cat() {
	_age = 0;
	_name[0] = '\0';
	_breed = nullptr;
	_ownerName = "";
}

Cat::Cat(int a, const char* n, const char* b, const std::string& n) {

	
	if (a != 0 && n != NULL && b != nullptr && n != "") {
		_age = a;
		strncpy(_name, n, MAX_SIZE + 1);
		
		//====================================================//
		// Dynamically allocate a memory for _breed (char*).  //
		//====================================================//
		_breed = new (std::nothrow) char[strlen(b) + 1];
		strcpy(_breed, b);
		
		_ownerName = n;
	} else *this = Cat();

}


Cat::~Cat() {

	//=====================================//
	// Delete the value of _breed (char*). //
	//=====================================//
	delete[] _breed;

	//========================================//
	// Reset the value of _breed to nullptr.  //
	//========================================//
	_breed = nullptr;
}

const std::string& Cat::getOwnerName() const {
	return _ownerName;
}

int Cat::getAge() const {
	return _age;
}

const char* Cat::getName() const {
	return _name;
}

const char* Cat::getBreed() const {
	return _breed;
}

std::ostream& Cat::read(std::ostream& os) const {
	os << "Name: " << _name << ", age: " << _age << ", Breed: " << _breed << ", Owner: " << _ownerName << std::endl;

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
	std::string owName;

	//================================//
	// This input can be with spaces. //
	// Indeed, try to write my first  //
	// name, which is "Anh Khoi".     //
	//================================//
	std::cout << "Type the name of your cat: ";
	is.getline(nm, sizeof(nm));


	std::cout << "Its _age: ";
	is >> a;
	std::cout << "Breed: ";

	is.ignore();
	is.getline(br, sizeof(br));

	std::cout << "The name of its owner: ";
	getline(is, owName);

	setTheCat(a, nm, br, owName);

	return is;

}


Cat::Cat(const Cat& src) {

	this->_age = src._age;

	strcpy(this->_name, src._name);

	this->_breed = new (std::nothrow) char[strlen(src._breed) + 1];
	strcpy(this->_breed, src._breed);
	
	this->_ownerName = src._ownerName;

}

Cat& Cat::operator=(Cat& src) {
	if (this != &src) {
		this->_age = src._age;

		strcpy(this->_name, src._name);

		this->_breed = new (std::nothrow) char[strlen(src._breed) + 1];
		strcpy(this->_breed, src._breed);
		
		this->_ownerName = src._ownerName;
	}

	return *this;
}


Cat::Cat(Cat&& src) {
	this->_age = src._age;
	strcpy(this->_name, src._name);
	
	this->_breed = new (std::nothrow) char[strlen(src._breed) + 1];
	strcpy(this->_breed, src._breed);

	this->_ownerName = src._ownerName;

	src._age = 0;
	src._name[0] = '\0';
	src._breed = nullptr;
	src._ownerName = "";
}

Cat& Cat::operator=(Cat&& src) {
	if (this != &src) {
		if (this->_breed != nullptr) {
			delete[] this->_breed;

			this->_age = 0;
			this->_name[0] = '\0';
		} // End of the nested if statement.

		this->_age = src._age;
		strcpy(this->_name, src._name);

		//=================================================//
		// Dynamically allocate memory for _breed (char*)  //
		// of the current object (*this).                  //
		//=================================================//
		this->_breed = new (std::nothrow) char[strlen(src._breed) + 1];
		strcpy(this->_breed, src._breed);

		src._age = 0;
		src._name[0] = '\0';
		src._breed = nullptr;
		src._ownerName = "";
	} // End of the if statement.

	return *this;
}

//================//
// The setter.    //
//================//
void Cat::setTheCat(int a, const char* n, const char* b, const std::string& on) {
	_age = a;
	strncpy(_name, n, MAX_SIZE + 1);

	_breed = new (std::nothrow) char[strlen(b) + 1];
	if (b != nullptr)
		strcpy(_breed, b);
		
	_ownerName = on;
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
