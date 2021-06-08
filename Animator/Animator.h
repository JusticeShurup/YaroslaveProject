#ifndef _ANIMATOR_H_
#define _ANIMATOR_H_
#include "Animations.h"
#include "Hurt.h"
#include "Idle.h"
#include "Punch.h"
#include "Run.h"
#include "Walk.h"
using namespace sf;
class Animator
{
public:
	static Animator *getInstance();
	void setAnimation(Player*, AnimationState *animation); // Установка анимации персонажа
	void setAnimation(Enemy*); // Установка анимации врага
private:
	int player_frame;
	int enemy_frame;
	static Animator *instance;
	Animator(); // Пук пук я пустой конструктор 
};
#endif

