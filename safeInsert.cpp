#include "safeInsert.h"


bool safeInsert(int &value){
	char str[MAX_STRING_SIZE];
	int try_count = 0;
	char escape = '\0';
	while(try_count < MAX_ATTEMPT){
		scanf("%[^\n]s", &str);
		getchar(); //gets the '\n' still in stdin buffer
		if(strchr(str, ' ') != NULL){
			cout << "[ ERROR ] Expecting only one value" << endl;
		}
		else if(sscanf(str, "%d%c", &value, &escape) !=1){
			cout << "[ ERROR ] expectign an integer" << endl;
			escape = '\0';
		}
		else{
			return true;
		}
		try_count++;
		cout << " [ INFO ] attempts left :  " << MAX_ATTEMPT - try_count << endl;
	}
	cout << "[ ERROR ] too many wrong attempts" << endl;
	cout << "          MAX_ATTEMPT = " << MAX_ATTEMPT << endl;
	return false;
}

bool safeInsert(double &value){
	char str[MAX_STRING_SIZE];
	int try_count = 0;
	char escape = '\0';
	while(try_count < MAX_ATTEMPT){
		scanf("%[^\n]s", &str);
		getchar(); //gets the '\n' still in stdin buffer
		if(strchr(str, ' ') != NULL){
			cout << "[ ERROR ] Expecting only one value" << endl;
		}
		else if(sscanf(str, "%lf%c", &value, &escape) !=1){
			cout << "[ ERROR ] expectign a double" << endl;
			escape = '\0';
		}
		else{
			return true;
		}
		try_count++;
	}
	cout << "[ ERROR ] too many wrong attempts" << endl;
	cout << "          MAX_ATTEMPT = " << MAX_ATTEMPT << endl;
	return false;
}

bool safeInsert(int &value, int from, int to){
	while(1){
		if(!safeInsert(value)) return false;
		if(value >= from && value <= to){
			return true;
		}
		else{
			cout << "[ ERROR ] value should be in range [ " << from << " , " << to << "] " << endl;
		}
	}
	cout << "[ ERROR ] OUT OF BOUNDS" << endl;
	return false;
}

bool safeInsert(double &value, double from, double to){
	while(1){
		if(!safeInsert(value)) return false;
		if(value >= from && value <= to){
			return true;
		}
		else{
			cout << "[ ERROR ] value should be in range [ " << from << " , " << to << "] " << endl;
		}
	}
	cout << "[ ERROR ] OUT OF BOUNDS" << endl;
	return false;
}



bool safeInsert(int &value, int cond_value, condition C){
	bool cond = true;
	do{
		if(!safeInsert(value)) return false;
		switch(C){
			case GT:
			value > cond_value ? cond = false : printf("[ ERROR ] value should be > %d\n", cond_value);
			break;

			case GE:
			value >= cond_value ? cond = false : printf("[ ERROR ] value should be >= %d\n", cond_value);
			break;

			case LT:
			value < cond_value ? cond = false : printf("[ ERROR ] value should be < %d\n", cond_value);
			break;

			case LE:
			value <= cond_value ? cond = false : printf("[ ERROR ] value should be <= %d\n", cond_value);
			break;
		}
	}while(cond);
	return true;
}
	bool safeInsert(double &value, double cond_value , condition C){
	bool cond = true;
	do{
		if(!safeInsert(value)) return false;
		switch(C){
			case GT:
			value > cond_value ? cond = false : printf("[ ERROR ] value should be > %d\n", cond_value);
			break;

			case GE:
			value >= cond_value ? cond = false : printf("[ ERROR ] value should be >= %d\n", cond_value);
			break;

			case LT:
			value < cond_value ? cond = false : printf("[ ERROR ] value should be < %d\n", cond_value);
			break;

			case LE:
			value <= cond_value ? cond = false : printf("[ ERROR ] value should be <= %d\n", cond_value);
			break;
		}
	}while(cond);
	return true;
	}