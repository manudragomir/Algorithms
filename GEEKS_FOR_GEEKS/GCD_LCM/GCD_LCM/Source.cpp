#include <iostream>
#include <fstream>

int GCD(int a, int b) {
	int r{ 0 };
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int LCM(int a, int b) {
	return a / GCD(a, b) * b;
}

int main(){
	std::ifstream fin{ "input.in" };
	int gcd{ 0 }, lcm{ 1 };
	int nr{ 0 };
	while (fin >> nr) {
		gcd = GCD(gcd, nr);
		lcm = LCM(lcm, nr);
	}
	std::cout << "The greatest common divisor is:" << gcd << "\n";
	std::cout << "The lowest common multiple is:" << lcm << "\n";
	return 0;
}