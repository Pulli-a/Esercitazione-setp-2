///TODO: add Interface.cpp and Interface.h
///TODO: add doxygen comments to files
///TODO: add doxygen comments to safeInsert.cpp
///TODO: add try_count to safeInsert(range) and (cond) for both int and double
///TODO: polish code and program
///TODO: non so se mi piace l'aggiunta dei coeff ad ogni inserimento

#include "CPolynomial.h"
#include "CExponential.h"
#include "CLogarithmic.h"
#include "Cpower.h"
#include "safeInsert.h"

#include "stdio.h"
#include <bits/stdc++.h>
#include "Gori_func.h"

using namespace std;


int menu();
bool insertFunction(vector<Function *> &f);

bool printFunctionList(vector<Function *> &f);
bool eraseFunction(vector<Function *> &f);
bool eraseAllFunctions(vector<Function *> &f);
bool selectFuncion(vector<Function *> &f);

int insertFunctionMenu();
bool insertLog(vector<Function *> &f);




/*
0 – Esci dal menù 

1 – Visualizza la vectora delle funzioni  

2 – Inserisci una funzione  

3 – Elimina una funzione  

4 – Elimina tutte le funzioni  

5 – Seleziona una funzione  
*/

/// @brief entry point of program
/// @return 0 or non zero value if errors 
int main(){

	vector<Function *> F;
	int mode = 0;
	///TODO: scrivi una spiegazione migliore, sono stanco
	printf("\e[1;1H\e[2J");
	cout << "This program allows you to handle different function via a list." << endl;
	cout << "you can add function to list, print current list, erase a function or all functions or select a function," << endl;
	cout << "when a function is selected you can evaluate it at some points [doing f(x) = ]." << endl;
	cout << "initially the list will be empty so you should start by adding a function to the list." << endl;
	cout << "(press enter to start the program)" << endl;
	getchar();

	while(1){
		if((mode = menu()) == -1) return 1;
		switch (mode)
		{
		case 0:
			return 0;
			break;
		
		case 1:
			printFunctionList(F);
			cout << "(press enter to continue)" << endl;
			getchar();
			break;

		case 2:
			insertFunction(F);
			break;

		case 3:
			eraseFunction(F);
			break;

		case 4:
			eraseAllFunctions(F);
			break;

		case 5:
			selectFuncion(F);
			break;
		default:
			cout << "[ ERROR ] invalid mode value: " << mode << endl;
			break;
		}
	}
	cout << "[ ERRRO ] OUT OF BOUDNS " << endl;
	return 1;
}

/// @brief prints main menu and make the user choose the mode
/// @return returns the  mode, integer from 0 to 5
int menu(){
	int mode = 0;
	printf("\e[1;1H\e[2J");
	cout << "### main menu ###" << endl;
	cout << "insert selection and press enter" << endl;
	cout << "0 - Exit menu  and program" << endl;
	cout << "1 - visualize function vector" << endl;
	cout << "2 - Insert a function" << endl;
	cout << "3 - Erase a function" << endl;
	cout << "4 - Erase all function" << endl;
	cout << "5 - Select a function" << endl;
	if(!safeInsert(mode, 0 , 5)) return -1;

	return mode;
}


///@brief allow to insert function to funciton pointer array f
///@param f reference of pointers to class Functionion 
///@returns true if successful or false if fails.
bool insertFunction(vector<Function *> &f){
	int mode = 0;
	double coeff = 0;
	if((mode = insertFunctionMenu()) == -1) return false;
	switch (mode)
	{
	case 0:
		return true;
		break;
	case 1:
		insertLog(f);
		break;

	case 2:
		insertPoly(f);
		break;

	case 3:
		insertPow(f);
		break;
	
	case 4:
		insertExp(f);
		break;
	
	default:
		break;
	}
	return true;	
}


