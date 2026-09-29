#ifndef MAGE_H
#define MAGE_H

#include "Player.h"
#include "Enemy.h"

class Mage : public Player {
protected:
	int mana;

public:
	Mage(const std::string& n);

	virtual void attackEnemy(Enemy* target) override;
	virtual void specialAbility() override;
	virtual void displayStatus() const override;
};

#endif