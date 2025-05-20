/*! @file CPower.cpp
	@brief Implementation of Power class 
	@authors Alessandro Maryni & Mauro Gori \n
											\n
	Power has the form:						\n
	y = k*x^e								\n
*/ 

#include "CPower.h"

// ############ CONSTRUCTORS AND DESTRUCTORS ############

/// @brief Default constructor, set all parameter to 0
Power::Power() {
	SetPower(.0 , .0);
}

/// @brief param constructor
/// @param k 
/// @param e 
Power::Power(double k, double e){
	SetPower(k, e);
}

/// @brief copy constructor
/// @param p reference to Power object
Power::Power(const Power &p){
	Init(p);
}

/// @brief destructor
Power::~Power(){

}

// ############ GETTERS AND SETTERS ############

/// @brief Returns the value of k_coeff
/// @return k_coeff
double Power::GetKCoeff(){
	return k_coeff;
}

/// @brief Returns the value of E_coeff
/// @return E_coeff
double Power::GetECoeff(){
	return e_coeff;
}


/// @brief Evaluates the Power function in x = in
/// @param in point of Power evaluation
/// @return value of k * in^e
double Power::GetValue(double in){
	return k_coeff * pow(in, e_coeff);
}

/// @brief Set k parameter
/// @param k 
void Power::SetKCoeff( double k){
	SetPower(k, e_coeff);
}

/// @brief Set e parameter
/// @param e 
void Power::SetECoeff( double e){
	SetPower(k_coeff, e);
}


/// @brief Set all coefficients in the Power
/// @param k Power multiplier
/// @param e exponent
void Power::SetPower(double k, double e){
	k_coeff = k;
	e_coeff = e;
}


// ############ OPERATORS ############

/// @brief assign Power to p
/// @param p object to confronting class
/// @return assigned object
Power& Power::operator=(const Power& p){
	Init(p);
	return *this;
}

/// @brief confrotn two Power funcitons
/// @param p 
/// @return true if the two have the same k and e. Else reutrns false
bool Power::operator==(const Power& l){
	if(l.k_coeff != k_coeff) return false;
	else if(l.e_coeff != e_coeff) return false;
	return true;
}

/// @brief Set all param to object p param
/// @param p
void Power::Init(const Power& p){
	SetPower(p.k_coeff, p.e_coeff);
}

/// @brief set all param to 0
void Power::Reset(){
	SetPower(0,0);
}

// ############ DEBUG ############

/// @brief print all params
void Power::Dump(){
	cout << "Dump of Power" << endl;
	cout << k_coeff << "x^" << e_coeff << endl;
}