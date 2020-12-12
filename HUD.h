#ifndef _HUD_H_
#define _HUD_H_
#include "SFML/Graphics.hpp"
class HUD
{
public:
	HUD(int health, int stamina);
	void setHP(int quantity);
	void setStamina(int quantity);
private:
	int hp;
	int stamina;
};
#endif
