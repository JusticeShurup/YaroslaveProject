#include "Walk.h"
Walk::Walk() : AnimationState() {
    //ÂÏÐÀÂÎ
    static Image anim_right_0; anim_right_0.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_East_frame_0.png");
    static Image anim_right_1; anim_right_1.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_East_frame_1.png");
    static Image anim_right_2; anim_right_2.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_East_frame_2.png");
    static Image anim_right_3; anim_right_3.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_East_frame_3.png");
    walk_animation_right.push_back(anim_right_0);
    walk_animation_right.push_back(anim_right_1);
    walk_animation_right.push_back(anim_right_2);
    walk_animation_right.push_back(anim_right_3);
    //ÂÏÐÀÂÎ
    //ÂËÅÂÎ
    static Image anim_left_0; anim_left_0.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_West_frame_0.png");
    static Image anim_left_1; anim_left_1.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_West_frame_1.png");
    static Image anim_left_2; anim_left_2.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_West_frame_2.png");
    static Image anim_left_3; anim_left_3.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_West_frame_3.png");
    walk_animation_left.push_back(anim_left_0);
    walk_animation_left.push_back(anim_left_1);
    walk_animation_left.push_back(anim_left_2);
    walk_animation_left.push_back(anim_left_3);
    //ÂËÅÂÎ
    //ÂÍÈÇ 
    static Image anim_down_0; anim_down_0.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_South_frame_0.png");
    static Image anim_down_1; anim_down_1.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_South_frame_1.png");
    static Image anim_down_2; anim_down_2.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_South_frame_2.png");
    static Image anim_down_3; anim_down_3.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_South_frame_3.png");
    walk_animation_down.push_back(anim_down_0);
    walk_animation_down.push_back(anim_down_1);
    walk_animation_down.push_back(anim_down_2);
    walk_animation_down.push_back(anim_down_3);
    //ÂÍÈÇ 
    //ÂÂÅÐÕ 
    static Image anim_up_0; anim_up_0.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_North_frame_0.png");
    static Image anim_up_1; anim_up_1.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_North_frame_1.png");
    static Image anim_up_2; anim_up_2.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_North_frame_2.png");
    static Image anim_up_3; anim_up_3.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_North_frame_3.png");
    walk_animation_up.push_back(anim_up_0);
    walk_animation_up.push_back(anim_up_1);
    walk_animation_up.push_back(anim_up_2);
    walk_animation_up.push_back(anim_up_3);
    //ÂÂÅÐÕ 

    walk_animations.push_back(walk_animation_right);
    walk_animations.push_back(walk_animation_left);
    walk_animations.push_back(walk_animation_down);
    walk_animations.push_back(walk_animation_up);
}
Image Walk::getAnimation(Player* hero) {
    if (hero->sost > 3) hero ->sost = 0;
    if (hero->frame > 3) hero->frame = 0;
    return walk_animations[hero->sost][hero->frame];
}
Image Walk::getAnimation(Enemy* enemy) {
    if (enemy->sost > 3) enemy->sost = 0;
    if (enemy->frame > 3) enemy->frame = 0;
    return walk_animations[enemy->sost][enemy->frame];
}