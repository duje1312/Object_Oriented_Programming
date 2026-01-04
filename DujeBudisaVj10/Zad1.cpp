#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool jePotencijaDva(int x) {
    return x > 0 && (x & (x - 1)) == 0;
}

int main() {
    vector<int> v = { 1, 3, 4, 6, 7, 8, 10, 16, 21, 32 };

    auto prviNeparni = find_if(v.begin(), v.end(), [](int x) {
        return x % 2 != 0;
        });

    if (prviNeparni != v.end())
        cout << "Prvi neparni: " << *prviNeparni << endl;
    else
        cout << "Nema neparnih brojeva" << endl;

   
    int brojNeparnih = count_if(v.begin(), v.end(), [](int x) {
        return x % 2 != 0;
        });

    cout << "Broj neparnih: " << brojNeparnih << endl;

   
    int sumaNeparnih = 0;
    for (int x : v)
        if (x % 2 != 0)
            sumaNeparnih += x;

    if (brojNeparnih > 0) {
        double prosjek = static_cast<double>(sumaNeparnih) / brojNeparnih;
        cout << "Prosjek neparnih: " << prosjek << endl;
    }

   
    for (int& x : v)
        if (jePotencijaDva(x))
            x = 2;

    vector<int> parni, neparni;

    for (int x : v) {
        if (x % 2 == 0)
            parni.push_back(x);
        else
            neparni.push_back(x);
    }

    sort(parni.begin(), parni.end());
    sort(neparni.begin(), neparni.end());

    cout << "Parni: ";
    for (int x : parni) cout << x << " ";

    cout << "\nNeparni: ";
    for (int x : neparni) cout << x << " ";

    return 0;
}
