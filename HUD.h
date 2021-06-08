#ifndef _HUD_H_
#define _HUD_H_
#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;
class HUD
{
public:
	HUD();
	void setHP(int quantity);
	void setStamina(unsigned int quantity);
	void sostBar();
	Sprite getHP_bar_sprite();
	Sprite getStamina_bar_sprite();
	void setHP_bar_sprite(std::string);//Для загрузки используется имя файл
	void setStamina_bar_sprite(std::string);//Для загрузки используется имя файл
	void HUDupdate(Player* hero);
private:
	int HP;
	unsigned int stamina;
	Image HP_bar_image; 
	Image stamina_bar_image;
	Texture stamina_bar_texture;
	Texture HP_bar_texture;
	Sprite HP_bar_sprite;
	Sprite stamina_bar_sprite;
	void makeSprite(std::string);
};
#endif