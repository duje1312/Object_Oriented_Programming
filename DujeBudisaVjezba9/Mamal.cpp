#include"mamal.h"
#include <stdexcept>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>


Mamal::Mamal(string ime, string vrsta, double k_hrane, int godine, double tezina, bool hasfur) :Animal(ime, vrsta, k_hrane, godine, tezina), hasfur(hasfur) {
	if (hasfur) {
		cout << "Sisavac ima dlake";
	}
	else {
		cout << "Sisavac ima malo dalke";
	}
};

string Mamal::getSpecies() const {
	return vrsta;
}
double Mamal::getDailyFood() const {
	return k_hrane;
}
string Mamal::getName() const {
	return ime;
}