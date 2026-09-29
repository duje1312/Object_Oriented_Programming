#include "Enemy.h"
#include "Player.h"
#include "GameCharacter.h"

Enemy::Enemy(int h, const std::string& n, int diff) : GameCharacter(h, n), difficulty(diff) {}
Enemy::~Enemy() {}

