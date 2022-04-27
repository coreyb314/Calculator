#pragma once
#include<iostream>;



//NEXT UP:
//Inverse trig functions!
// Hyperbolic trig!
// 
//

const long double pi = 3.141592653589793238462643383;
const long double e = 2.7182818284590452353602874713527;

//Takes only integer exponent
float intpow(float operand, int exponent) {
	int count = 1;
	int ncount = -1;
	float result = operand;

	if (exponent == 0) {
		return 1;
	}
	else if (exponent > 0) {
		while (count != exponent) {
			result = result * operand;
			count++;
		}
		return result;
	}
	else {
		while (ncount != exponent) {
			result = result * operand;
			ncount--;
		}
		result = 1 / result;
		return result;
	}
}

//takes only integer operand
double factorial(long int operand) {
	int boundary = operand;
	double result = operand;
	int count = 1;

	if (operand == 0) {
		return 1;
	}

	if (operand < 0) {
		std::cout << " Error: operand must be positive" << std::endl;
		return 0;
	}

	while (count != boundary) {
		result = result * (operand - 1);
		operand = operand - 1; 
		count++;
	}
	return result;
}

//Gives remainder of any two floats
float CBremainder(float num, float denom) {
	float fquotient = num / denom;
	int iquotient = num / denom;
	float result = 0;
	
	//determines how to calculate remainder based upon sign of quotient
	if (fquotient > 0) {
		
		//calculate remainder
		if (iquotient < fquotient) {
			result = (fquotient - iquotient)*denom;
		}
		else {
			result = (fquotient - iquotient + 1)*denom; 
		}
	}
	else if(fquotient < 0){
		if (iquotient < fquotient) {
			result = (iquotient - fquotient)*denom;
		}
		else {
			result = (iquotient - fquotient - 1)*denom;
		}
	}
	else if (num == 0) {
		result = 0;
	}
	else {
		std::cout << "invalid entry" << std::endl;
		result = 0;
	}
	return result;
}

//nth root, assuming n and opperand is positive, and n is a positive integer!
double nthroot(double operand, int root) {
	double guess = operand / root;
	float upperbound = 1.00001;
	float lowerbound = 0.99999;


	while ((intpow(guess, root) / operand) > upperbound || (intpow(guess, root) / operand) < lowerbound) {
		
		//If guess is too high, reduce it!
		if ((intpow(guess, root) / operand) < 1) {
			guess = guess * 1.5;
		}
		else if ((intpow(guess, root) / operand) > 1) {
			guess = guess * 0.5;
		}
	}
	return guess;
}

//Raises the operand to the exponent. Floats allowed.
//Only use positive operands!
//Precision levels (1 and 2) correspond to number of decimals in exponent read.
//Level 2 is quite slow
double pow(float operand, float exponent, int precision = 1) {
		
	if (precision > 2) {
		precision = 2;
	}
	else if (precision < 1) {
		precision = 1;
		}

	float decexponent = 0;			//Decimal part of exponent
	int intexponent = exponent;		//integer part of exponent

	double intresult = 0;
	double decresult = 0;
	double result = 0;
	
	//Should make sure integer part of exponent is smaller in magnitude than the total exponent
	if ((exponent > 0) && (intexponent > exponent)) {
		intexponent = intexponent - 1;
	}
	else if ((exponent < 0) && (intexponent < exponent)) {
		intexponent = intexponent + 1;
	}
	else if (exponent == 0) {
		return 1;
	}

	//initialize decimal part of exponent
	decexponent = exponent - intexponent;

	//compute int and decimal parts seperately
	intresult = intpow(operand, intexponent);
	
	//compute decimal part...
	//decresult switch statement - switching based upon requested permission
	int case1exp = 0;
	int case2exp = 0;
	double temp = 0;

	
	switch (precision) {
	case 1:
		case1exp = ((10 * decexponent)+0.1);
		temp = intpow(operand, case1exp);
		decresult = nthroot(temp, 10);
		break;

	case 2:
		case2exp = ((decexponent * 100)+0.1);
		temp = intpow(operand, case2exp);
		decresult = nthroot(temp, 100);
		break;

	default:
		std::cout << "invalid precission" << std::endl;
		break;
	}
	result = (intresult * decresult);
	return result;
}


//Trigonometric functions - take any input in radians
//Precission corresponds to number of terms in taylor series to calculate function - max is 20!
float sin(float inputoperand, int precision = 15) {
	if (precision > 20) {
		precision = 20;
	}

	//Takes input, and puts it between 0 and 2pi
	float operand = inputoperand;
	while (operand > 6.283185307179586 || operand < 0) {
		if (operand < 0) {
			operand = operand + 6.283185307179586;
		}
		else {
			operand = operand - 6.283185307179586;
		}
	}
	
	float result = 0;
	int count = 0;

	double num1, num2, num3;
	while (count < precision) {

		//terms of Mclauren series
		num1 = intpow(-1, count);
		num2 = intpow(operand, ((2 * count) + 1));
		num3 = factorial(2 * count + 1); //Denominator

		//current value of sin(operand)
		result += ((num1 * num2) / num3);
		count++;
	}
	return result;
}

