#include <iostream>
using namespace std;
int* fibonacci(int n) {
	int* niz = new int[n] {1, 1};
	for (int i = 2; i < n; i++) {
		niz[i] = niz[i - 1] + niz[i - 2];
	}
	return niz;
}

int main() {
	int n = 9;
	int* niz1 = fibonacci(n);
	for (int i = 0; i < n; i++) {
		cout << niz1[i] << ' ';
	}
	delete[] niz1;
	niz1 = nullptr;
	return 0;
}