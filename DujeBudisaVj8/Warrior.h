#ifndef WARRIOR_H
#define WARRIOR_H

#include "Player.h"
#include "Enemy.h"

class Warrior : public Player {
public:
	Warrior(const std::string& n);
	
	virtual void attackEnemy(Enemy* target) override;
	virtual void specialAbility() override;
	virtual void displayStatus() const override;
};

#endif