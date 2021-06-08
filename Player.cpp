#include "Player.h"
bool Player::canMove(Map* map, float x, float y) {
	for (int i = (coordinateY + y) / 32; i < (coordinateY + h) / 32; i++)
		for (int j = (coordinateX + x) / 32; j < (coordinateX + w) / 32; j++)
			if (map->TileMap[i][j] == '0')
				return false;
			else
				return true;
}

Player::Player(float x, float y, int heal, unsigned int stam, float w, float h, std::string namefile)
{
	coordinateX = x;
	coordinateY = y;
	health = heal;
	stamina = stam;
	image.loadFromFile(namefile);
	texture.loadFromImage(this->image);	
	sprite.setTexture(texture);
	this->w = w;
	this->h = h;
	speed = 0;  dy = 0; dx = 0; sost = 0; frame = 0;
	damage = 10;
}

void Player::Update(float time, Map* map) // Обновление местоположения игрока 
{
	switch (sost)
	{
	case 0: speed = abs(dx); break; // Вправо
	case 1: speed = abs(dx); break; // Влево
	case 2: speed = abs(dy); break; // Вниз 
	case 3: speed = abs(dy); break; // Вверх
	}
	if (canMove(map, dx * time, dy * time)) {
		coordinateX += dx * time;
		coordinateY += dy * time;
	}

	setPosition(coordinateX, coordinateY);
		//interactionWithMap(map);
}

/*void Player::interactionWithMap(Map* map) // ф-ция взаимодействия с картой
{
	for (int i = coordinateY / 32; i < (coordinateY + h) / 32; i++)
		for (int j = coordinateX / 32; j < (coordinateX + w) / 32; j++)
			if (map->TileMap[i][j] == '0')
			{
				if (dy > 0) //Если шли вниз
					coordinateY = i * 32 - h;
				if (dy < 0)//Если шли вверх
					coordinateY = i * 32 + h;
				if (dx > 0)//Если шли вправо
					coordinateX = j * 32 - w;
				if (dx < 0)//Если шли влево
					coordinateX = j * 32 + w;
			}				
}*/

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
	coordinateX = x;
	coordinateY = y;
}
void Player::setSprite(Image i) 
{	
	image = i;
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}


//void Player::setDamage() {
	//return;
//}

// Блок с хп и стаминой 
void Player::setHP(int quantity) {
	health = quantity;
}

void Player::setStamina(unsigned int quantity) 
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
// Блок с хп и стаминой