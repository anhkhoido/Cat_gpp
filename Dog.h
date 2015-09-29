//
// File's name: Dog.h
// Author: Dan Brennan
// Date: 09/28/2015
//
// Description: Definition of a class that
// refers to a Dog and its attributes.
//===========================================
#include <iostream>
#include <string>

using namespace std;

class Dog {
	int age;
	string name;
	string breed;


	public:
		Dog();
		Dog(int, const string, const string);
		~Dog();

		//=====================//
		// Output operator.    //
		//=====================//
		ostream& read(ostream&) const;

		//====================//
		// Copy constructor.  //
		//====================//
		Dog(const Dog&);



		//=====================//
		// Assignment operator //
		//=====================//
	//	Dog& operator=(const Dog&);


}; // End of the class.

//================================//
// Non-member output operator.    //
//================================//
ostream& operator<<(ostream&, const Dog&);
