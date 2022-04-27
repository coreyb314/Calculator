#include<iostream>;
#include "LongQuerry.h";
#include "LinearAlgebra.h";

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

                                                                              
                         
                                            


int main() {
	
	cout << "     _______________________________                                                                                                                                                 " << endl;
	cout << "     |+++++++++++++++++++++++++++++|            ________         ____        __         ________     __     __   __             ____    __________    _______    _______             " << endl;
	cout << "     |+++++++++++++++++++++++++++++|           |   _____\\       /    \\      |  |       |   _____\\   |  |   |  | |  |           /    \\  |___    ___|  /  ___  \\  |  ___  \\      " << endl;
	cout << "     |+++|                     |+++|           |  |            /  /\\  \\     |  |       |  |         |  |   |  | |  |          /  /\\  \\     |  |     |  /   \\  | |  |  \\  \\    " << endl;
	cout << "     |+++| Calculator by Corey |+++|           |  |           /  /__\\  \\    |  |       |  |         |  |   |  | |  |         /  /__\\  \\    |  |     |  |   |  | |  |__/  /       " << endl;
	cout << "     |+++|                     |+++|           |  |          /  /_______\\   |  |       |  |         |  |   |  | |  |        /  /_______\\   |  |     |  |   |  | |  |__  \\    	 " << endl;
	cout << "     |+++|         Enter query |+++|           |  |______   /  /      \\  \\  |  |_____  |  |______   |  |___|  | |  |____   /  /      \\  \\  |  |     |  \\___/  | |  |  \\  \\    " << endl;
	cout << "     |+++| Find Result         |+++|           |________/  /__/        \\__\\ |________| |________/    \\_______/  |_______| /__/        \\__\\ |__|      \\_______/  |__|   \\__\\  " << endl;
	cout << "     |+++|_____________________|+++|                                                                ________   ___    ___                                                          " << endl;
	cout << "     |+++++++++++++++++++++++++++++|                                                               |   ___  \\  \\  \\  /  /                                                          " << endl;
	cout << "     |-----------------------------|                                                               |  |___| |   \\  \\/  /                                                           " << endl;
	cout << "     |  _____   _______   _______  |                                                               |   _____/    \\    /                                                            " << endl;
	cout << "     | | TRIG| | CLEAR | | ENTER | |                                                               |  |  \\  \\     \\  /                                                             " << endl;
	cout << "     | |_____| |_______| |_______| |                                                               |  |__/  |     |  |                                                              " << endl;
	cout << "     |  ___    ___    ___     ___  |                                                               |________/     |__|                                                              " << endl;
	cout << "     | | 1 |  | 2 |  | 3 |   | / | |                                           ________    _______     _______      _________  ___    ___                                       " << endl;
	cout << "     | |___|  |___|  |___|   |___| |                                          |   _____\\  /  ___  \\   |  ___  \\    |   ______| \\  \\  /  /                                       " << endl;
	cout << "     |  ___    ___    ___     ___  |                                          |  |       |  /   \\  |  |  |  \\  \\   |  |______   \\  \\/  /                                        " << endl;
	cout << "     | | 4 |  | 5 |  | 6 |   | X | |                                          |  |       |  |   |  |  |  |__/  /   |   ______|   \\    /                                         " << endl;
	cout << "     | |___|  |___|  |___|   |___| |                                          |  |       |  |   |  |  |  |__  \\    |  |           \\  /                                          " << endl;
	cout << "     |  ___    ___    ___     ___  |                                          |  |______ |  \\___/  |  |  |  \\  \\   |  |______     |  |                                           " << endl;
	cout << "     | | 7 |  | 8 |  | 9 |   | - | |                                          |________/  \\_______/   |__|   \\__\\  |_________|    |__|                                           " << endl;
	cout << "     | |___|  |___|  |___|   |___| |    " << endl;
	cout << "     |  ___    ___    ___     ___  |    " << endl;
	cout << "     | |Fnc|  | 0 |  | . |   | + | |    " << endl;
	cout << "     | |___|  |___|  |___|   |___| |    " << endl;
	cout << "     |_____________________________|   \n " << endl;


	cout << " To enter linear algebra mode, type 'LinAlg.' To enter algebra mode, typle 'Alg.'\n" << endl;
	
	cout << " Algebra Instructions:" << endl;
	cout << " Use the following formats for entering algebraic expressions:" << endl;
	cout << " A+B		A-B		A*B		A/B		A^B		A%B		A!" << endl;
	cout << " sin(B)		cos(B)		tan(B)		sec(B)		csc(B)		cot(B)" << endl;
	cout << " log_A(B)	ln(B)" << endl;
	cout << " Order of operations is not automatic - use brackets." << endl;
	cout << " No brackets are necessary around entire expressions\n" << endl;
	cout << " Linear Algebra Instructions:" << endl;
	cout << " To enter a matrix, seperate entries with commas and rows with semicolons." << endl;
	cout << " Please ensure all rows are of equal length." << endl;
	cout << " For instance, a 3X3 matrix will have the entry form 'a,b,c;d,e,f;g,h,i;'" << endl;

	LinearAlgebra:
	while (cin) {
		string s;
		getline(cin, s);
		
		if ((s == "LinAlg")||(s=="linalg")) {
			goto LinearAlgebra;
		}
		if ((s == "Alg") || (s == "alg")) {
			goto Algebra;
		}

		Matrices M(s);
		cout << "Your input was:" << endl;
		M.print();
	}

	Algebra:
	while (cin) {
		string s;
		getline(cin, s);

		if ((s == "LinAlg") || (s == "linalg")) {
			goto LinearAlgebra;
		}
		if ((s == "Alg")||(s=="alg")) {
			goto Algebra;
		}

		LongQuerry LQ(s);
		long double answer = LQ.evaluate();
		cout << " Result:" << answer << "\n" << endl;
	}
	
	return 0;
}


