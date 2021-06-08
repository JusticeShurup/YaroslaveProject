#ifndef _ANIMATION_STATE_H_
#define _ANIMATION_STATE_H_
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "../Player.h"
#include "../Enemy.h"
using namespace sf;
class AnimationState // Абстрактный класс для всех анимаций 
{
public:
	AnimationState();
	virtual Image getAnimation(Player*) = 0;
	virtual Image getAnimation(Enemy*) = 0;
};
#endif
