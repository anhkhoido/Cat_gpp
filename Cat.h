//
// File's name: Cat.h
// Author: Anh Khoi Do
// Date: 09/28/2015
//
// Description: Definition of a class that
// refers to a cat and its attributes.
//
// Revision history:
// 
// Name            Date          Version     Reason(s)
// Anh Khoi Do     09/28/2015    1           Creation of the file.
//
// Anh Khoi Do     09/10/2015    2           Addition of a move copy constructor
//                                           and a move assignment operator.
//
// Anh Khoi Do     11/26/2015    3           Addition of an std::string as a private
//					     data member, which is the owner's name.
//=======================================================================================

#include <iostream>
#include <string>

#define MAX_SIZE 30

class Cat {
	int _age;
	char _name[MAX_SIZE + 1];
	char* _breed;
	std::string _ownerName;
	

	public:
		Cat();
		Cat(int, const char*, const char*, const std::string&);
		~Cat();

		//====================//
		// Accessors.         //
		//====================//
		const std::string& getOwnerName() const;
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


		//=========================//
		// Move copy constructor.  //
		//=========================//
		Cat(Cat&&);
		
		//============================//
		// Move assignment operator.  //
		//============================//
		Cat& operator=(Cat&&);


		//===============================//
		// Mutators: Needed for the copy //
		// and assignment operators.     //
		//===============================//
		void setTheCat(int, const char*, const char*, const std::string&);
}; // End of the class.

//================================//
// Non-member output operator.    //
//================================//
std::ostream& operator<<(std::ostream&, const Cat&);

//=============================//
// Non-member input operator   //
//=============================//
std::istream& operator>>(std::istream&, Cat&);
