#include "Boss.h"
#include "Player.h"
#include "Enemy.h"

Boss::Boss(const std::string& n) : Enemy(300, n, 8) {}

void Boss::attackPlayer(Player* target) {
	if (!isAlive() || !target->isAlive()) {
		return;
	}

	int dmg = 10 * difficulty;
	std::cout << name << " razbija zemlju pod igracem (" << dmg << "dmg)\n";
	target->takeDamage(dmg);
}

void Boss::specialAbility() {
	if (health >= 1 || health <= 250) {
		std::cout << name << " regenerira health\n";
		health += 50;
	}
}

void Boss::displayStatus() const {
	std::cout << "Boss: " << name << ", HP: " << health << "\n";
}