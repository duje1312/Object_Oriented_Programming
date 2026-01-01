#include "Warrior.h"
#include "Player.h"
#include "Enemy.h"

Warrior::Warrior(const std::string& n) : Player(120, n) {}

void Warrior::attackEnemy(Enemy* target) {
	if (!isAlive() || !target->isAlive()) {
		return;
	}

	std::cout << name << " napada " << target->getName() << " macem(20 dmg)\n";
	target->takeDamage(20);

	if (!target->isAlive()) {
		addScore(10);
	}
}

void Warrior::specialAbility() {
	std::cout << name << " aktivira stit (smanjuje sljedeci primljeni napad za 50%)\n";
}

void Warrior::displayStatus() const {
	std::cout << "Warrior: " << name << ", HP: " << health << "\n";
}

