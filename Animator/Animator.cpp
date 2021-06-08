#include "Animator.h"
#include <iostream>
Animator *Animator::instance = nullptr;
Animator::Animator(){}
void Animator::setAnimation(Player* hero,AnimationState *animation){
	hero->setSprite(animation->getAnimation(hero));
}
void Animator::setAnimation(Enemy* enemy) {
	AnimationState* animation;
	if (enemy->speed == 0) {
		animation = new Idle;
		enemy->setSprite(animation->getAnimation(enemy));
		delete animation;
	}

	else if (enemy->speed <= 0.05) {
		animation = new Walk;
		enemy->setSprite(animation->getAnimation(enemy));
		delete animation;
	}

	else {
		animation = new Run;
		enemy->setSprite(animation->getAnimation(enemy));
		delete animation;
	}
		
	//enemy->setSprite(animation->getAnimation(enemy));
}
Animator *Animator::getInstance() {
	if (!Animator::instance) {
		Animator::instance = new Animator;
	}
	return Animator::instance;
}