#include "HUD.h"
#include "Controller.h"

HUD::HUD() {
	HP = 100;
	stamina = 100;

	HP_bar_image.loadFromFile("images/healthbar.png");
	HP_bar_texture.loadFromImage(HP_bar_image);
	HP_bar_sprite.setTexture(HP_bar_texture);

	stamina_bar_image.loadFromFile("images/stamina.png");
	stamina_bar_texture.loadFromImage(stamina_bar_image);
	stamina_bar_sprite.setTexture(stamina_bar_texture);

}

void HUD::HUDupdate(Player* hero) {
	HP_bar_sprite.setPosition(hero->getCoordinateX() - 320, hero->getCoordinateY() - 220);
	stamina_bar_sprite.setPosition(hero->getCoordinateX() - 320, hero->getCoordinateY() - 190);
}

void HUD::setHP(int quantity) {
	HP = quantity;
	sostBar();
}

void HUD::setStamina(unsigned int quantity) {
	stamina = quantity;
	sostBar();
}

Sprite HUD::getHP_bar_sprite() {
	return HP_bar_sprite;
}

Sprite HUD::getStamina_bar_sprite() {
	return stamina_bar_sprite;
}

void HUD::setHP_bar_sprite(std::string file_name) {// загрузка происходит через файл
	HP_bar_image.loadFromFile(file_name);
	HP_bar_texture.loadFromImage(HP_bar_image);
	HP_bar_sprite.setTexture(HP_bar_texture);
}

void HUD::setStamina_bar_sprite(std::string file_name) {
	stamina_bar_image.loadFromFile(file_name);
	stamina_bar_texture.loadFromImage(stamina_bar_image);
	stamina_bar_sprite.setTexture(stamina_bar_texture);
}

void HUD::sostBar() { // Метод отвечающий за состояние полоски HP и стамины, в зависимости от кол-ва уменьшает или увеличивает их
	HP_bar_sprite.setTextureRect(IntRect(0, 0, 1.1 * HP, 20));
	stamina_bar_sprite.setTextureRect(IntRect(0, 0, 1.1 * stamina, 20));
}