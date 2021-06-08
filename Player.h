#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "map.h"
using namespace sf;
class Player
{
public:
	Player(float x, float y, int heal, unsigned int stam, float w, float h, std::string namefile);// Конструктор с значениями координат X, Y и показателем h - HP, s - Stamina, image - передаёт модельку

	void Move(float, float);

	float getCoordinateX();
	void setCoordinateX(float x);
	float getCoordinateY();
	void setCoordinateY(float y);
	void setPosition(float, float);// Присваивание игроку его места на карте

	//void interactionWithMap(Map* map);
	bool canMove(Map* map, float x, float y);

	void setSprite(Image);
	Sprite getSprite();

	void Update(float time,Map* map); // Обновление местоположения игрока
	
	void setHP(int quantity);
	void setStamina(unsigned int quantity);
	void setDamage(unsigned int quantity);
	int getDamage();
	int getStamina();
	int getHP();


	float speed;
	float dx; float dy;
	float w; // Ширина 
	float h; // Высота
	int sost; // Счётчик состояния игрока
	int frame;
	friend class Controller;
private:
	float coordinateX; // Его текущее положение по X
	float coordinateY; // Его текущее положение по Y
	int health; // Очевидно, хп
	unsigned int stamina; // Очевидно, стамина
	unsigned int damage;
	Image image;
	Texture texture;
	Sprite sprite; // Модель персонажа
};
#endif


