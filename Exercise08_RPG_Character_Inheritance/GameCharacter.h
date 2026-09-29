#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>
#include <iostream>

class GameCharacter {
protected:
	int health;
	std::string name;

public:
	GameCharacter(int h, const std::string& n);
	virtual ~GameCharacter();

	virtual void displayStatus() const = 0;
	virtual void specialAbility() = 0;

	void takeDamage(int dmg);
	bool isAlive() const;

	std::string getName() const {
		return name;
	}

	int getHealth() const {
		return health;
	}
};

#endif