// объявление функций и классов для вычисления арифметических выражений
#include "stack.h"
#include <string>
struct token {
	int pr; 
	int flag;
	double p;
	token() {
		pr = -1;
		p = 0;
	}
	token(std::string q, double pp = -1) {
		if (q == "-") {
			flag = 1;
			pr = 1;
		}
		if (q == "+"){
			flag = 2;
			pr = 1;
		}
		if (q == "*") {
			flag = 3;
			pr = 2;
		}
		if (q == "/") {
			flag = 4;
			pr = 2;
		}
		if (q == "sin") {
			flag = 44;
			pr = 3;
		}
		if (q == "cos") {
			flag = 5;
			pr = 3;
		}
		if (q == "log") {
			flag = 6;
			pr = 3;
		}
		if (q == "exp") {
			flag = 7;
			pr = 3;
		}
		if (q == "number") {
			flag = 8;
			pr = 0;
		}
		if (q == "x") {
			flag = 9;
			pr = 0;
		}
		if (q == "y") {
			flag = 10;
			pr = 0;
		}
		if (q == "z"){
			flag = 11;
			pr = 0;
		}
		if (q == "(") {
			flag = 12;
			pr = 6;
		}
		p = pp;
	}
};
class arithmetic {
private:
	Stack<token> q;
public:
	double x, y, z;
	int flag_x, flag_y, flag_z;
	arithmetic(std::string str);
	arithmetic() {
		q = Stack<token>();
		x = 0;
		y = 0;
		z = 0;
		flag_x = flag_y = flag_z = 0;
	}
	double calc();
};
