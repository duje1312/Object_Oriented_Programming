#ifndef ENEMY_H
#define ENEMY_H

#include "GameCharacter.h"

class Player;

class Enemy : public GameCharacter {
protected:
	int difficulty;

public:
	Enemy(int h, const std::string& n, int diff);
	virtual ~Enemy();

	virtual void attackPlayer(Player* target) = 0;
};

#endif