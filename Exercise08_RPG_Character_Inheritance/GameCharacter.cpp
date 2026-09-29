#include "GameCharacter.h"

GameCharacter::GameCharacter(int h, const std::string& n) : health(h), name(n) {}
GameCharacter::~GameCharacter() {}

void GameCharacter::takeDamage(int dmg) {
	if (dmg > 0) {
		health -= dmg;
	}

	if (health < 0) {
		health = 0;
	}
}

bool GameCharacter::isAlive() const {
	return health > 0;
}