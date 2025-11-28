// реализация функций и классов для вычисления арифметических выражений
#include "arithmetic.h"
#include <stdexcept>
#include <stdlib.h> 
#include <string>
#include<iostream>
arithmetic::arithmetic(std::string str):q(0) {
	flag_x = flag_y = flag_z = 0;
	x = y = z = 0;
	int v = 0;
	int i = 0;
	std::string t = "";
	Stack<token> w(0);
	if (0 == str.size()) {
		this->q = Stack<token>(0);
	}
	else {
		if (str[i] == '-') {
			v = 1;
		}
		if ((((str[i] - '0' > 0) && (str[i] - '0' <= 9)) || (str[i] == '(') || (str[i] == '0') || (str[i] == 'x')
			|| (str[i] == 'y') || (str[i] == 'z') || (str[i] == 'x') || (str[i] == 's')) || (str[i] == 'c') || (str[i] == 'l')
			|| (str[i] == 'e')) {
			v = 2;
		}

	}
	while (i < str.size()) {
		if (str[i] == 'x') { flag_x = 1; }
		if (str[i] == 'y') { flag_y = 1; }
		if (str[i] == 'z') { flag_z = 1; }
		switch (v) {
		case 1:
			if (str[i] == '-') {
				t += str[i];
				v = 2;
				if (i+1 == str.size()) { 
					std::string M = "Invalid input " + std::to_string(i);
					throw std::invalid_argument(M);
				}
				if (!((str[i + 1] - '0' > 0) && (str[i] - '0' <= 9))) {
					w.Push(token("-"));
				}
			}
			else {
				std::string M = "Invalid input " + std::to_string(i);
				throw std::invalid_argument(M);
			}
			break;
		case 2:
			switch (str[i]) {
			case 'x':
				q.Push(token("x"));
				v = 8;
				break;
			case 'y':
				q.Push(token("y"));
				v = 8;
				break;
			case 'z':
				q.Push(token("z"));
				v = 8;
				break;
			case '0':
				v = 3;
				t += str[i];
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				v = 4;
				t += str[i];
				break;
			case 's':
				if ((str[i + 1] == 'i') && (str[i + 2] == 'n') && (str[i + 3] == '(')) {
					t = "";
					i += 4;
					int kl = 0;
					while ((kl >= 0) && (i != str.size())) {
						if (str[i] == '(') { kl++; }
						else {
							if (str[i] == ')') { kl--; }
						}
						t += str[i];
						i++;
					}
					t.pop_back();
					if ((i == str.size()) && (kl > 0)) {
						std::string M = "Invalid input " + std::to_string(i);
						throw std::invalid_argument(M);
					}
					else {
						i--;
						auto ww = arithmetic(t);
						Stack<token> www;
						while (!(ww.q.IsEmpty())) {
							www.Push(ww.q.Pop());
						}
						while (!www.IsEmpty()) {
							q.Push(www.Pop());
						}
						q.Push(token("sin"));
						t = "";
						flag_x = flag_x || ww.flag_x;
						flag_y = flag_y || ww.flag_y;
						flag_z = flag_z || ww.flag_z;
					}
				}
				else {
					std::string M = "Invalid input " + std::to_string(i);
					throw std::invalid_argument(M);
				}
				v = 8;
				break;
			case 'c':
				if ((str[i + 1] == 'o') && (str[i + 2] == 's') && (str[i + 3] == '(')) {
					t = "";
					i += 4;
					int kl = 0;
					while ((kl >= 0) && (i != str.size())) {
						if (str[i] == '(') { kl++; }
						else {
							if (str[i] == ')') { kl--; }
						}
						t += str[i];
						i++;
					}
					t.pop_back();
					if ((i == str.size()) && (kl > 0)) { throw std::invalid_argument("Invalid input"); }
					else {
						i--;
						auto ww = arithmetic(t);
						Stack<token> www;
						while (!(ww.q.IsEmpty())) {
							www.Push(ww.q.Pop());
						}
						while (!www.IsEmpty()) {
							q.Push(www.Pop());
						}
						q.Push(token("cos"));
						t = "";
						flag_x = flag_x || ww.flag_x;
						flag_y = flag_y || ww.flag_y;
						flag_z = flag_z || ww.flag_z;
					}
				}
				else {
					std::string M = "Invalid input " + std::to_string(i);
					throw std::invalid_argument(M);
				}
				v = 8;
				break;
			case 'l':
				if ((str[i + 1] == 'o') && (str[i + 2] == 'g') && (str[i + 3] == '(')) {
					t = "";
					i += 4;
					int kl = 0;
					while ((kl >= 0) && (i != str.size())) {
						if (str[i] == '(') { kl++; }
						else {
							if (str[i] == ')') { kl--; }
						}
						t += str[i];
						i++;
					}
					t.pop_back();
					if ((i == str.size()) && (kl > 0)) { throw std::invalid_argument("Invalid input"); }
					else {
						i--;
						auto ww = arithmetic(t);
						Stack<token> www;
						while (!(ww.q.IsEmpty())) {
							www.Push(ww.q.Pop());
						}
						while (!www.IsEmpty()) {
							q.Push(www.Pop());
						}
						q.Push(token("log"));
						t = "";
						flag_x = flag_x || ww.flag_x;
						flag_y = flag_y || ww.flag_y;
						flag_z = flag_z || ww.flag_z;
					}
				}
				else {
					std::string M = "Invalid input " + std::to_string(i);
					throw std::invalid_argument(M);
				}
				v = 8;
				break;
			case 'e':
				if ((str[i + 1] == 'x') && (str[i + 2] == 'p') && (str[i + 3] == '(')) {
					t = "";
					i += 4;
					int kl = 0;
					while ((kl >= 0) && (i != str.size())) {
						if (str[i] == '(') { kl++; }
						else {
							if (str[i] == ')') { kl--; }
						}
						t += str[i];
						i++;
					}
					t.pop_back();
					if ((i == str.size()) && (kl > 0)) {
						std::string M = "Invalid input " + std::to_string(i);
						throw std::invalid_argument(M);
					}
					else {
						i--;
						auto ww = arithmetic(t);
						Stack<token> www;
						while (!(ww.q.IsEmpty())) {
							www.Push(ww.q.Pop());
						}
						while (!www.IsEmpty()) {
							q.Push(www.Pop());
						}
						q.Push(token("exp"));
						t = "";
						flag_x = flag_x || ww.flag_x;
						flag_y = flag_y || ww.flag_y;
						flag_z = flag_z || ww.flag_z;
					}
				}
				else {
					std::string M = "Invalid input " + std::to_string(i);
					throw std::invalid_argument(M);
				}
				v = 8;
				break;
			case '(':
				v = 2;
				w.Push(token("("));
				break;
			default:
				std::string M = "Invalid input " + std::to_string(i);
				throw std::invalid_argument(M);
			}

			break;
		case 3:
			switch (str[i]) {
			case '.':
				v = 6;
				t += str[i];
				break;
			default:
				std::string M = "Invalid input " + std::to_string(i);
				throw std::invalid_argument(M);
			}
			break;
		case 4:
			switch (str[i]) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				v = 4;
				t += str[i];
				break;
			case '+':
				v = 2;
				if (t != "") {
					q.Push(token("number", std::stod(t)));
				}
				t = "";
				while ((!w.IsEmpty()) && (w.Check().pr <= 2) && (w.Check().pr >= 1)) {
					q.Push(w.Pop());
				}
				w.Push(token("+"));
				break;
			case '-':
				v = 2;
				if (t != "") {
					q.Push(token("number", std::stod(t)));
				}
				t = "";
				while ((!w.IsEmpty()) && (w.Check().pr <= 2) && (w.Check().pr >= 1)) {
					q.Push(w.Pop());
				}
				w.Push(token("-"));
				break;
			case '*':
				v = 2;
				if (t != "") {
					q.Push(token("number", std::stod(t)));
				}
				t = "";
				while ((!w.IsEmpty()) && (w.Check().pr <= 2) && (w.Check().pr >= 2)) {
					q.Push(w.Pop());
				}
				w.Push(token("*"));
				break;
			case '/':
				v = 2;
				if (t != "") {
					q.Push(token("number", std::stod(t)));
				}
				t = "";
				while ((!w.IsEmpty()) && (w.Check().pr <= 2) && (w.Check().pr >= 2)) {
					q.Push(w.Pop());
				}
				w.Push(token("/"));
				break;
			case ')':
				v = 8;
				if (t != "") {
					q.Push(token("number", std::stod(t)));
				}
				t = "";
				while ((!w.IsEmpty()) && (w.Check().flag != 12)) {
					q.Push(w.Pop());
				}
				if (w.Check().flag == 12) {
					w.Pop();
				}
				break;
			case '.':
				v = 6;
				t += str[i];
				break;
			default:
				std::string M = "Invalid input " + std::to_string(i);
				throw std::invalid_argument(M);
			}
			break;
		case 6:

			switch (str[i]) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				v = 7;
				t += str[i];
				break;
			default:
				std::string M = "Invalid input " + std::to_string(i);
				throw std::invalid_argument(M);
			}
			break;
		case 7:
			switch (str[i]) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				v = 7;
				t += str[i];
				break;
			case '+':
				v = 2;
				if (t != "") {
					q.Push(token("number", std::stod(t)));
				}
				t = "";
				while ((!w.IsEmpty()) && (w.Check().pr <= 2) && (w.Check().pr >= 1)) {
					q.Push(w.Pop());
				}
				w.Push(token("+"));
				break;
			case '-':
				v = 2;
				if (t != "") {
					q.Push(token("number", std::stod(t)));
				}
				t = "";
				while ((!w.IsEmpty()) && (w.Check().pr <= 2) && (w.Check().pr >= 1)) {
					q.Push(w.Pop());
				}
				w.Push(token("-"));
				break;
			case '*':
				v = 2;
				if (t != "") {
					q.Push(token("number", std::stod(t)));
				}
				t = "";
				while ((!w.IsEmpty()) && (w.Check().pr <= 2) && (w.Check().pr >= 2)) {
					q.Push(w.Pop());
				}
				w.Push(token("*"));
				break;
			case '/':
				v = 2;
				if (t != "") {
					q.Push(token("number", std::stod(t)));
				}
				t = "";
				while ((!w.IsEmpty()) && (w.Check().pr <= 2) && (w.Check().pr >= 2)) {
					q.Push(w.Pop());
				}
				w.Push(token("/"));
				break;
			case ')':
				v = 8;
				if (t != "") {
					q.Push(token("number", std::stod(t)));
				}
				t = "";
				while ((!w.IsEmpty()) && (w.Check().flag != 12)) {
					q.Push(w.Pop());
				}
				if (w.Check().flag == 12) {
					w.Pop();
				}
				break;
			default:
				std::string M = "Invalid input " + std::to_string(i);
				throw std::invalid_argument(M);
			}
			break;
		case 8:
			switch (str[i]) {
			case '+':
				v = 2;
				if (t != "") {
					q.Push(token("number", std::stod(t)));
				}
				t = "";
				while ((!w.IsEmpty()) && (w.Check().pr <= 2) && (w.Check().pr >= 1)) {
					q.Push(w.Pop());
				}
				w.Push(token("+"));
				break;
			case '-':
				v = 2;
				if (t != "") {
					q.Push(token("number", std::stod(t)));
				}
				t = "";
				while ((!w.IsEmpty()) && (w.Check().pr <= 2) && (w.Check().pr >= 1)) {
					q.Push(w.Pop());
				}
				w.Push(token("-"));
				break;
			case '*':
				v = 2;
				if (t != "") {
					q.Push(token("number", std::stod(t)));
				}
				t = "";
				while ((!w.IsEmpty()) && (w.Check().pr <= 2) && (w.Check().pr >= 2)) {
					q.Push(w.Pop());
				}
				w.Push(token("*"));
				break;
			case '/':
				v = 2;
				if (t != "") {
					q.Push(token("number", std::stod(t)));
				}
				t = "";
				while ((!w.IsEmpty()) && (w.Check().pr <= 2) && (w.Check().pr >= 2)) {
					q.Push(w.Pop());
				}
				w.Push(token("/"));
				break;
			case ')':
				v = 8;
				if (t != "") {
					q.Push(token("number", std::stod(t)));
				}
				t = "";
				while ((!w.IsEmpty()) && (w.Check().flag != 12)) {
					q.Push(w.Pop());
				}
				if (w.Check().flag == 12) {
					w.Pop();
				}
				break;
			default:
				std::string M = "Invalid input " + std::to_string(i);
				throw std::invalid_argument(M);
			}
			break;
		}
		i++;
	}
	if (t != "") {
		token tr = token("number", std::stod(t));
		q.Push(tr);
	}
	while ((!w.IsEmpty())) {
		q.Push(w.Pop());
	}
}
double arithmetic::calc() {
	Stack<token> w(0);
	Stack<token> qq;
	Stack<token> qqq;
	while (!(q.IsEmpty())) {
		qq.Push(q.Check());
		qqq.Push(q.Pop());
	}
	while (!(qqq.IsEmpty())) {
		int g = qqq.Check().flag;
		if (g == 1) {
			qqq.Pop();
			double a = w.Pop().p;
			double b = w.Pop().p;
			w.Push(token("number", b - a));
		}
		if (g == 2) {
			qqq.Pop();
			double a = w.Pop().p;
			double b = w.Pop().p;
			w.Push(token("number", b + a));
		}
		if (g == 3) {
			qqq.Pop();
			double a = w.Pop().p;
			double b = w.Pop().p;
			w.Push(token("number", b * a));
		}
		if (g == 4) {
			qqq.Pop();
			double a = w.Pop().p;
			double b = w.Pop().p;
			w.Push(token("number", b / a));
		}
		if (g == 44) {
			qqq.Pop();
			double a = w.Pop().p;
			w.Push(token("number", sin(a)));
		}
		if (g == 5) {
			qqq.Pop();
			double a = w.Pop().p;
			w.Push(token("number", cos(a)));
		}
		if (g == 6) {
			qqq.Pop();
			double a = w.Pop().p;
			w.Push(token("number", log(a)));
		}
		if (g == 7) {
			qqq.Pop();
			double a = w.Pop().p;
			w.Push(token("number", exp(a)));
		}
		if (g == 8) {
			w.Push(token("number", qqq.Pop().p));
		}
		if (g == 9) {
			qqq.Pop();
			w.Push(token("number", x));
		}
		if (g == 10) {
			qqq.Pop();
			w.Push(token("number", y));
		}
		if (g == 11) {
			qqq.Pop();
			w.Push(token("number", z));
		}
	}
	while (!(qq.IsEmpty())) {
		q.Push(qq.Pop());
	}
	return w.Pop().p;
}
