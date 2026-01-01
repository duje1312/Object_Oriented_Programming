#ifndef GNOME_H
#define GNOME_H

#include "Enemy.h"
#include "Player.h"

class Gnome : public Enemy {
public:
	Gnome(const std::string& n);

	virtual void attackPlayer(Player* target) override;
	virtual void specialAbility() override;
	virtual void displayStatus() const override;
};

#endif