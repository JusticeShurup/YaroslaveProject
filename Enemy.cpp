#include "Enemy.h"
int Sign(double value) {
	if (floor(value) == 0)
		return 0;
	else if (value > 0)
		return 1;
	else
		return -1;
}

Enemy::Enemy(float x, float y, int heal, float w, float h, std::string namefile) {
	coordinateX = x;
	coordinateY = y;

	image.loadFromFile(namefile);
	texture.loadFromImage(this->image);
	sprite.setTexture(texture);

	HP_bar_image.loadFromFile("images/enemy_hp_bar.png");
	HP_bar_texture.loadFromImage(HP_bar_image);
	HP_bar_sprite.setTexture(HP_bar_texture);
	HP_bar_sprite.setPosition(coordinateX + 2, coordinateY);

	this->w = w;
	this->h = h;
	
	speed = 0.049; dy = 0; dx = 0; sost = 0; frame = 0;
	damage = 10; health = heal;
}

Enemy::~Enemy() {}

void Enemy::Update(float time, Map* map, Player* hero) {
	HP_bar_sprite.setTextureRect(IntRect(0, 0, 0.1 * health, 2));
	float targetX = hero->getCoordinateX(); float targetY = hero->getCoordinateY();
	if (targetX > coordinateX)
		sost = 0;
	else
		sost = 1;

	if (Distance(targetX, targetY) > speed)
		speed = 0.05;

	if (floor(coordinateX) == floor(targetX) && coordinateY == targetY) {
		speed = 0;
		return;  // job's done
	}

	if (Distance(targetX, targetY) < speed)
	{
		coordinateX = targetX;
		coordinateY = targetY;
		speed = 0;
		return;
	}

	float adjucentLeg = abs(targetX - coordinateX); // прилежащий катет
	float opposingLeg = abs(targetY - coordinateY); // противолежащий катет
	float signX = Sign(targetX - coordinateX);
	float signY = Sign(targetY - coordinateY);

	if (speed == 0) return;
	
	setPosition(coordinateX, coordinateY);

	if (adjucentLeg == 0)
	{
		if (!sprite.getGlobalBounds().intersects(hero->getSprite().getGlobalBounds()))
			coordinateY += speed * signY * time;
		return;
	}
	if (opposingLeg == 0)
	{
		if (!sprite.getGlobalBounds().intersects(hero->getSprite().getGlobalBounds()))
			coordinateX += speed * signX * time;
		return;
	}

	float tgAlpha = ((double)opposingLeg) / adjucentLeg;
	float alpha = atan(tgAlpha);

	float stepX = (float)(signX * speed * cos(alpha) * time);
	float stepY = (float)(signY * speed * sin(alpha) * time);
	if (!sprite.getGlobalBounds().intersects(hero->getSprite().getGlobalBounds())) {
		coordinateX += stepX;
		coordinateY += stepY;
	}

	if (targetY > coordinateY && (coordinateX > targetX - 10 && coordinateX < targetX + 10) || targetY - 30 > coordinateY)
		sost = 2;//Идёт вниз 
	else if (coordinateX > targetX - 10 && coordinateX < targetX + 10 || targetY + 30 < coordinateY)
		sost = 3;//Идёт вверх
	interactionWithMap(map);
}

Sprite Enemy::getHP_bar() {
	return HP_bar_sprite;
}

void Enemy::interactionWithMap(Map* map) // ф-ция взаимодействия с картой
{
	for (int i = coordinateY / 32; i < (coordinateY + h) / 32; i++)
		for (int j = coordinateX / 32; j < (coordinateX + w) / 32; j++)
			if (map->TileMap[i][j] == '0')
			{
				if (dy > 0)//Если шли вниз,
					coordinateY = i * 32 - h;
				if (dy < 0)//Если шли вверх
					coordinateY = i * 32 + h;
				if (dx > 0)//Если шли вправо
					coordinateX = j * 32 - w;
				if (dx < 0)//Если шли влево
					coordinateX = j * 32 + w;
			}
}

float Enemy::getCoordinateX(){
	return coordinateX;
}

void Enemy::setCoordinateX(float x){
	this->coordinateX = x;
}

float Enemy::getCoordinateY(){
	return coordinateY;
}

void Enemy::setCoordinateY(float y){
	this->coordinateY = y;
}

void Enemy::setHP(int quantity) {
	health = quantity;
}

int Enemy::getHP() {
	return health;
}

void Enemy::setStamina(int quantity) {
	stamina = quantity;
}

int Enemy::getStamina() {
	return stamina;
}

void Enemy::Move(float x, float y){
	sprite.move(x, y);
	coordinateX += x;
	coordinateY += y;
}

void Enemy::setPosition(float x, float y){
	sprite.setPosition(x, y);
	HP_bar_sprite.setPosition(coordinateX + 2, coordinateY);
	coordinateX = x;
	coordinateY = y;
}

void Enemy::setSprite(Image i){
	image = i;
	texture.loadFromImage(i);
	sprite.setTexture(texture);
}

int Enemy::Distance(float X, float Y) {
	return sqrt(pow(X - coordinateX, 2) + pow(Y - coordinateY, 2));
}

Sprite Enemy::getSprite() {
	return sprite;
}