float cos(float inputoperand, int precision = 15) {
	if (precision > 20) {
		precision = 20;
	}

	//Takes input, and puts it between 0 and 2pi
	float operand = inputoperand;
	while (operand > 6.283185307179586 || operand < 0) {
		if (operand < 0) {
			operand = operand + 6.283185307179586;
		}
		else {
			operand = operand - 6.283185307179586;
		}
	}


	float result = 0;
	int count = 0;

	double num1, num2, num3;
	while (count < precision) {

		//terms of Mclauren series
		num1 = intpow(-1, count);
		num2 = intpow(operand, (2 * count));
		num3 = factorial(2 * count);

		//current value of cos(operand)
		result += ((num1 * num2) / num3);
		count++;
	}
	return result;
}

float tan(float inputoperand, int precision = 15) {
	if (precision > 20) {
		precision = 20;
	}

	//Takes input, and puts it between 0 and 2pi
	float operand = inputoperand;
	while (operand > 6.283185307179586 || operand < 0) {
		if (operand < 0) {
			operand = operand + 6.283185307179586;
		}
		else {
			operand = operand - 6.283185307179586;
		}
	}

	float result = sin(operand, precision) / cos(operand, precision);
	return result;
}

float sec(float inputoperand, int precision = 15) {
	if (precision > 20) {
		precision = 20;
	}

	//Takes input, and puts it between 0 and 2pi
	float operand = inputoperand;
	while (operand > 6.283185307179586 || operand < 0) {
		if (operand < 0) {
			operand = operand + 6.283185307179586;
		}
		else {
			operand = operand - 6.283185307179586;
		}
	}
	float result = 1 / cos(operand, precision);
	return result;
}

float csc(float inputoperand, int precision = 15) {
	if (precision > 20) {
		precision = 20;
	}

	//Takes input, and puts it between 0 and 2pi
	float operand = inputoperand;
	while (operand > 6.283185307179586 || operand < 0) {
		if (operand < 0) {
			operand = operand + 6.283185307179586;
		}
		else {
			operand = operand - 6.283185307179586;
		}
	}
	float result = 1 / sin(operand, precision);
	return result;
}

float cot(float inputoperand, int precision = 15) {
	if (precision > 20) {
		precision = 20;
	}

	//Takes input, and puts it between 0 and 2pi
	float operand = inputoperand;
	while (operand > 6.283185307179586 || operand < 0) {
		if (operand < 0) {
			operand = operand + 6.283185307179586;
		}
		else {
			operand = operand - 6.283185307179586;
		}
	}
	float result = 1 / tan(operand, precision);
	return result;
}

float ln(float operand) {
	float guess = 0;
	float check = 0;
	float jump = 0;
	float tempjump = 0;


	if (operand < 0) {
		std::cout << " Error: operand must be positive" << std::endl;
		return 0;
	}

	if (operand > 1) {
		guess = operand;
		jump = guess / 2;

		check = (pow(e, guess) / operand);
		while (check < 1) {
			guess += jump;
			check = (pow(e, guess) / operand);
		}

		while ((check < 0.999) || (check > 1.001)) {
			if (check < 1) {
				guess += jump;
				tempjump = jump;
				jump = (tempjump / 2);
			}
			else if (check > 1) {
				guess -= jump;
				tempjump = jump;
				jump = (tempjump / 2);
				
			}
			else {}
			check = (pow(e, guess) / operand);
			
		}
	}
	else if (operand < 1) {
		guess = -operand;
		jump = guess / 2;

		check = pow(e, guess) / operand;

		while (check > 1) {
			guess += jump;
			check = (pow(e, guess) / operand);
		}

		while (check < 0.9999 || check > 1.0001) {
			if (check < 1) {
				guess -= jump;
				tempjump = jump;
				jump = (tempjump / 2);
			}
			else if (check > 1) {
				guess += jump;
				tempjump = jump;
				jump = (tempjump / 2);
			}
			else {}
			check = pow(e, guess) / operand;
		}
	}
	else if (operand == 1) {
		return 0;
	}
	
	return guess;
}

double log(float operand, float base) {
	if (base < 0) {
		std::cout << " Error: base must be positive" << std::endl;
		return 0;
	}
	if (operand < 0) {
		std::cout << " Error: operand must be positive" << std::endl;
		return 0;
	}

	double result = (ln(operand) / ln(base));
	return result;
}