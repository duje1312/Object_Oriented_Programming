#include <iostream>
#include "container.h"
using namespace std;

void test_copy(container c) {
    cout << "Funkcija test_copy primila container size=" << c.size() << endl;
}


container create_container() {
    container c;
    c.push_back(111);
    c.push_back(222);
    return c; 
}

int main() {

    cout << "\n1) Kreiranje i dodavanje elemenata\n";
    container c;
    for (int i = 1; i <= 10; i++)
        c.push_back(i * 10);

    cout << "size=" << c.size() << ", capacity=" << c.capacity() << endl;

    cout << "\n2) Kopiranje containera (copy konstruktor)\n";
    container c2(c);

    cout << "\n3) Move konstruktor\n";
    container c3 = std::move(c2);

    cout << "\n4) Slanje containera funkciji po vrijednosti (copy konstruktor)\n";
    test_copy(c);

    cout << "\n5) Vraæanje containera iz funkcije (move konstruktor)\n";
    container c4 = create_container();

    cout << "\n6) Realokacija memorije (prijelaz kapaciteta)\n";
    c.push_back(9999);
    cout << "Novi capacity: " << c.capacity() << endl;

    cout << "\n7) Ispis elemenata\n";
    for (int i = 0; i < c.size(); i++)
        cout << "Index " << i << " = " << c.at(i) << endl;

    cout << "\nProgram završava...\n";
    return 0;
}
