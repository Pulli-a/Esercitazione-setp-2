/*! @file safeInsert.cpp
	@brief implementation of safeInsert.h functions 
	@authors Alessandro Maryni & Mauro Gori

	@note safeInsert uses ANSI escape codes
*/ 

#include "safeInsert.h"
bool scp = false; //saved cursor position 

/// @brief handle the (press enter) insertion
/// @return true
void safeInsert(){
	cout << "(press enter to contiune)" << endl;
	char str[MAX_STRING_SIZE] = {0};
	scanf("%[^\n]s", str);
	getchar();
}

/// @brief Makes shure that the input is an integer
/// @param value reference to integer value desidered
/// @return false in case of an error
bool safeInsert(int &value ){
	if(!scp){
		printf("\e[s"); // saves the cursor current position
		scp = true;
	}
	char str[MAX_STRING_SIZE] = {0};
	int try_count = 0;
	char escape = '\0';
	while(try_count < MAX_ATTEMPT){
		printf("\e[u\e[2K"); // load curso to previous saved position
		scanf("%[^\n]s", str);
		printf("\e[J"); // clear screen from cursor to end
		getchar(); //gets the '\n' still in stdin buffer
		if(strlen(str) == 0){
			cout << "[ ERROR ] Input value is NULL" << endl;
		}
		else if(strchr(str, ' ') != NULL){
			cout << "[ ERROR ] Expecting only one value" << endl;
		}
		else if(sscanf(str, "%d%c", &value, &escape) !=1){
			cout << "[ ERROR ] expectign an integer" << endl;
			escape = '\0';
		}
		else{
			scp = false;
			return true;
		}
		try_count++;
		cout << " [ INFO ] attempts left :  " << MAX_ATTEMPT - try_count << endl;
	}
	cout << "[ ERROR ] too many wrong attempts" << endl;
	cout << "          MAX_ATTEMPT = " << MAX_ATTEMPT << endl;
	return false;
}

/// @brief Makes shure that the input is a double
/// @param value reference to double value desidered
/// @return false in case of an error
bool safeInsert(double &value){
	if(!scp){
		printf("\e[s");
		scp = true;
	}
	char str[MAX_STRING_SIZE];
	int try_count = 0;
	char escape = '\0';
	while(try_count < MAX_ATTEMPT){
		printf("\e[u\e[2K");
		scanf("%[^\n]s", str);
		printf("\e[J");
		getchar(); //gets the '\n' still in stdin buffer
		if(strchr(str, ' ') != NULL){
			cout << "[ ERROR ] Expecting only one value" << endl;
		}
		else if(sscanf(str, "%lf%c", &value, &escape) !=1){
			cout << "[ ERROR ] expectign a double" << endl;
			escape = '\0';
		}
		else{
			scp = false;
			return true;
		}
		try_count++;
	}
	cout << "[ ERROR ] too many wrong attempts" << endl;
	cout << "          MAX_ATTEMPT = " << MAX_ATTEMPT << endl;
	return false;
}

/// @brief Makes shure that the input is an integer between 'from' & 'to'
/// @param value reference to integer value
/// @param from inferior bound
/// @param to superior bound
/// @return false in case of an error
bool safeInsert(int &value, int from, int to){
	if(!scp){
		printf("\e[s");
		scp = true;
	}
	int try_count = 0;
	while(try_count < MAX_ATTEMPT){
		if(!safeInsert(value)) return false;
		if(value >= from && value <= to){
			return true;
			scp = false;
		}
		try_count++;
		cout << "[ ERROR ] value should be in range [ " << from << " , " << to << "] " << endl;
		cout << " [ INFO ] attempts left :  " << MAX_ATTEMPT - try_count << endl;
		scp = true;
	}
	cout << "[ ERROR ] too many wrong attempts" << endl;
	cout << "          MAX_ATTEMPT = " << MAX_ATTEMPT << endl;
	scp = false;
	return false;
}


/// @brief Makes shure that the input is a double between 'from' & 'to'
/// @param value reference to double value
/// @param from inferior bound
/// @param to superior bound
/// @return false in case of an error
bool safeInsert(double &value, double from, double to){
	if(!scp){
		printf("\e[s");
		scp = true;
	}
	int try_count = 0;
	while(try_count < MAX_ATTEMPT){
		if(!safeInsert(value)) return false;
		if(value >= from && value <= to){
			scp = false;
			return true;
		}
		try_count++;
		cout << "[ ERROR ] value should be in range [ " << from << " , " << to << "] " << endl;
		cout << " [ INFO ] attempts left :  " << MAX_ATTEMPT - try_count << endl;
		scp = true;
	}
	cout << "[ ERROR ] too many wrong attempts" << endl;
	cout << "          MAX_ATTEMPT = " << MAX_ATTEMPT << endl;
	scp = false;
	return false;
}

/// @brief makes the given input meet the condition given
/// @param value reference to value
/// @param cond_value 
/// @param C the condition, could be GT, GE, LT, LE
/// @return false in case of an error
bool safeInsert(int &value, int cond_value, condition C){
	if(!scp){
		printf("\e[s");
		scp = true;
	}
	bool cond = true;
	int try_count = 0;
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
		scp = cond;
		try_count++;
	}while(cond && try_count < MAX_ATTEMPT);
	if(try_count == MAX_ATTEMPT){
		cout << "[ ERROR ] too many wrong attempts" << endl;
		cout << "          MAX_ATTEMPT = " << MAX_ATTEMPT << endl;
		scp = false;
		return false;
	}
	scp = false;
	return true;
}

/// @brief makes the given input meet the condition given
/// @param value reference to value
/// @param cond_value 
/// @param C the condition, could be GT, GE, LT, LE
/// @return false in case of an error
bool safeInsert(double &value, double cond_value , condition C){
	if(!scp){
		printf("\e[s");
		scp = true;
	}
	bool cond = true;
	int try_count = 0;
	do{
		if(!safeInsert(value)) return false;
		switch(C){
			case GT:
			value > cond_value ? cond = false : printf("[ ERROR ] value should be > %lf\n", cond_value);
			break;

			case GE:
			value >= cond_value ? cond = false : printf("[ ERROR ] value should be >= %lf\n", cond_value);
			break;

			case LT:
			value < cond_value ? cond = false : printf("[ ERROR ] value should be < %lf\n", cond_value);
			break;

			case LE:
			value <= cond_value ? cond = false : printf("[ ERROR ] value should be <= %lf\n", cond_value);
			break;
		}
		scp = cond;
		try_count++;
	}while(cond && try_count < MAX_ATTEMPT);
	if(try_count == MAX_ATTEMPT){
		cout << "[ ERROR ] too many wrong attempts" << endl;
		cout << "          MAX_ATTEMPT = " << MAX_ATTEMPT << endl;
		scp = false;
		return false;
	}
	scp = false;
	return true;
}