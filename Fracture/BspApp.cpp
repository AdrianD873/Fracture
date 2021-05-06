#include <iostream>
#include "Fracture.hpp"

int main()
{
	Fraction f1(3, 7);
	--f1;

	Fraction f2(7, 7);
	f2++;

	Fraction f3(10, 3);
	f3 += 1;

	Fraction f4(1.25f);
	f4 += 1.25;

	std::cout << "f1: " << f1 << "\n";
	std::cout << "f2: " << f2 << "\n";
	std::cout << "f3: " << f3 << "\n";
	std::cout << "f4: " << 1 + f4 << "\n";
	std::cout << "f1 + f2: " << f1 + f2 << "\n";
	std::cout << "f1 - f2: " << f1 - f2 << "\n";
	std::cout << "f1 * f2: " << f1 * f2 << "\n";
	std::cout << "f1 / f2: " << f1 / f2 << "\n";

	std::cout << "f1 == f2: " << (f1 == f2) << "\n";
	std::cout << "f1 != f2: " << (f1 != f2) << "\n";
	std::cout << "f1 >= f2: " << (f1 >= f2) << "\n";
	std::cout << "f1 <= f2: " << (f1 <= f2) << "\n";
	std::cout << "f1 > f2: " << (f1 > f2) << "\n";
	std::cout << "f1 < f2: " << (f1 < f2) << "\n";
	std::cout << "f3 double: " << f3 << "\n";

	auto comp = f1 <=> f2;
	if (comp > 0)
		std::cout << "f1 is smaller";
	if (comp < 0)
		std::cout << "f2 is smaller";
	if (comp == 0)
		std::cout << "1f and f2 are equal";
}