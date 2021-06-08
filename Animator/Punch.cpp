#include "Punch.h"
Punch::Punch() {
	if (punch_animations.size() < 1) {
		//ÂÏÐÀÂÎ
		static Image anim_punch_right; anim_punch_right.loadFromFile("NES Slave - Toby Orbon Free Files/Attack/Attack_Pose_East_frame.png");
		static Image anim_walk_right; anim_walk_right.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_East_frame_0.png");
		punch_animation_right.push_back(anim_punch_right);
		punch_animation_right.push_back(anim_punch_right);
		punch_animation_right.push_back(anim_punch_right);
		punch_animation_right.push_back(anim_punch_right);
		//ÂÏÐÀÂÎ
		//ÂËÅÂÎ
		static Image anim_punch_left; anim_punch_left.loadFromFile("NES Slave - Toby Orbon Free Files/Attack/Attack_Pose_West_frame.png");
		static Image anim_walk_left; anim_walk_left.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_West_frame_0.png");
		punch_animation_left.push_back(anim_punch_left);
		punch_animation_left.push_back(anim_punch_left);
		punch_animation_left.push_back(anim_punch_left);
		punch_animation_left.push_back(anim_walk_left);
		//ÂËÅÂÎ
		//ÂÍÈÇ
		static Image anim_punch_down; anim_punch_down.loadFromFile("NES Slave - Toby Orbon Free Files/Attack/Attack_Pose_South_frame.png");
		static Image anim_walk_down; anim_walk_down.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_South_frame_0.png");
		punch_animation_down.push_back(anim_punch_down);
		punch_animation_down.push_back(anim_punch_down);
		punch_animation_down.push_back(anim_punch_down);
		punch_animation_down.push_back(anim_walk_down);
		//ÂÍÈÇ
		//ÂÂÅÐÕ
		static Image anim_punch_up; anim_punch_up.loadFromFile("NES Slave - Toby Orbon Free Files/Attack/Attack_Pose_North_frame.png");
		static Image anim_walk_up; anim_walk_up.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_North_frame_0.png");
		punch_animation_up.push_back(anim_punch_up);
		punch_animation_up.push_back(anim_punch_up);
		punch_animation_up.push_back(anim_punch_up);
		punch_animation_up.push_back(anim_walk_up);
		//ÂÂÅÐÕ
		punch_animations.push_back(punch_animation_right);
		punch_animations.push_back(punch_animation_left);
		punch_animations.push_back(punch_animation_down);
		punch_animations.push_back(punch_animation_up);
	}
}
Image Punch::getAnimation(Player* hero) {
	if (hero->sost > 3) hero->sost = 0;
	if (hero->frame > 3) hero->frame = 0;
	return punch_animations[hero->sost][hero->frame];
}
Image Punch::getAnimation(Enemy* enemy) {
	if (enemy->sost > 3) enemy->sost = 0;
	if (enemy->frame > 3) enemy->frame = 0;
	return punch_animations[enemy->sost][enemy->frame];
}