#include"animal.h"
#include <stdexcept>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>




Animal::Animal(string ime, string vrsta, double k_hrane, int godine, double tezina) :ime(ime), vrsta(vrsta), k_hrane(k_hrane), godine(godine), tezina(tezina) {
	if (ime.empty()) {
		throw invalid_argument("Ime nesmije biti prazno");
	}
	if (godine<0) {
		throw invalid_argument("godine nesmiju biti manje od nula");
	}
	if (tezina<=0) {
		throw invalid_argument("tezina nesmije biti manje od nula");
	}
};
string Animal::getSpecies() const {
	return vrsta;
}
double Animal::getDailyFood() const {
	return k_hrane;
}
string Animal::getName() const {
	return ime;
}







