#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "map.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Player
{
public:
	Player(float x, float y, int heal, int stam, float w, float h, Image image);// ����������� � ���������� ��������� X, Y � ����������� h - HP, s - Stamina, image - ������� ��������
	void Move(float, float);
	float getCoordinateX();
	void setCoordinateX(float x);
	float getCoordinateY();
	void setCoordinateY(float y);
	void setPosition(float, float);// ������������ ������ ��� ����� �� ����� 
	Sprite getSprite();
	void interactionWithMap();
	void setSprite(Image);
	void Update(float time); // ���������� �������������� ������
	void setHP(int quantity);
	void setStamina(int quantity);
	int getStamina();
	int getHP();
	float speed;
	float dx; float dy;
	float w; // ������ 
	float h; // ������
	int sost; // ������� ��������� ������
private:
	float coordinateX; // ��� ������� ��������� �� X
	float coordinateY; // ��� ������� ��������� �� Y
	int health; // ��������, ��
	int stamina; // ��������, �������
	Image image;
	Texture texture;
	Sprite sprite; // ������ ���������
};
#endif


