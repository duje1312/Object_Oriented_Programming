#include <vector>
#include <algorithm>
#include "Mage.h"
#include "Warrior.h"
#include "Gnome.h"
#include "Boss.h"

int main() {
	std::vector<GameCharacter*> chars;

	Warrior* Conan = new Warrior("Conan");
	Mage* Merlin = new Mage("Merlin");
	Gnome* Gnomeo = new Gnome("Gnomeo");
	Gnome* Sneaky = new Gnome("Sneaky");
	Boss* Dragon = new Boss("Dragon");

	chars.push_back(Conan);
	chars.push_back(Merlin);
	chars.push_back(Gnomeo);
	chars.push_back(Sneaky);
	chars.push_back(Dragon);

	Conan->attackEnemy(Gnomeo);
	Merlin->attackEnemy(Sneaky);
	Gnomeo->attackPlayer(Conan);
	Merlin->attackEnemy(Gnomeo);
	Dragon->attackPlayer(Merlin);
	Merlin->attackEnemy(Gnomeo);
	Conan->attackEnemy(Dragon);
	Merlin->attackEnemy(Dragon);

	std::cout << "\nSPECIAL ABILITIES\n";
	for (auto* c : chars) {
		c->specialAbility();
	}

	std::cout << "\nSTATUS\n";
	for (auto* c : chars) {
		c->displayStatus();
	}

	std::cout << "\nLik s najvise HP-a je:\n";
	auto* maxHP = *std::max_element(chars.begin(), chars.end(),
		[](auto* a, auto* b) { return a->getHealth() < b->getHealth(); });

	std::cout << maxHP->getName() << " (" << maxHP->getHealth() << " HP)\n";

	for (auto* c : chars) {
		delete c;
	}

	return 0;
}