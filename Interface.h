/*! @file Interface.h
	@brief Declaration of Interface functions
	@authors Alessandro Maryni & Mauro gori

	@mainpage Interface
	This header contains the declaration of funtion needed to create and handle \n
	a vector of pointer to Function Classes (in CFuntion.h) \n
	En example is in main.cpp
	@note This header depends on safeInsert.h and safeInsert.cpp on top of Function classes
*/ 

#ifndef INTERFACE_H
#define INTERFACE_H

	#include "CPolynomial.h"
	#include "CExponential.h"
	#include "CLogarithmic.h"
	#include "Cpower.h"
	

	#include <bits/stdc++.h>

	/// @name Menu functions
	/// @{ 
	int menu();
	int insertFunctionMenu();
	/// @}

	/// @name Inesrt functions
	/// @{
	bool insertFunction(vector<Function *> &f);
	bool insertLog(vector<Function *> &f);
	bool insertPoly(vector<Function *> &f);
	bool insertPow(vector<Function *> &f);
	bool insertExp(vector<Function *> &f);
	bool final_insertion(vector<Function *> &f, Function* func, const char* func_name);
	/// @}
	
	
	/// @name Utility functions
	/// @{
	bool printFunctionList(vector<Function *> &f);
	bool eraseFunction(vector<Function *> &f);
	bool eraseAllFunctions(vector<Function *> &f);
	bool selectFuncion(vector<Function *> &f);
	bool final_erase(vector<Function *> &f, int erase_index);
	/// @}

	/// @name estetic functions
	/// @{
	void clrscr();
	/// @}

#endif