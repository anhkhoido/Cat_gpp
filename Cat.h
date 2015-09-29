//
// File's name: Cat.h
// Author: Anh Khoi Do
// Date: 09/28/2015
//
// Description: Definition of a class that
// refers to a cat and its attributes.
//===========================================

#include <iostream>
#include <string>

#define MAX_SIZE 30

class Cat {
	int age;
	char name[MAX_SIZE + 1];
	char *breed;
	

	public:
		Cat();
		Cat(int, const char*, const char*);
		~Cat();

		//====================//
		// Accessors.         //
		//====================//
		int getAge() const;
		const char* getName() const;
		const char* getBreed() const;
	 		

		//=====================//
		// Output operator.    //
		//=====================//
		std::ostream& read(std::ostream&) const;
		
		//==================//
		// Input operator.  //
		//==================//
		std::istream& write(std::istream&);

		//====================//
		// Copy constructor.  //
		//====================//
		Cat(const Cat&);
		
		

		//=====================//
		// Assignment operator //
		//=====================//
		Cat& operator=(Cat&);


		//===============================//
		// Mutators: Needed for the copy //
		// and assignment operators.     //
		//===============================//
		void setTheCat(int, const char*, const char*);
		
}; // End of the class.

//================================//
// Non-member output operator.    //
//================================//
std::ostream& operator<<(std::ostream&, const Cat&);

//=============================//
// Non-member input operator   //
//=============================//
std::istream& operator>>(std::istream&, Cat&);

bool operator!=(const Cat&, const Cat&);
bool operator==(const Cat&, const Cat&);
