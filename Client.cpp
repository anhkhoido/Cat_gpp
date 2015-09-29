//
// File's name: Client.cpp
// Author: Anh Khoi Do
// Date: 09/28/2015
//
// Description: The client that calls
// the cat and any other objects. This file
// contains the main function of the program.
//==============================================

#include <iostream>
#include "Cat.h"

int main() {

	Cat harry;

	std::cout << "The Cat Customizer\n" << std::endl;
	
	//========================//
	// Input data for the cat.//
	//========================//
	std::cin >> harry;

	std::cout << "\nCat\'s fact sheet" << std::endl;
	std::cout << "---------------------------" << std::endl;

	//=======================================//
	// Display the inormation about the cat. //
	//=======================================//
	std::cout << harry;


	return 0;
}
