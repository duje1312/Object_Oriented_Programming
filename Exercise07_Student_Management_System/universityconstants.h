#ifndef UNIVERSITYCONSTANTS_H
#define UNIVERSITYCONSTANTS_H

#include <iostream>
using namespace std;

class UniversityConstants
{
public:
    // STATIC KONSTANTE (traži zadatak)
    static const int MAX_ETCS_PER_YEAR;
    static const int REQUIRED_ECTS_PER_YEAR;

    // Staticka funkcija za ispis pravila
    static void print_university_rules();
};

#endif