///@brief prints list of existing function objects
///@param f reference of pointers to class Function
///@returns true if printed successfully or false if array is empty
bool printFunctionList(vector<Function *> &f){
	int size = f.size();
	printf("\e[1;1H\e[2J");
	cout << "### Function vector ###" << endl;
	if(f.empty()){
		cout << endl << "[ INFO ] vector is empty " << endl << endl;
		return false;
	}
	else{
		for(int i = 0; i < size; i++){
			cout << i << ":   ";
			f[i]->Dump();
		}
	}
	return true;
}
///@brief deletes a specific function from the array
///@param f reference of pointers to class Function
///@returns true if deleted successfully or false if failed. 
bool eraseFunction(vector<Function *> &f){
	int erase_index = 0;
	int max_index = f.size();
	if(!printFunctionList(f)){
		return false;
	}
	cout << "insert the index of function to delete" << endl;
	if(!safeInsert(erase_index, 0, max_index-1)) return false;
	delete f[erase_index];
	f[erase_index] = NULL;
	f.erase(f.begin() + erase_index);
	
	return true;
}

///@brief deletes all objects from the array
///@param f reference of pointers to class Function
///@returns true if deleted successfully or false if failed. 
bool eraseAllFunctions(vector<Function *> &f){
	cout << "[ INFO ] Erasing all functions in list" << endl;
	if(!f.empty()){
		while(!f.empty()){
			delete f[f.size()-1];
			f.erase(f.end());
		}
	}
	///TODO: metti messaggi più belli
	cout << "[ INFO ] success" << endl;
	return true;
}

///@brief logarithmic function creator
///@param f reference of pointers to class Function
///@returns true if successful
bool insertLog(vector<Function *> &f){
	double b;
	double k;
	Logarithmic* l;
	l = new Logarithmic;
	printf("\e[1;1H\e[2J");
	cout <<"### logarithmic function creation wizard ###"<< endl << endl;
	cout << "Logarithmic has the form: k * logb(x)" << endl << endl;
	cout<<"insert k coefficent"<<endl;
	safeInsert(k);
	cout << " Log: "<< k << " * logb(x)" << endl;
	while(1){
		cout<<"insert base coefficent \nbase coefficent must be > 0 and not 1"<<endl;
		safeInsert(b, 0 ,GT);
		if(b != 1){
			break;
		}else{
			cout<<"[ ERROR ] b coefficent should be not equal to 1"<< endl;
		}
	}
	cout << k << " * log"<< b <<"(x)" << endl;
	l->SetLogarithmic(b, k);
	Function* func = l;
	f.push_back(func);
	return true;
}
///@brief prints menu to select function to create
///@returns selection 
int insertFunctionMenu(){
	int select;
	printf("\e[1;1H\e[2J");
	cout<<"### function creation wizard ###"<< endl;
	cout<<"0 - return to main menu"<<endl;
	cout<<"1 - create logarithmic function"<<endl;
	cout<<"2 - create polynomial function"<<endl;
	cout<<"3 - create power function"<<endl;
	cout<<"4 - create exponential function"<<endl;
	if(!safeInsert(select, 0, 4)) return -1;
	return select;
}

///@brief allows the user to pick a specific function from the object array
///@param f reference of pointers to class Function
///@returns true if successful or false if fails
bool selectFuncion(vector<Function *> &f){
	int select_index = 0;
	int mode = 0;
	double x;
	int max_index = f.size();
	if(!printFunctionList(f)){
		return false;
	}
	cout << "--- Select a function ---" << endl;
	cout << "value should be between 0 and " << max_index - 1 << endl;
	if(!safeInsert(select_index, 0, max_index-1)) return false;
	while(1){
		printf("\e[1;1H\e[2J");
		cout << "### function selected ###" << endl;
		f[select_index]->Dump();
		cout << "0 - exit evaluation" << endl;
		cout << "1 - evaluate funciton" << endl;
		if(!safeInsert(mode, 0 , 1)) return false;
		cout << "###   ###" << endl;
		switch(mode)
		{
		case 0:
			return true;

		case 1:
			cout << "insert evaluation point (x = )" << endl;
			safeInsert(x);
			cout << "f("<< x << ") = " << f[select_index]->GetValue(x) << endl;
			cout << "(press enter to continue)" << endl;
			getchar();
			break;
		}
	}
	return true;
}