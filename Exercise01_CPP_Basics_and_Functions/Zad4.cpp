#include <iostream>
using namespace std;


int& at(int* niz, int i) {
    return niz[i];
}

int main() {
    int niz[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(niz) / sizeof(niz[0]);

    
    for (int i = 0; i < n; i++)
        cout << niz[i] << " ";
    cout << endl;
    int index = 2;
    at(niz, index) = at(niz, index) + 1;

   
    for (int i = 0; i < n; i++)
        cout << niz[i] << " "; 
    cout << endl;

    return 0;
}
