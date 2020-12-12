#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "map.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Player
{
public:
	Player(float x, float y, int heal, int stam, float w, float h, Image image);// Конструктор с значениями координат X, Y и показателем h - HP, s - Stamina, image - передаёт модельку
	void Move(float, float);
	float getCoordinateX();
	void setCoordinateX(float x);
	float getCoordinateY();
	void setCoordinateY(float y);
	void setPosition(float, float);// Присваивание игроку его места на карте 
	Sprite getSprite();
	void interactionWithMap();
	void setSprite(Image);
	void Update(float time); // Обновление местоположения игрока
	void setHP(int quantity);
	void setStamina(int quantity);
	int getStamina();
	int getHP();
	float speed;
	float dx; float dy;
	float w; // Ширина 
	float h; // Высота
	int sost; // Счётчик состояния игрока
private:
	float coordinateX; // Его текущее положение по X
	float coordinateY; // Его текущее положение по Y
	int health; // Очевидно, хп
	int stamina; // Очевидно, стамина
	Image image;
	Texture texture;
	Sprite sprite; // Модель персонажа
};
#endif


