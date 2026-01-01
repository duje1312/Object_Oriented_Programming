#ifndef AQUATIC_H
#define AQUATIC_H
#include"animal.h"
#include <stdexcept>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>


class Aquatic : public virtual Animal {
protected:
	double maxDiveDepth ;
public:
	Aquatic(string ime, string vrsta, double k_hrane, int godine, double tezina,double maxDiveDepth);
	std::string getSpecies() const override;
	double getDailyFood() const override;
	std::string getName() const override;
};





#endif //AQUATIC_H