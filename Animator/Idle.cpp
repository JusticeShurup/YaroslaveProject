#include "Idle.h"
Idle::Idle() {
	//ÂÏÐÀÂÎ
	static Image anim_idle_right_0; anim_idle_right_0.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_East_frame_0.png");
	static Image anim_idle_right_1; anim_idle_right_1.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_East_frame_1.png");
	static Image anim_idle_right_2; anim_idle_right_2.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_East_frame_2.png");
	static Image anim_idle_right_3; anim_idle_right_3.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_East_frame_3.png");
	idle_animation_right = { anim_idle_right_0, anim_idle_right_1, anim_idle_right_2, anim_idle_right_3 };
	//ÂÏÐÀÂÎ
	//ÂËÅÂÎ
	static Image anim_idle_left_0; anim_idle_left_0.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_West_frame_0.png");
	static Image anim_idle_left_1; anim_idle_left_1.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_West_frame_1.png");
	static Image anim_idle_left_2; anim_idle_left_2.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_West_frame_2.png");
	static Image anim_idle_left_3; anim_idle_left_3.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_West_frame_3.png");
	idle_animation_left = { anim_idle_left_0, anim_idle_left_1, anim_idle_left_2, anim_idle_left_3 };
	//ÂËÅÂÎ
	//ÂÍÈÇ
	static Image anim_idle_down_0; anim_idle_down_0.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_South_frame_0.png");
	static Image anim_idle_down_1; anim_idle_down_1.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_South_frame_1.png");
	static Image anim_idle_down_2; anim_idle_down_2.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_South_frame_2.png");
	static Image anim_idle_down_3; anim_idle_down_3.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_South_frame_3.png");
	idle_animation_down = { anim_idle_down_0, anim_idle_down_1, anim_idle_down_2, anim_idle_down_3 };
	//ÂÍÈÇ
	//ÂÂÅÐÕ
	static Image anim_idle_up_0; anim_idle_up_0.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_North_frame_0.png");
	static Image anim_idle_up_1; anim_idle_up_1.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_North_frame_1.png");
	static Image anim_idle_up_2; anim_idle_up_2.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_North_frame_2.png");
	static Image anim_idle_up_3; anim_idle_up_3.loadFromFile("NES Slave - Toby Orbon Free Files/Idle/Idle_North_frame_3.png");
	idle_animation_up = { anim_idle_up_0, anim_idle_up_1, anim_idle_up_2, anim_idle_up_3 };
	//ÂÂÅÐÕ
	idle_animations = { idle_animation_right, idle_animation_left, idle_animation_down, idle_animation_up };
}
Image Idle::getAnimation(Player* hero) {
	return idle_animations[hero->sost][hero->frame];
}
Image Idle::getAnimation(Enemy* enemy) {
	return idle_animations[enemy->sost][enemy->frame];
}
