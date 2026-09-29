#ifndef ANIMAL_H
#define ANIMAL_H
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

class Animal {
protected:
	string ime;
	string vrsta;
	double k_hrane;
	int godine;
	double tezina;
public:
	Animal(string ime, string vrsta, double k_hrane, int godine, double tezina);
	virtual string getSpecies()const = 0;
	virtual double getDailyFood()const = 0;
	virtual string getName()const = 0 ;
	virtual ~Animal() = default;
};

















#endif  // ANIMAL_H

