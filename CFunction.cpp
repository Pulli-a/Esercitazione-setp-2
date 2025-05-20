/*! @file CFunction.cpp
	@brief Implementation of Function class 
	@author Alessandro Maryni

	Details.
*/ 

#include "CFunction.h"

/// @brief writes an error message 
/// @param string message to be printed
void Function::ErrorMessage(const char *string) {
	
	cout << endl << "[ ERROR ] ";
	cout << string << endl << flush;

}

/// @brief writes a warning message 
/// @param string message to be printed
void Function::WarningMessage(const char *string) {
	
	cout << endl << "[ WARNING ] ";
	cout << string << endl << flush;

}
