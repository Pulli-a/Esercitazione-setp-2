/*! @file CExponential.h
	@brief A class for exponential functions 
	@author Alessandro Maryni
										\n
	The exponential has the form:		\n
	y = k * b^(cx)						\n
	@note b MUST be a positive value	\n
*/ 

#ifndef _EXPONENTIAL_H
#define _EXPONENTIAL_H

#include "CFunction.h"
#include <iostream>
#include <cmath>
#include <cstring>

/*
La funzione esponenziale (classe Exponential) è formalizzata come  k×bcx, con b > 0

La classe deve quindi prevedere le seguenti variabili membro:  

double b_coeff  	per memorizzare la base b  

double  k_coeff	per memorizzare il coefficiente k  

double  c_coeff	per memorizzare il coefficiente c  
*/

using namespace std;

class Exponential : public Function {

protected: 

double k_coeff;
double b_coeff;
double c_coeff;
		
public:
    
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
    Exponential();
	Exponential(double k, double b, double c);
	Exponential(const Exponential &e);
    ~Exponential();
	/// @}

	/// @name GETTERS AND SETTERS
	/// @{
	double GetKCoeff();
	double GetBCoeff();
	double GetCCoeff();
	double GetValue(double in);

	void SetExponential(double k, double b, double c);
	void SetKCoeff( double k);
	void SetBCoeff( double b);
	void SetCCoeff( double c);
	/// @}

	/// @name OPERATORS 
	/// @{
    Exponential& operator=(const Exponential& e);
	bool operator==(const Exponential& e);
	/// @}

	void Init(const Exponential& e);
	void Reset();

	/// @name DEBUG 
	/// @{
	void Dump();
	/// @}

    
};

#endif
