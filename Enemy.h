#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace sf;
class Enemy
{
public:
	Enemy(float x, float y, int heal, float w, float h, std::string namefile);
	~Enemy();
	void setSprite(Image);

	void setCoordinateY(float y);
	float getCoordinateY();
	void setCoordinateX(float x);
	float getCoordinateX();
	void Update(float time, Map* map, Player* hero);//Обновление местоположения	
	void interactionWithMap(Map* map);
	void setPosition(float y, float x);
	void Move(float x, float y);

	void setHP(int quantity);
	int getHP();
	Sprite getHP_bar();
	
	void setStamina(int quantity);
	int getStamina();
	
	int Distance(float X, float Y);
	Sprite getSprite();

	float speed;
	float dx; float dy;
	float w; // Ширина 
	float h; // Высота
	int sost; // Счётчик состояния игрока
	int frame; // Кадр 

private:
	float coordinateX; // Его текущее положение по X
	float coordinateY; // Его текущее положение по Y

	int health; // Очевидно, хп
	int stamina; // Выносливость 

	int damage;

	Image image;	// Модель персонажа
	Texture texture;// Модель персонажа
	Sprite sprite;  // Модель персонажа

	Image HP_bar_image;		// ХП полоска
	Texture HP_bar_texture; // ХП полоска
	Sprite HP_bar_sprite;	// ХП полоска

	std::vector<Image> animation;
};
#endif

