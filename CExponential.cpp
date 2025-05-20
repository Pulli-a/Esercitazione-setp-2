/*! @file CExponential.cpp
	@brief Implementation of Exponential class 
	@author Alessandro Maryni
										\n
	The exponential has the form:		\n
	y = k * b^(cx)						\n
*/ 

#include "CExponential.h"

// ############ CONSTRUCTORS AND DESTRUCTORS ############

/// @brief Default constructor
Exponential::Exponential() {
	SetExponential(.0 , 1., .0);
}

/// @brief constructor with all exponential parameters
/// @param k exponential multiplier
/// @param b base of the exponential, MUST be a positive value
/// @param c exponent multiplier
Exponential::Exponential(double k, double b, double c){
	SetExponential(k, b, c);
}

/// @brief copy constructor
/// @param e reference to Exponential object
Exponential::Exponential(const Exponential &e){
	Init(e);
}

/// @brief destructor
Exponential::~Exponential(){

}

// ############ GETTERS AND SETTERS ############

/// @brief Returns the value of k_coeff
/// @return k_coeff
double Exponential::GetKCoeff(){
	return k_coeff;
}

/// @brief Returns the value of B_coeff
/// @return B_coeff
double Exponential::GetBCoeff(){
	return b_coeff;
}

/// @brief Returns the value of C_coeff
/// @return C_coeff
double Exponential::GetCCoeff(){
	return c_coeff;
}

/// @brief Evaluates the Exponential function in x = in
/// @param in point of Exponential evaluation
/// @return value of k*b^(C in)
double Exponential::GetValue(double in){
	return k_coeff * pow( b_coeff, (c_coeff * in));
}

/// @brief Set k parameter
/// @param k 
void Exponential::SetKCoeff( double k){
	SetExponential(k, b_coeff, c_coeff);
}

/// @brief Set b parameter
/// @param b 
void Exponential::SetBCoeff( double b){
	SetExponential(k_coeff, b, c_coeff);
}

/// @brief set c parameter
/// @param c 
void Exponential::SetCCoeff( double c){
	SetExponential(k_coeff, b_coeff, c);
}


/// @brief Set all coefficients in the exponential
/// @param k exponential multiplier
/// @param b base of the exponential, MUST be a positive value
/// @param c exponent multiplier
/// @note if a b is a negative value the base will be set to 0
void Exponential::SetExponential(double k, double b, double c){
	k_coeff = k;
	if(b > 0){
		b_coeff = b;
	}else { 
		ErrorMessage("B coeff should be > 0,\n\t  b_coeff set to 1"); 
		b_coeff = 1;
	}
	c_coeff = c;
}


// ############ OPERATORS ############

/// @brief assign exponential to e
/// @param e object to confronting class
/// @return assigned object
Exponential& Exponential::operator=(const Exponential& e){
	Init(e);
	return *this;
}

/// @brief confrotn two exponential funcitons
/// @param e 
/// @return true if the two have the same k , b , and c. Else false
bool Exponential::operator==(const Exponential& e){
	if(e.k_coeff != k_coeff) return false;
	else if(e.b_coeff != b_coeff) return false;
	else if(e.c_coeff != c_coeff) return false;

	return true;
}

/// @brief Set all param to object e param
/// @param e 
void Exponential::Init(const Exponential& e){
	SetExponential(e.k_coeff, e.b_coeff, e.c_coeff);
}

/// @brief set all param to 0
void Exponential::Reset(){
	SetExponential(0,0,0);
}

// ############ DEBUG ############

/// @brief print all params
void Exponential::Dump(){
	cout << k_coeff << "*" << b_coeff << "^(" << c_coeff << " x)" << endl;
}