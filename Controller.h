#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_
#include "Enemy.h"
#include "HUD.h"
#include "Animator/AnimationState.h"
#include "Animator/Animations.h"
#include <ctime>
class Controller //  ласс отвечающий за взаимодействие между всеми показател€ми игроков, а также осуществл€ет управление
{
public:
	static Controller* getInstance();

	void takeDamage(Enemy* enemy);
	void giveDamage(Enemy* enemy);
	void setDamage(int damage);
	int getDamage();

	void Die();

	bool canHit(float targetX, float targetY, float X, float Y);
	void moveAfterHit();

	int getHP();
	void setHP(int quantity);
	void setStamina(int quantity);
	int getStamina();

	void setPlayer(Player* player);
	Player* getPlayer();
	void setEnemy(Enemy* enemy);
	Enemy* getEnemy();

	void setAnimiationState(AnimationState* animation);
	AnimationState* getAnimationState();
	void deleteAnimation();

	void setHUD(HUD* hud);
	HUD* getHUD();

	void makeMove();

	void playerUpdate(float time, Map* map); 

private:
	int HP; // ¬ременное кол-во хп, которое хранитс€ и потом присваиваетс€ игроку или врагу
	float Stamina; //  ол-во стамины, принадлежащее только игроку
	int damage; // ”рон игрока или врага 
	Controller();
	AnimationState* animation;
	Idle* idle;
	Walk* walk;
	Run* run;
	Punch* punch;

	static Controller* instance;
						 
	clock_t cooldown_start, cooldown_end;
	bool isCooldown, stoped; //  удлаун дл€ удара и stoped дл€ остановки игрока во врем€ удара

	Enemy* enemy;
	Player* player;
	HUD* hud;
};
#endif

