#include "Mage.h"
#include "Player.h"
#include "Enemy.h"

Mage::Mage(const std::string& n) : Player(80, n), mana(100) {}

void Mage::attackEnemy(Enemy* target) {
	if (!isAlive() || !target->isAlive()) {
		return;
	}

	if (mana >= 20) {
		std::cout << name << " baca vatrenu kuglu (40dmg)\n";
		mana -= 20;
		target->takeDamage(40);
	}

	if (mana < 20) {
		std::cout << name << " koristi stap (20dmg)\n";
		mana -= 0;
		target->takeDamage(20);
	}

	if (!target->isAlive()) {
		addScore(10);
	}
}

void Mage::specialAbility() {
	if (health > 50) {
		std::cout << name << " se teleportira.\n";
	}
}

void Mage::displayStatus() const {
	std::cout << "Mage: " << name << ", HP: " << health << ", Mana: " << mana << "\n";
}

