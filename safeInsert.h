/*! @file SafeInsert.h
	@brief Declaration of safeInsert.cpp functions
	@authors Alessandro Maryni & Mauro gori

	@subsection SafeInsert.h
	Safe insert should contain all User Imput functions \n
	in order to be sure that all data are the correct \n
	type and lenght.

	@note  Templatatisation
	I would have loved to make it a template but \n
	it's not possible since there is a type specifier \n
	in a sscanf(). 
*/ 


#ifndef _SAFE_INSERT_
#define _SAFE_INSERT_

	#include <iostream>
	#include <string.h>

	using namespace std;

	#define MAX_ATTEMPT 10
	#define MAX_STRING_SIZE 1024

	enum condition{
		GT = 0,  //Greater than to
		GE,		 //Greater equal to
		LT,		 //Less than to
		LE		 //Less equal to
	};

	void safeInsert();
	bool safeInsert(int &value);
	bool safeInsert(double &value);

	bool safeInsert(int &value, int from, int to);
	bool safeInsert(double &value, double from, double to);
	bool safeInsert(int &value, int cond_value, condition);
	bool safeInsert(double &value, double cond_value , condition);

#endif