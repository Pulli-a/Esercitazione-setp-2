#ifndef _SAFE_INSERT_
#define _SAFE_INSERT_

	#include <iostream>
	#include <string.h>

	#define MAX_ATTEMPT 10
	#define MAX_STRING_SIZE 1024

	enum condition{
		GT = 0,
		GE,
		LT,
		LE
	};


	using namespace std;

	bool safeInsert(int &value);
	bool safeInsert(double &value);

	bool safeInsert(int &value, int from, int to);
	bool safeInsert(double &value, double from, double to);
	bool safeInsert(int &value, int cond_value, condition);
	bool safeInsert(double &value, double cond_value , condition);

#endif