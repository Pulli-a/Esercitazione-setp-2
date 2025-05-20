#include "Gori_func.h"


bool insertPoly(vector<Function *> &f){
	return false;
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