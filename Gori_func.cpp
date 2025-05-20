#include "Gori_func.h"


bool insertPoly(vector<Function *> &f){
	double* c;	//pointer to int array
    int d;		//degree
	Polynomial* p;
	cout<<"Polynomial Function creation wizard"<<endl;
	while(1){
		cout<<"insert function degree"<<endl;
		cin>>d;
		///TODO: LEVA QUESTA MERDA E METTICI SAFE INSERT QUESTO ROMPERà IL PROGRAMMA
		if(d < 0){
			cout<<"[ ERROR ] degree must be at least 0"<<endl;
		}else{
			break;
		}
	}
	c = new double[d + 1];
	for(int i = 0; i < d +1; i++){
		cout<<"insert coefficent of degree: "<<i<<endl;
		///TODO: LEVA STO CIN E METTI SAFE INSERT
		cin>>c[i];
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
	
	cout<<"Power Function creation wizard"<<endl;
	cout<<"insert k coefficent"<<endl;
	cin>>k;
	cout<<"insert e coefficent"<<endl;
	cin>>e;
	p = new Power(k, e);
	f.push_back(p);
	return true;
}
	
bool insertExp(vector<Function *> &f){
	double k;
	double b;
	double c;
	Exponential* e;
	cout<<"insert k coefficent"<<endl;
	cin>>k;
	cout<<"insert c coefficent"<<endl;
	cin>>c;
	while(1){
		cout<<"insert b coefficent"<<endl;
		cin>>b;
		if(b > 0){
			break;
		}
		else{
			cout<<"[ ERROR ] b coefficent must be > 0"<<endl;
		}
	}
	e = new Exponential(k, b ,c);
	f.push_back(e);
	return true;
	
}