/*! @file Interface.cpp
	@brief implementation of Interface.h functions 
	@authors Alessandro Maryni & Mauro Gori
*/ 


#include "Interface.h"
#include "safeInsert.h"

// ##################### MENU FUNCTIONS #####################

/// @brief prints main menu and make the user choose the mode
/// @return returns the  mode, integer from 0 to 5
int menu(){
	int mode = 0;
	int try_num = 0;
	clrscr();
	cout << "### main menu ###" << endl;
	cout << "insert selection and press enter" << endl;
	cout << "0 - Exit menu and program" << endl;
	cout << "1 - visualize function vector" << endl;
	cout << "2 - Insert a function" << endl;
	cout << "3 - Erase a function" << endl;
	cout << "4 - Erase all function" << endl;
	cout << "5 - Select a function to evaluate" << endl;
	if(!safeInsert(mode, 0 , 5)) return -1;

	return mode;
}

///@brief prints menu that explane choices in insertFunction();
///@return selection 
int insertFunctionMenu(){
	int select;
	clrscr();
	cout<<"### function creation wizard ###"<< endl;
	cout<<"0 - return to main menu"<<endl;
	cout<<"1 - create logarithmic function"<<endl;
	cout<<"2 - create polynomial function"<<endl;
	cout<<"3 - create power function"<<endl;
	cout<<"4 - create exponential function"<<endl;
	if(!safeInsert(select, 0, 4)) return -1;
	return select;
}


// ##################### INSERT FUNCTIONS #####################

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

///@brief logarithmic function creator
///@param f reference of pointers to class Function
///@returns true if successful
bool insertLog(vector<Function *> &f){
	double b;
	double k;
	Logarithmic* l;
	l = new Logarithmic;
	clrscr();
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
	l->SetLogarithmic(b, k);
	Function* func = l;
	final_insertion(f, func, "logarithm");
	return true;
}

///@brief polynomial function creation wizard
///@param f reference of pointers to class Function
///@returns true if succesful
///@note inserts in the array of pointers the created function
bool insertPoly(vector<Function *> &f){
	double* c;	//pointer to int array
    int d;		//degree
	Polynomial* p;
	clrscr();
	cout << "### Polynomial Function creation wizard###"<<endl << endl;
	cout << "Polynomial has the form: c0 + c1 * x^1 + ... + c(deg-1) * x^(deg-1)" << endl;
	cout << "insert function degree"<<endl;
	safeInsert(d, 0, GE);
	if(d > 10){
		int is_not_ok = 1;
		cout << "[ WARNING ] you have selected a high poly degree " << endl;
		cout << "Are you sure ? \n[y = 0 / n = 1]" << endl;
		safeInsert(is_not_ok, 0, 1);
		if(is_not_ok){
			cout << "insert function degree" << endl;
			cout << "[ WARNING ] last chance to insert degree before insertion of coefficents" << endl;
			safeInsert(d, 0 , GE);
		}
	}
	c = new double[d + 1];
	for(int i = 0; i < d +1; i++){
		cout<<"insert coefficent of degree: c "<< i << "  out of " << d <<endl;
		safeInsert(c[i]);
	}
	p = new Polynomial(c, d + 1);
	Function* func = p;
	final_insertion(f, func, "polynomial");
	return true;
}

///@brief Power Function creation wizard
///@param f reference of pointers to class Function
///@returns true if successful
///@note inserts in the array of pointers the created function
bool insertPow(vector<Function *> &f){
	double k;
	double e;
	Power* p;
	clrscr();
	cout << "### Power Function creation wizard ###"<< endl << endl;
	cout << "Power has the form: k * x^e" << endl;
	cout << "insert k coefficent" << endl;
	safeInsert(k);
	cout << "Pow = "<< k << "x^e" << endl;
	cout << "insert e coefficent" << endl;
	safeInsert(e);
	p = new Power(k, e);
	Function * func = p;
	final_insertion(f, func, "power");
	return true;
}

///@brief Exponential Function creation wizard
///@param f reference of pointers to class Function
///@returns true if successful
///@note inserts in the array of pointers the created function
bool insertExp(vector<Function *> &f){
	double k;
	double b;
	double c;
	Exponential* e;
	clrscr();
	cout << "### Exponential Function creation wizard ###" << endl << endl;
	cout << "Exponential has the form: k * b^(c * x)" << endl;
	cout << "insert k coefficent" << endl;
	safeInsert(k);
	cout << "Exp = "<<  k <<" * b^(c * x)" << endl;
	cout << "insert b coefficent" << endl;
	safeInsert(b, 0, GT);
	cout << "Exp = "<<  k <<" * " << b << "^(c * x)" << endl;
	cout << "insert c coefficent" << endl;
	safeInsert(c);
	e = new Exponential(k, b ,c);
	Function * func = e;
	final_insertion(f, func, "exponential");
	return true;
}

bool final_insertion(vector<Function *> &f, Function* func, const char* func_name){
	int not_to_list = 0;
	clrscr();
	cout << "### final " << func_name << "###" << endl;
	cout << "f(x) = ";
	func->Dump();
	cout << "add function to list?" << endl;
	cout << "[y = 0 / N = 1]" << endl;
	safeInsert(not_to_list, 0 , 1);
	if(not_to_list){
		delete func;
	}
	else{
		f.push_back(func);
	}
	return true;
}

bool final_erase(vector<Function *> &f, int erase_index){
	int dont_erase = 0;
	clrscr();
	cout << "### function erase ###" << endl;
	cout << "function selected: f(x) = ";
	f[erase_index]->Dump();
	cout << "delete the function ?" << endl;
	cout << "[y = 0 / N = 1]" << endl;
	safeInsert(dont_erase, 0 , 1);
	if(!dont_erase){
		delete f[erase_index];
		f[erase_index] = NULL;
		f.erase(f.begin() + erase_index);
	}
	return true;
}


// ##################### UTILITY FUNCTIONS #####################

///@brief prints list of existing function objects
///@param f reference of pointers to class Function
///@returns true if printed successfully or false if array is empty
bool printFunctionList(vector<Function *> &f){
	int size = f.size();
	clrscr();
	cout << "### Function vector ###" << endl;
	if(f.empty()){
		cout << endl << "[ INFO ] vector is empty " << endl << endl;
		return false;
	}
	else{
		for(int i = 0; i < size; i++){
			cout << i << ":  f(x) = ";
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
	final_erase(f, erase_index);	
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
	return true;
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
		clrscr();
		cout << "### function selected ###" << endl << "f(x) = ";
		f[select_index]->Dump();
		cout << "0 - exit evaluation" << endl;
		cout << "1 - evaluate funciton" << endl;
		if(!safeInsert(mode, 0 , 1)) return false;
		switch(mode)
		{
		case 0:
			return true;

		case 1:
			clrscr();
			cout << "###   ###" << endl;
			cout << "f(x) = ";
			f[select_index]->Dump();
			cout << "insert evaluation point (x = )" << endl;
			safeInsert(x);
			cout << "f("<< x << ") = " << f[select_index]->GetValue(x) << endl;
			safeInsert();
			break;
		}
	}
	return true;
}

// ##################### ESTETIC FUNCTIONS #####################

/// @brief clears the screen
/// @note works ONLY on ANSI machines 
/// more in https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
void clrscr(){
	//What is it doing?
	// \e  -> escape the printf()
	// [1;1H moves cursor to line 1 and column 1 of terminal
	// [2J   erase entire screen
	// [3J   erase saved lines
	printf("\e[1;1H\e[2J\e[3J");
}