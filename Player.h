#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "map.h"
using namespace sf;
class Player
{
public:
	Player(float x, float y, int heal, unsigned int stam, float w, float h, std::string namefile);// ����������� � ���������� ��������� X, Y � ����������� h - HP, s - Stamina, image - ������� ��������

	void Move(float, float);

	float getCoordinateX();
	void setCoordinateX(float x);
	float getCoordinateY();
	void setCoordinateY(float y);
	void setPosition(float, float);// ������������ ������ ��� ����� �� �����

	//void interactionWithMap(Map* map);
	bool canMove(Map* map, float x, float y);

	void setSprite(Image);
	Sprite getSprite();

	void Update(float time,Map* map); // ���������� �������������� ������
	
	void setHP(int quantity);
	void setStamina(unsigned int quantity);
	void setDamage(unsigned int quantity);
	int getDamage();
	int getStamina();
	int getHP();


	float speed;
	float dx; float dy;
	float w; // ������ 
	float h; // ������
	int sost; // ������� ��������� ������
	int frame;
	friend class Controller;
private:
	float coordinateX; // ��� ������� ��������� �� X
	float coordinateY; // ��� ������� ��������� �� Y
	int health; // ��������, ��
	unsigned int stamina; // ��������, �������
	unsigned int damage;
	Image image;
	Texture texture;
	Sprite sprite; // ������ ���������
};
#endif


