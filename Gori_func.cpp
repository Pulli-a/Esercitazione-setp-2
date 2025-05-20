bool insertPoly(vector<Function *> &f){
}
//k * x ^ e
bool insertPow(vector<Function *> &f){
	double k;
	double e;
	Power* p;
	p = new Power;
	cout<<"Power Function creation wizard"<<endl;
	cout<<"insert k coefficent"<<endl;
	cin>>k;
	cout<<"insert e coefficent"<<endl;
	cin>>e;
	p->SetPower(k, e);
	return true;
}
	
bool insertExp(vector<Function *> &f){
	double k;
	double b;
	double c;
	Exponential* e;
	e = new Exponential;
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
	e->SetExponential(k, b, c);
	return true;
	
}