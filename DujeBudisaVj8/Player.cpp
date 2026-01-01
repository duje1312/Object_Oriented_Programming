#include "Player.h"
#include "GameCharacter.h"
#include "Enemy.h"

Player::Player(int h, const std::string& n) : GameCharacter(h, n), score(0) {}
Player::~Player() {}

