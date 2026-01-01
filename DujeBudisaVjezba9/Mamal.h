#ifndef MAMAL_H
#define MAMAL_H
#include"animal.h"
#include <stdexcept>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>


class Mamal : public virtual Animal {
protected:
	bool hasfur;
public:
	Mamal(string ime, string vrsta, double k_hrane, int godine, double tezina,bool hasfur);
	std::string getSpecies() const override;
	double getDailyFood() const override;
	std::string getName() const override;
};





#endif // MAMAL_H

