#include"aquatic.h"
#include <stdexcept>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>




Aquatic::Aquatic(string ime, string vrsta, double k_hrane, int godine, double tezina, double maxDiveDepth) :Animal(ime, vrsta, k_hrane, godine, tezina), maxDiveDepth(maxDiveDepth) {
	cout << "Stvorena vodena zivotinja koja roni do" << maxDiveDepth << endl;
};
string Aquatic::getSpecies() const {
	return vrsta;
}
double Aquatic::getDailyFood() const {
	return k_hrane;
}
string Aquatic::getName() const {
	return ime;
}