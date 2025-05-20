#include "CPolynomial.h"
#include "CExponential.h"
#include "CLogarithmic.h"
#include "Cpower.h"

#include <bits/stdc++.h>
using namespace std;

#define MAX_ATTEMPT 10

int menu();
bool insertFunction(vector<Function *> &f);
int safeInsertion(int low, int high);
int insertFunctionMenu();
bool insertLog(vector<Function *> f);

/// TODO: implement funcitons

bool InsertPoly(vector<Function *> &f);
bool InsertPow(vector<Function *> &f);
bool InsertExp(vector<Function *> &f);


/*
0 – Esci dal menù 

1 – Visualizza la lista delle funzioni  

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
			///TODO: visualizza lista funzioni
			break;

		case 2:
			///TODO: Inserisci una funzione 
			break;

		case 3:
			///TODO: Elimina una funzione
			break;

		case 4:
			///TODO: Elimina tutte le funzioni 
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
	while(1){
		///TODO: clear the screen and put menu on top using weird printf
		cout << "### main menu ###" << endl;
		cout << "insert selection and press enter" << endl;
		cout << "0 - Exit menu  and program" << endl;
		cout << "1 - visualize function list" << endl;
		cout << "2 - Insert a function" << endl;
		cout << "3 - Erase a function" << endl;
		cout << "4 - Erase all function" << endl;
		cout << "5 - Select a function" << endl;
		if((mode = safeInsertion(0 , 5)) == -1) return -1;
	}
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
		InsertLog(f);
		break;

	case 2:
		InsertPoly(f);
		break;

	case 3:
		InsertPow(f);
		break;
	
	case 4:
		InsertExp(f);
		break;
	
	default:
		break;
	}
	
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
	
}
int insertFunctionMenu(){
	int select;
	cout<<"### function creation wizard ###"<< endl;
	cout<<"0 - return to main menu"<<endl;
	cout<<"1 - create logarithmic function"<<endl;
	cout<<"2 - create polynomial function"<<endl;
	cout<<"3 - create power function"<<endl;
	cout<<"4 - create exponential function"<<endl,
	return safeInsertion(0, 4);
}

