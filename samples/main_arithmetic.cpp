#include<iostream>
#include"arithmetic.h"
int main()
{
	std::string str = "";
	int f = 0;
	std::cout << " enter the expression or \" stop \" ";
	std::cin >> str;
	arithmetic c = arithmetic(str);
	while (f == 0) {
		if (c.flag_x == 1) {
			std::cout << "enter x ";
			std::cin >> c.x;
			f = 1;
		}
		if (c.flag_y == 1) {
			std::cout << "enter y ";
			std::cin >> c.y;
			f = 1;
		}
		if (c.flag_z == 1) {
			std::cout << "enter z ";
			std::cin >> c.z;
			f = 1;
		}
		std::cout << c.calc() << std::endl;
		std::cout << "enter 0 to calc with other variables ";
		std::cin >> f;
	}
	return 0;
}
