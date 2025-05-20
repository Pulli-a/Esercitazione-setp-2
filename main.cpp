#include "CPolynomial.h"
#include "CExponential.h"
#include "CLogarithmic.h"
#include "Cpower.h"

#include <bits/stdc++.h>
#include "Gori_func.h"

using namespace std;

#define MAX_ATTEMPT 10

int menu();
bool insertFunction(vector<Function *> &f);

bool printFunctionList(vector<Function *> &f);
bool eraseFunction(vector<Function *> &f);
bool eraseAllFunctions(vector<Function *> &f);

int safeInsertion(int low, int high);
int insertFunctionMenu();
bool insertLog(vector<Function *> f);


/// TODO: implement funcitons



/*
0 – Esci dal menù 

1 – Visualizza la vectora delle funzioni  

2 – Inserisci una funzione  

3 – Elimina una funzione  

4 – Elimina tutte le funzioni  

5 – Seleziona una funzione  
*/

int main(){
	//initializing dinamic array
	vector<Function *> F;

	int mode = 0;

	while(1){
		if((mode = menu()) == -1) return 1;
		switch (mode)
		{
		case 0:
			return 0;
			break;
		
		case 1:
			printFunctionList(F);
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
			///TODO: Seleziona una funzione 
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
	int try_num = 0;

	///TODO: clear the screen and put menu on top using weird printf
	cout << "### main menu ###" << endl;
	cout << "insert selection and press enter" << endl;
	cout << "0 - Exit menu  and program" << endl;
	cout << "1 - visualize function vector" << endl;
	cout << "2 - Insert a function" << endl;
	cout << "3 - Erase a function" << endl;
	cout << "4 - Erase all function" << endl;
	cout << "5 - Select a function" << endl;
	if((mode = safeInsertion(0 , 5)) == -1) return -1;

	return mode;
}


/*

function indexes
0 exit
1 log
2 poly
3 pow
4 exp

*/

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
		//insertPoly(f);
		break;

	case 3:
		//insertPow(f);
		break;
	
	case 4:
		//insertExp(f);
		break;
	
	default:
		break;
	}
	return true;	
}

int safeInsertion(int low, int high){
	int mode = 0;
	int max_try = 0;
	while(1){
		if(scanf("%d", &mode) != 1){
			cout << "[ ERROR ] mode should be a integer" << endl << flush;
		}
		else if(mode >= low && mode <= high){
			return mode;
		}
		max_try++;
		cout << "[ ERROR ] mode should be from 0 to 5" << endl;
		if(max_try > MAX_ATTEMPT){
			cout << "[ ERROR ] exceeded max menu attempts, exiting the program" << endl;
			return -1;
		}
	}
}

bool printFunctionList(vector<Function *> &f){
	int size = f.size();
	cout << "### Function vector ###" << endl;
	if(f.empty()){
		cout << "[ INFO ] vector is empty " << endl;
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

bool eraseFunction(vector<Function *> &f){
	int erase_index = 0;
	int max_index = f.size();
	if(!printFunctionList(f)){
		return false;
	}
	if((erase_index = safeInsertion(0, max_index)) == -1 ) return false;
	delete f[erase_index];
	f.erase(f.begin() + erase_index);
	
	return true;
}


bool eraseAllFunctions(vector<Function *> &f){
	if(!f.empty()){
		while(!f.empty()){
			delete f[f.size()-1];
			f.erase(f.end());
		}
	}
	return true;
}

bool insertLog(vector<Function *> f){
	int b;
	int k;
	Logarithmic* l;
	l = new Logarithmic;
	cout<<"logarithmic function creation wizard"<<endl;
	while(1){
		cout<<"insert base coefficent /nbase coefficent must be > 0 and not 1"<<endl;
		cin>>b;
		if(b > 0 && b != 1){
			break;
		}else{
			cout<<"[ ERROR ] invalid b coefficent value"<<endl;
		}
	}
	cout<<"insert k coefficent"<<endl;
	cin>>k;
	l->SetLogarithmic(b, k);
	f.push_back(l);
	return true;
}

int insertFunctionMenu(){
	int select;
	cout<<"### function creation wizard ###"<< endl;
	cout<<"0 - return to main menu"<<endl;
	cout<<"1 - create logarithmic function"<<endl;
	cout<<"2 - create polynomial function"<<endl;
	cout<<"3 - create power function"<<endl;
	cout<<"4 - create exponential function"<<endl;
	return safeInsertion(0, 4);
}

