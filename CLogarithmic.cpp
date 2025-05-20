/*! @file Logarithmic.cpp
	@brief implementation of Logarithmic.h functions 
	@author Mauro Gori
											\n
	Logaritmic has the form:				\n
	y = k * logb(x)							\n
*/ 

#include <iostream>
#include <cmath>
#include <cstring>
#include "CLogarithmic.h"

using namespace std;

///@brief Default constructor
///@note it sets the base = 10 and coefficent = 0 as default
Logarithmic::Logarithmic(){
	SetLogarithmic(10, 0.0);
}

///@brief Copy-Constructor
Logarithmic::Logarithmic(const Logarithmic &l){
	SetLogarithmic(l.b_coeff, l.k_coeff);
}

///@brief Non-Default Constructor
///@param b Base Parameter
///@param k Coefficent Parameter
Logarithmic::Logarithmic(double b, double k){
	SetLogarithmic(b, k);
}

///@brief Default Destructor
Logarithmic::~Logarithmic(){
	//non ho puntatori faccio un eliminazione shallow
}

///@brief Operator= overloading
Logarithmic& Logarithmic::operator=(const Logarithmic& l){
	if(this == &l){
		return *this;
	}else{
		Init(l);
		return *this;
	}
}

///@brief Operator== overloading
bool Logarithmic::operator==(const Logarithmic& l){
	if(k_coeff == l.k_coeff && b_coeff == l.b_coeff){
		return true;
	}else{
		return false;
	}
}

///@brief GetValue returns the y value given an x value
///@param x
///@return y
double Logarithmic::GetValue(double in){
	if(in < 0){
		ErrorMessage("'in' value should be > 0");
		return 0;
	}
	return k_coeff*(log2(in) / log2(b_coeff));
}
///@brief GetCoeffK returns the k coefficent value
///@return k
double Logarithmic::GetKCoeff(){
	return k_coeff;
}
///@brief GetCoeffB returns the b coefficent value
///@return b
double Logarithmic::GetBCoeff(){
	return b_coeff;
}

///@brief sets the coefficent parameter
///@param k
void Logarithmic::SetKCoeff(double k){
	SetLogarithmic( b_coeff , k);
}

///@brief sets the base parameter
///@param b
void Logarithmic::SetBCoeff(double b){
	SetLogarithmic( b , k_coeff);
}

///@brief sets both the base and coefficent parameters, in that order
///@param b
///@param k
void Logarithmic::SetLogarithmic(double b, double k){
	if(b > 0.0 && b != 1){
		b_coeff = b;
	}else{
		ErrorMessage("Cannot set base < 0 or equal to 1,\n\t  b_coef set to 10");
		b_coeff = 10;
	}
	k_coeff = k;
	return;
}
///@brief initializes the logarithmic functions copying a pre-existing object
void Logarithmic::Init(const Logarithmic& l){
	SetLogarithmic(l.k_coeff, l.b_coeff);
}
///@brief resets the logarithmic function to default values
void Logarithmic::Reset(){
	SetLogarithmic(10.0, 0.0);
}

///@brief data dump
void Logarithmic::Dump(){
	cout << k_coeff << "log" << b_coeff << "(x)"<< endl << flush;
}