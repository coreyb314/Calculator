#pragma once
#include<iostream>;
#include<string>;
#include<vector>;
#include "CalculatorQuerry.h";


struct LongQuerry {
public:
	LongQuerry(std::string st) : s(st) {}
	double evaluate() {
		std::string s = this->s;
		s += "]";
		s.insert(0, "[");
		int lbrackets = 0;
		int sz = s.size();
		int i = 0;

		//count number of "[" we have - corresponds to number of expressions!
		while (i < sz) {
			if (s.compare(i, 1, "[") == 0) {
				lbrackets++;
			}
			i++;
		}

		//Isolate and replace each binary expression
		for (int j = 0; j < lbrackets; j++) {
			//indices to correspond to beginning and end of binary expressions
			int begb = 0;
			int endb = 0;
			int k = 0;

			//find first ]
			while (k < sz) {
				if (s.compare(k, 1, "]") == 0) {
					endb = k;
					break;
				}
				else {
					k++;
				}
			}

			//find corresponding [
			int l = endb;
			while (l > 0) {
				l--;
				if (s.compare(l, 1, "[") == 0) {
					begb = l;
					break;
				}
			}

			//replace range denoted by begb & endb with result of binary querry
			std::string inputCQ = "";
			for (int i = (begb+1); i < endb; i++) {
				inputCQ += s[(i)];
			}
			BinaryCalculatorQuerry CQ(inputCQ);
			std::string term = std::to_string(CQ.result());

			s.replace(begb, (inputCQ.size()+2), term);
		}
		return std::stof(s);
	}

private:
	std::string s;
};
