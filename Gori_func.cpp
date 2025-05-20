#include "Gori_func.h"
#include "safeInsert.h"


bool insertPoly(vector<Function *> &f){
	double* c;	//pointer to int array
    int d;		//degree
	Polynomial* p;
	printf("\e[1;1H\e[2J");
	cout<<"### Polynomial Function creation wizard###"<<endl;
	cout<<"insert function degree"<<endl;
	safeInsert(d, 0, GE);
	c = new double[d + 1];
	for(int i = 0; i < d +1; i++){
		cout<<"insert coefficent of degree: "<<i<<endl;
		safeInsert(c[i]);
	}
	
	p = new Polynomial(c, d + 1);
	f.push_back(p);
	return true;
}
//k * x ^ e
bool insertPow(vector<Function *> &f){
	double k;
	double e;
	Power* p;
	printf("\e[1;1H\e[2J");
	cout<<"### Power Function creation wizard ###"<<endl;
	cout<<"insert k coefficent"<<endl;
	safeInsert(k);
	cout<<"insert e coefficent"<<endl;
	safeInsert(e);
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
	cout<<"### Exponential Function creation wizard ###"<<endl;
	cout<<"insert k coefficent"<<endl;
	safeInsert(k);
	cout<<"insert c coefficent"<<endl;
	safeInsert(c);
	cout<<"insert b coefficent"<<endl;
	safeInsert(b, 0, GT);
	e = new Exponential(k, b ,c);
	f.push_back(e);
	return true;
	
}