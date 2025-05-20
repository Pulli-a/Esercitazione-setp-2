/*! @file CPower.h
	@brief A class for Power functions 
	@author Alessandro Maryni

	The Power has the form:
	y = k*x^e
*/ 

/*
La funzione potenza (classe Power) è formalizzata come  k×xe 

La classe deve quindi prevedere le seguenti variabili membro:  

double  k_coeff per memorizzare il coefficiente k 

double  e_coeff	per memorizzare l’esponente 
*/

#ifndef _POWER_H
#define _POWER_H

#include "CFunction.h"
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class Power : public Function {

protected: 

double k_coeff;
double e_coeff;
		
public:
    
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
    Power();
	Power(double k, double e);
	Power(const Power &p);
    ~Power();
	/// @}

	/// @name GETTERS AND SETTERS
	/// @{
	double GetKCoeff();
	double GetECoeff();
	
	double GetValue(double in);

	void SetPower(double k, double e);
	void SetKCoeff( double k);
	void SetECoeff( double e);
	/// @}

	/// @name OPERATORS 
	/// @{
    Power& operator=(const Power& p);
	bool operator==(const Power& p);
	/// @}

	void Init(const Power& p);
	void Reset();

	/// @name DEBUG 
	/// @{
	void Dump();
	/// @}

    
};

#endif
