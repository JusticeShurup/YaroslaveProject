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
	void Update(float time, Map* map, Player* hero);//���������� ��������������	
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
	float w; // ������ 
	float h; // ������
	int sost; // ������� ��������� ������
	int frame; // ���� 

private:
	float coordinateX; // ��� ������� ��������� �� X
	float coordinateY; // ��� ������� ��������� �� Y

	int health; // ��������, ��
	int stamina; // ������������ 

	int damage;

	Image image;	// ������ ���������
	Texture texture;// ������ ���������
	Sprite sprite;  // ������ ���������

	Image HP_bar_image;		// �� �������
	Texture HP_bar_texture; // �� �������
	Sprite HP_bar_sprite;	// �� �������

	std::vector<Image> animation;
};
#endif

