#include "Gnome.h"
#include "Player.h"
#include "Enemy.h"

Gnome::Gnome(const std::string& n) : Enemy(90, n, 3) {}

void Gnome::attackPlayer(Player* target) {
	if (!isAlive() || !target->isAlive()) {
		return;
	}

	int dmg = 5 * difficulty;
	std::cout << name << " napada lukom i strijelom (" << dmg << "dmg)\n";
	target->takeDamage(dmg);
}

void Gnome::specialAbility() {
	if (health > 20) {
		std::cout << name << " svira trubu (poziva druge gnomove u pomoc)\n";
	}
}

void Gnome::displayStatus() const {
	std::cout << "Gnome: " << name << ", HP: " << health << "\n";
}

