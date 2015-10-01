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
		~Dog();

		void setName(const string);
		void setBreed(const string);
		void setAge(const int);

	/*	string getName();
		string getBreed();
		int getAge();
*/
		Dog(Dog&);	// copy constructor
		Dog& operator=(const Dog&);

		//=====================//
		// Output operator.    //
		//=====================//
		ostream& read(ostream&) const;
		istream& write(istream& is);

}; // End of the class.

//================================//
// Non-member output operator.    //
//================================//
ostream& operator<<(ostream&, const Dog&);
istream& operator>>(istream&, Dog&);
