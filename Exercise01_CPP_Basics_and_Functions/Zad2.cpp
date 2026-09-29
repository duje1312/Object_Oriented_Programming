#include <iostream>
using namespace std;

int limit(int x, int low = 0, int high = 100) {
    if (x < low) return low;
    if (x > high) return high;
    return x;
}

double limit(double x, double low = 0.0, double high = 100.0) {
    if (x < low) return low;
    if (x > high) return high;
    return x;
}

int main() {
    cout << limit(120) << endl;       
    cout << limit(-5) << endl;        
    cout << limit(50) << endl;       
    cout << limit(25.7, 10.0, 30.0) << endl; 
    cout << limit(33.3, 10.0, 30.0) << endl; 
    return 0;
}
