#pragma once
#include<iostream>;
#include<vector>;
#include<string>;
#include<sstream>;



// Introduction to Matrix Usage!
// 
// Creating a matrix
//		Matrices M = Matrices.Make(string s)
//		Use commas to seperate entries, semicolons to seperate rows
//			ie for the matrix
//				1	2	3
//				4	5	6
//				7	8	9
//			string s should equal "1,2,3;4,5,6;7,8,9;"
// 
// Accessing a matrix
//		Matrices.Matrix
// 
// Printing a matrix
//		print(Matrices M)
// 
// 




using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::istringstream;

//No need to define copy control, right??

struct Matrices {
public:
	//Constructor
	Matrices(string s) : Matrix(MakeMatrix(s)) {}

	//Function to take string and make matrix
	std::vector<std::vector<float>> MakeMatrix(string s) {
		std::vector<std::vector<float>> OutputMatrix;
		string stringentry = "";

		//index variable for matrix - access rows
		int i = 0;
		int j = 0; 

		std::vector<float> row;

		for (int k = 0; k < s.size(); k++) {
			if (s.compare(k, 1, ",") == 0) {
				
				row.push_back(std::stof(stringentry));
				stringentry = "";
				j++; 
			}
			else if (s.compare(k, 1, ";") == 0) {
				row.push_back(std::stof(stringentry));
				OutputMatrix.push_back(row);
				row.clear();
				stringentry = "";
				j = 0;
				i++;
			}
			else {
				stringentry += s[k];
			}
		}
		return OutputMatrix;
	}
	
	

	//function to print a matrix from a Matrices object
	void print() {
		std::vector<std::vector<float>> M = this->Matrix;
		for (int i = 0; i < M.size(); i++) {
			for (int j = 0; j < M[0].size(); j++) {
				std::cout << M[i][j] << "  ";
			}
			std::cout << std::endl;
		}
	}




private:
	//member object that holds the matrix
	std::vector<std::vector<float>> Matrix;
	





	//member function to add column from vector
	//member function to add row from vector
	//member function to read column into vector
	//member function to read row into vector
	//memeber functions for each standard matrix operation
		//row rescalling
		//row swapping
		//row combination
	//member function to multiply matrices
		//overloaded to multiply matrix with vector?
	//memeber function to transpose matrix
	//member function to take inverse of matrix
	//member function to calculate determinant


};



