#include <iostream>

using namespace std;

int fiboRecursiv(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	return fiboRecursiv(n - 1) + fiboRecursiv(n - 2);
}
//dem complexitate cu noduri in arbore
//cu a^n = a^(n-1) + a^(n-2) | a^(n-2) => x^2 = x + 1 => x

int arr[1000];
int fiboMemo(int n) {

}

int main() {
	int n;
	cin >> n;
	//cout << fiboRecursiv(n);
	cout << fiboMemo(n);


	return 0;
}