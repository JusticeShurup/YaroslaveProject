#include "HUD.h"
HUD::HUD(int health, int stamina) {
	hp = health;
	this->stamina = stamina;
}
void HUD::setHP(int quantity) {
	hp = quantity;
}
void HUD::setStamina(int quantity) {
	stamina = quantity;
}

