//standard headers
#include <bits/stdc++.h>
#include "stdio.h"

//classes headers
#include "CPolynomial.h"
#include "CExponential.h"
#include "CLogarithmic.h"
#include "Cpower.h"

//program headers
#include "safeInsert.h"
#include "Interface.h"

using namespace std;



/// @brief entry point of program
/// @return 0 or non zero value if errors 
int main(){
	//initializing dinamic array
	vector<Function *> F;

	int mode = 0;

	while(1){
		if((mode = menu()) == -1){
			eraseAllFunctions(F);
			return 1;
		} 
		switch (mode)
		{
		case 0:
			eraseAllFunctions(F); // avoid memory leak
			return 0;
			break;
		
		case 1:
			printFunctionList(F);
			safeInsert();
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
	eraseAllFunctions(F);
	return 1;
}

