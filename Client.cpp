//
// File's name: .cpp
// Author: Dan Brennan
// Date: 09/28/2015
//
// Description: The client that calls
// the Dog and any other objects. This file
// contains the main function of the program.
//==============================================

#include <iostream>
#include "Dog.h"

int main() {

	string nm, br;
	int a;

	cout << "The Dog Customizer" << endl;

	cout << "Type the name of your Dog: ";
	cin >> nm;
	cout << "Its age: ";
	cin >> a;
	cout << "Breed: ";
	cin >> br;


	Dog toto(a, nm, br);

	//========================//
	// Input data for the Dog.//
	//========================//

	cout << "\nDog\'s fact sheet" << endl;
	cout << "---------------------------" << endl;

	//=======================================//
	// Display the inormation about the Dog. //
	//=======================================//
	cout << toto;


	return 0;
}
