#include "Gori_func.h"
#include "safeInsert.h"


bool insertPoly(vector<Function *> &f){
	double* c;	//pointer to int array
    int d;		//degree
	Polynomial* p;
	printf("\e[1;1H\e[2J");
	cout << "### Polynomial Function creation wizard###"<<endl << endl;
	cout << "Polynomial has the form: c0 + c1 * x^1 + ... + c(deg-1) * x^(deg-1)" << endl;
	cout << "insert function degree"<<endl;
	safeInsert(d, 0, GE);
	if(d > 10){
		int is_not_ok = 1;
		cout << "[ WARNING ] you have selected a high poly degree " << endl;
		cout << "Are you shure ? \n[y = 0 / n = 1]" << endl;
		safeInsert(is_not_ok, 0, 1);
		if(is_not_ok){
			cout << "[ WARNING ] last chance to insert degree before insertion of coefficents" << endl;
			safeInsert(d, 0 , GE);
		}
	}
	c = new double[d + 1];
	for(int i = 0; i < d +1; i++){
		cout<<"insert coefficent of degree: c"<< i << "out of " << d <<endl;
		safeInsert(c[i]);
	}
	
	p = new Polynomial(c, d + 1);
	f.push_back(p);
	return true;
}


bool insertPow(vector<Function *> &f){
	double k;
	double e;
	Power* p;
	printf("\e[1;1H\e[2J");
	cout << "### Power Function creation wizard ###"<< endl << endl;
	cout << "Power has the form: k * x^e" << endl;
	cout << "insert k coefficent" << endl;
	safeInsert(k);
	cout << "Pow = "<< k << "x^e" << endl;
	cout << "insert e coefficent" << endl;
	safeInsert(e);
	cout << "Pow = "<< k << "x^" << e << endl;
	p = new Power(k, e);
	f.push_back(p);
	return true;
}
	
bool insertExp(vector<Function *> &f){
	double k;
	double b;
	double c;
	Exponential* e;
	printf("\e[1;1H\e[2J");
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
	cout << "Exp = "<<  k <<" * " << b << "^("<< c << " * x)" << endl;
	e = new Exponential(k, b ,c);
	f.push_back(e);
	return true;
	
}