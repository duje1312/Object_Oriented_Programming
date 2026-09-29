#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"

class Boss : public Enemy {
public:
	Boss(const std::string& n);

	virtual void attackPlayer(Player* target) override;
	virtual void specialAbility() override;
	virtual void displayStatus() const override;
};

#endif