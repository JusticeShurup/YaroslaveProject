#include "Hurt.h"
Hurt::Hurt() {
	if (hurt_animations.size() < 1) {
		//ÂÏÐÀÂÎ
		static Image anim_hurt_right; anim_hurt_right.loadFromFile("NES Slave - Toby Orbon Free Files/Hurt/Hurt_East_frame.png");
		hurt_animation_right.push_back(anim_hurt_right);
		hurt_animation_right.push_back(anim_hurt_right);
		hurt_animation_right.push_back(anim_hurt_right);
		hurt_animation_right.push_back(anim_hurt_right);
		//ÂÏÐÀÂÎ
		//ÂËÅÂÎ
		static Image anim_hurt_left; anim_hurt_left.loadFromFile("NES Slave - Toby Orbon Free Files/Hurt/Hurt_West_frame.png");
		hurt_animation_left.push_back(anim_hurt_left);
		hurt_animation_left.push_back(anim_hurt_left);
		hurt_animation_left.push_back(anim_hurt_left);
		hurt_animation_left.push_back(anim_hurt_left);
		//ÂËÅÂÎ
		//ÂÍÈÇ
		static Image anim_hurt_down; anim_hurt_down.loadFromFile("NES Slave - Toby Orbon Free Files/Hurt/Hurt_South_frame.png");
		hurt_animation_down.push_back(anim_hurt_down);
		hurt_animation_down.push_back(anim_hurt_down);
		hurt_animation_down.push_back(anim_hurt_down);
		hurt_animation_down.push_back(anim_hurt_down);
		//ÂÍÈÇ
		//ÂÂÅÐÕ
		static Image anim_hurt_up; anim_hurt_up.loadFromFile("NES Slave - Toby Orbon Free Files/Hurt/Hurt_North_frame.png");
		hurt_animation_up.push_back(anim_hurt_up);
		hurt_animation_up.push_back(anim_hurt_up);
		hurt_animation_up.push_back(anim_hurt_up);
		hurt_animation_up.push_back(anim_hurt_up);
		//ÂÂÅÐÕ
		hurt_animations.push_back(hurt_animation_right);
		hurt_animations.push_back(hurt_animation_left);
		hurt_animations.push_back(hurt_animation_down);
		hurt_animations.push_back(hurt_animation_up);
	}
}
Image Hurt::getAnimation(Player *hero) {
	if (hero->sost > 3) hero->sost = 0;
	if (hero->frame > 3) hero->frame = 0;
	return hurt_animations[hero->sost][hero->frame];
}
Image Hurt::getAnimation(Enemy* enemy) {
	if (enemy->sost > 3) enemy->sost = 0;
	if (enemy->frame > 3) enemy->frame = 0;
	return hurt_animations[enemy->sost][enemy->frame];
}

