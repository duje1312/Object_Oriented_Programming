#include "Animal.h"
#include "Mamal.h"
#include "Aquatic.h"
#include <string>
#include <stdexcept>

using namespace std;

class Lion : public Mamal {
public:
    Lion(string ime, int godine, double tezina)
        : Animal(ime, "Lav", 0, godine, tezina),
        Mamal(ime, "Lav", 0, godine, tezina, true)
    {
    }

    string getSpecies() const override { return vrsta; }
    string getName() const override { return ime; }

    double getDailyFood() const override {
        double hrana = tezina * 0.06;
        if (hrana == 0) throw logic_error("Dnevna kolicina hrane je 0");
        return hrana;
    }
};

class Elephant : public Mamal {
public:
    Elephant(string ime, int godine, double tezina)
        : Animal(ime, "Slon", 0, godine, tezina),
        Mamal(ime, "Slon", 0, godine, tezina, false)
    {
    }

    string getSpecies() const override { return vrsta; }
    string getName() const override { return ime; }

    double getDailyFood() const override {
        double hrana = tezina * 0.04;
        if (hrana == 0) throw logic_error("Dnevna kolicina hrane je 0");
        return hrana;
    }
};

class Dolphin : public Mamal, public Aquatic {
public:
    Dolphin(string ime, int godine, double tezina)
        : Animal(ime, "Dupin", 0, godine, tezina),
        Mamal(ime, "Dupin", 0, godine, tezina, true),
        Aquatic(ime, "Dupin", 0, godine, tezina, 300.0)
    {
    }

    string getSpecies() const override { return vrsta; }
    string getName() const override { return ime; }

    double getDailyFood() const override {
        double hrana = tezina * 0.05;
        if (hrana == 0) throw logic_error("Dnevna kolicina hrane je 0");
        return hrana;
    }
};

class SeaTurtle : public Aquatic {
public:
    SeaTurtle(string ime, int godine, double tezina)
        : Animal(ime, "Morska kornjaca", 0, godine, tezina),
        Aquatic(ime, "Morska kornjaca", 0, godine, tezina, 200.0)
    {
    }

    string getSpecies() const override { return vrsta; }
    string getName() const override { return ime; }

    double getDailyFood() const override {
        double hrana = tezina * 0.03;
        if (hrana == 0) throw logic_error("Dnevna kolicina hrane je 0");
        return hrana;
    }
};
