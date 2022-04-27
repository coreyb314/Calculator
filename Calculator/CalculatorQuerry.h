#pragma once
#include<iostream>;
#include<string>;
#include<ctype.h>;
#include<AlgebraicFunctions.h>;

//OPERATORS:
//
// A+B	A-B
// A*B	A/B
// A^(B) A%B
// A!
// log_A(B)
// ln(B)
// 
// sin(B)	cos(B)
// tan(B)	sec(B)
// csc(B)	cot(B)
// 
//CURRENTLY DOES NOT SUPPORT NEGATIVE VALUES

struct BinaryCalculatorQuerry {
public:
	//constructor to initialize BinaryCalculatorQuerry from string
	BinaryCalculatorQuerry(std::string s) : lh(getlh(s)), op(getop(s)), rh(getrh(s)) {}



	//function to isolate lh side from input string
	double getlh(std::string s) {
		int sz = s.size();
		std::string result = "";

		//iterate through the string
		int i = 0;
		

		if (getop(s) == "log") {

			i += 4;

			//Enter negative sign if present.
			if (s.compare(i, 1, "-") == 0) {
				result += s[i];
				i++;
			}

			
			while (  (isdigit(s[i]) || (s.compare((i), 1, ".") == 0))  &&  (i!=sz) ) {
				result += s[i];

				i++;
			}
			return std::stof(result);
		}

		//Enter negative sign if present.
		if (s.compare(i, 1, "-") == 0) {
			result += s[i];
			i++;
		}
		

		while ((isdigit(s[i]) || (s.compare((i), 1, ".") == 0)) && (i != sz)) {
			result += s[i];
			i++;
		}

		//If no numbers at beginning, set LH to 1 (except for log which is taken care of above)
		if (isalpha(s[i])) {
			if (s.compare(0, 1, "-") == 0) {
				return -1;
			}
			else {
				return 1;
			}

		}

		return std::stof(result);
	}

	//Function to isolate operator from input string
	std::string getop(std::string s) {
		
		int sz = s.size();
		int i = 0;

		if (s.compare(0, 1, "-") == 0) {
			i++;
		}
		
		//Check if a character is a digit or a decimal. If so, increment i!
		while ((isdigit(s[i]) || (s.compare((i), 1, ".") == 0)) && (i != sz)) {
			i++;
		}


		//Temporary string to hold first character of operator
		std::string result;
		

		//assign opperators for +,-,*,/,^,!,%
		if (!isalpha(s[i])) {
			result = s[i];
		}
		//assign opperators for letter operators
		else while (isalpha(s[i])) {
			result += s[i];
			i++;
		}
		return result;
		
	}

	//function to isloate rh side from input string
	double getrh(std::string s) {		
		int sz = s.size();
		int i = 0;
		std::string result = "";

		//iterate through negative sign if present.
		if (s.compare(i, 1, "-") == 0) {
			i++;
		}

		//iterate through LH side
		while ((isdigit(s[i]) || (s.compare((i), 1, ".") == 0)) && (i != sz)) {
			i++;
		}

		//iterate through operator
		if (isalpha(s[i])) {
			while (!((s.compare((i), 1, "(")) == 0)) {
				i++;
			}
			i++;
		}
		else {
			i++;
		}
		
		//Add RH side to result

		//Add negative if present
		if (s.compare(i, 1, "-") == 0) {
			result += s[i];
			i++;
		}

		
		while ((isdigit(s[i]) || (s.compare((i), 1, ".") == 0)) && (i != sz)) {
			result += s[i];
			i++;
		}
		if ((result.compare(0, 1, "") == 0)) {
			return 0;
		}
		else {
			return std::stof(result);
		}
	}

	long double result() {
		double lo = this->lh;
		double ro = this->rh;
		std::string oper = this->op;
		
		int intoper = 0;

		if (oper.compare("+") == 0) {
			intoper = 1;
		}
		else if (oper.compare("-") == 0) {
			intoper = 2;
		}
		else if (oper.compare("*") == 0) {
			intoper = 3;
		}
		else if (oper.compare("/") == 0) {
			intoper = 4;
		}
		else if (oper.compare("^") == 0) {
			intoper = 5;
		}
		else if (oper.compare("%") == 0) {
			intoper = 6;
		}
		else if (oper.compare("sin") == 0) {
			intoper = 7;
		}
		else if (oper.compare("cos") == 0) {
			intoper = 8;
		}
		else if (oper.compare("tan") == 0) {
			intoper = 9;
		}
		else if (oper.compare("sec") == 0) {
			intoper = 10;
		}
		else if (oper.compare("csc") == 0) {
			intoper = 11;
		}
		else if (oper.compare("cot") == 0) {
			intoper = 12;
		}
		else if (oper.compare("log") == 0) {
			intoper = 13;
		}
		else if (oper.compare("ln") == 0) {
			intoper = 14;
		}
		else if (oper.compare("!") == 0) {
			intoper = 15;
		}
		


		switch (intoper) {
		case 1:
			return(lo + ro);
			break;
		case 2:
			return(lo - 0);
			break;
		case 3:
			return(lo * ro);
			break;
		case 4:
			return(lo / ro);
			break;
		case 5:
			return(pow(lo, ro));
			break;
		case 6:
			return(CBremainder(lo, ro));
			break;
		case 7:
			return(lo*sin(ro));
			break;
		case 8:
			return(lo*cos(ro));
			break;
		case 9:
			return(lo*tan(ro));
			break;
		case 10:
			return(lo*sec(ro));
			break;
		case 11:
			return(lo*csc(ro));
			break;
		case 12:
			return(lo*cot(ro));
			break;
		case 13:
			return(log(ro, lo));
			break;
		case 14:
			return(ln(ro));
		case 15:
			return(factorial(lh));
		default:
			std::cout << " Error, try again!" << std::endl;
		}

	

		
	
	}

	void print() {
		std::cout << " LH side is: " << this->lh << std::endl;
		std::cout << " Opperator is: " << this->op << std::endl;
		std::cout << " RH side is: " << this->rh <<std::endl;
	}

private:
	//LH data member
	double lh = 0;
	//RH data member
	double rh = 0;
	//Operator data member
	std::string op;
	

};