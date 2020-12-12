#include "Player.h"
Player::Player(float x, float y, int heal, int stam, float w, float h, Image image)
{
	coordinateX = x;
	coordinateY = y;
	health = heal;
	stamina = stam;
	this->image = image;
	texture.loadFromImage(this->image);
	sprite.setTexture(texture);
	this->w = w;
	this->h = h;
	speed = 0; dy = 0; dx = 0; sost = 0;
}
void Player::Update(float time) // ���������� �������������� ������ 
{
		switch (sost)
		{
			case 0: dx = speed; dy = 0; break;
			case 1: dx = -speed; dy = 0; break;
			case 2: dx = 0; dy = speed; break;
			case 3: dx = 0; dy = -speed; break;
		}
		coordinateX += dx * time;
		coordinateY += dy * time;
		speed = 0;
		sprite.setPosition(coordinateX, coordinateY);
		interactionWithMap();
}
void Player::interactionWithMap() // �-��� �������������� � ������
{

	for (int i = coordinateY / 32; i < (coordinateY + h) / 32; i++)
		for (int j = coordinateX / 32; j < (coordinateX + w) / 32; j++) 
		{
			if (TileMap[i][j] == '0')
			{
				if (dy > 0)//���� ��� ����,
				{
					coordinateY = i * 32 - h;
				}
				if (dy < 0)//���� ��� �����
				{
					coordinateY = i * 32 + 32;
				}
				if (dx > 0)//���� ��� ������
				{
					coordinateX = j * 32 - w;
				}
				if (dx < 0)//���� ��� �����
				{
					coordinateX = j * 32 + 32;
				}
			}
		}
}
float Player::getCoordinateX()
{
	return coordinateX;
}
void Player::setCoordinateX(float x) 
{
	coordinateX = x;
}
float Player::getCoordinateY() 
{
	return coordinateY;
}
void Player::setCoordinateY(float y) 
{
	coordinateY = y;
}
void Player::Move(float x, float y) 
{
	sprite.move(x, y);
	coordinateX += x;
	coordinateY += y;
}
Sprite Player::getSprite() 
{
	return sprite;
}
void Player::setPosition(float x, float y) 
{
	sprite.setPosition(x, y);
}
void Player::setSprite(Image i) 
{
	image = i;
	texture.loadFromImage(i);
	sprite.setTexture(texture);
}
// ���� � �� � �������� 
void Player::setHP(int quantity) 
{
	health = quantity;
}
void Player::setStamina(int quantity) 
{
	stamina = quantity;
}
int Player::getHP() 
{
	return health;
}
int Player::getStamina() 
{
	return stamina;
}
// ���� � �� � ��������