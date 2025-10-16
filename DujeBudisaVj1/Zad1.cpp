#include <iostream>
#include<iomanip>
using namespace std;
int* fibonacciNiz(int n) {
	int* niz = new int[n]; 
	niz[0] = 1;
	if (n > 1) {
		niz[1] = 1;
	}
	for (int i = 2; i < n; ++i) {
		niz[i] = niz[i - 1] + niz[i - 2];
	}

	return niz;
}

int main() {
	int n;
	cout << "Unesite velicinu niza (n): ";
	cin >> n;
	int* niz = fibonacciNiz(n);
	std::cout << "Fibonacci niz: ";
	for (int i = 0; i < n; ++i) {
		std::cout << niz[i] << " ";
	}
	delete[] niz; 
	return 0;
}
