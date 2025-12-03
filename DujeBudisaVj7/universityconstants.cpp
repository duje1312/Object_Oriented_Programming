#include "universityconstants.h"
#include <iostream>
using namespace std;

// DEFINICIJE STATIC konstanti (moraju biti definirane u .cpp)
const int UniversityConstants::MAX_ETCS_PER_YEAR = 60;
const int UniversityConstants::REQUIRED_ECTS_PER_YEAR = 45;

// Definicija funkcije
void UniversityConstants::print_university_rules()
{
    cout << "Max broj ECTS bodova: "
        << MAX_ETCS_PER_YEAR << endl;

    cout << "Minimalan broj ECTS bodova za prolaznu godinu: "
        << REQUIRED_ECTS_PER_YEAR << endl;
}
