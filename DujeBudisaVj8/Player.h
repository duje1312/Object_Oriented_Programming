#ifndef PLAYER_H
#define PLAYER_H

#include "GameCharacter.h"

class Enemy;

class Player : public GameCharacter {
protected:
	int score;

public:
	Player(int h, const std::string& n);
	virtual ~Player();

	virtual void attackEnemy(Enemy* target) = 0;
	void addScore(int s) {
		score += s;
	}
};

#endif