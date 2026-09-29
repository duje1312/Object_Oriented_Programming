#include <iostream>
#include <memory>
#include <stdexcept>

#include "Animal.h"
#include "Mamal.h"
#include "Aquatic.h"

#include "ZooKeeper.h"
#include "ZooSection.cpp"   
#include "Zivotinje.cpp"   

using namespace std;

int main() {
    try {
        ZooSection<Animal> section;
        ZooKeeper keeper;

        try {
            section.AddAnimal(make_unique<Lion>("Simba", 3, 180.0));
            section.AddAnimal(make_unique<Elephant>("Dumbo", 10, 1200.0));
            section.AddAnimal(make_unique<Dolphin>("Flipper", 5, 200.0));
            section.AddAnimal(make_unique<SeaTurtle>("Shelly", 40, 80.0));
        }
        catch (const exception& e) {
            cout << "Greska pri dodavanju zivotinja: " << e.what() << endl;
        }

        for (size_t i = 0; i < section.size(); ++i) {
            try {
                keeper.processAnimal(section.getAnimal(i));
            }
            catch (const exception& e) {
                cout << "Greska pri hranjenju: " << e.what() << endl;
            }
        }

        try {
            cout << "Ukupna dnevna kolicina hrane: "
                << section.totalFood() << "kg" << endl;
        }
        catch (const exception& e) {
            cout << "Greska pri racunanju hrane: " << e.what() << endl;
        }

        cout << "Ukupno nahranjenih zivotinja: "
            << ZooKeeper::getTotalAnimalsServed() << endl;

        try {
            section.AddAnimal(unique_ptr<Animal>(nullptr));
        }
        catch (const exception& e) {
            cout << "Demonstracija iznimke: " << e.what() << endl;
        }
    }
    catch (const exception& e) {
        cout << "Neocekivana greska: " << e.what() << endl;
    }

    return 0;
}
