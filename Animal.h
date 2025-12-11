#ifndef ANIMAL_H
#define ANIMAL_H
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <stdexcept>

using namespace std;

class Animal {
protected:
	string name;
	string spicie;
	int yr;
	double wh;
	double food;
public:
	Animal(string spicie, string name, double food,int yr,double wh);
	virtual string getSpecies() const = 0;
	virtual double getDailyFood() const = 0;
	virtual string getName() const = 0;
	if (name.empty() || yr < 0 || wh < 0) throw X();
	catch X{

	};
};















#endif  ANIMAL_H


