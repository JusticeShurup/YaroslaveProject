#include "Run.h"
Run::Run() : AnimationState() {
    //ÂÏÐÀÂÎ
    static Image anim_right_run_0; anim_right_run_0.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_East_frame_0.png");
    static Image anim_right_run_1; anim_right_run_1.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_East_frame_1.png");
    static Image anim_right_run_2; anim_right_run_2.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_East_frame_2.png");
    static Image anim_right_run_3; anim_right_run_3.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_East_frame_3.png");
    run_animation_right.push_back(anim_right_run_0);
    run_animation_right.push_back(anim_right_run_1);
    run_animation_right.push_back(anim_right_run_2);
    run_animation_right.push_back(anim_right_run_3);
    //ÂÏÐÀÂÎ
    //ÂËÅÂÎ
    static Image anim_left_run_0; anim_left_run_0.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_West_frame_0.png");
    static Image anim_left_run_1; anim_left_run_1.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_West_frame_1.png");
    static Image anim_left_run_2; anim_left_run_2.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_West_frame_2.png");
    static Image anim_left_run_3; anim_left_run_3.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_West_frame_3.png");
    run_animation_left.push_back(anim_left_run_0);
    run_animation_left.push_back(anim_left_run_1);
    run_animation_left.push_back(anim_left_run_2);
    run_animation_left.push_back(anim_left_run_3);
    //ÂËÅÂÎ
    //ÂÍÈÇ
    static Image anim_down_run_0; anim_down_run_0.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_South_frame_0.png");
    static Image anim_down_run_1; anim_down_run_1.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_South_frame_1.png");
    static Image anim_down_run_2; anim_down_run_2.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_South_frame_2.png");
    static Image anim_down_run_3; anim_down_run_3.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_South_frame_3.png");
    run_animation_down.push_back(anim_down_run_0);
    run_animation_down.push_back(anim_down_run_1);
    run_animation_down.push_back(anim_down_run_2);
    run_animation_down.push_back(anim_down_run_3);
    //ÂÍÈÇ
    //ÂÂÅÐÕ
    static Image anim_up_run_0; anim_up_run_0.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_North_frame_3.png");
    static Image anim_up_run_1; anim_up_run_1.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_North_frame_1.png");
    static Image anim_up_run_2; anim_up_run_2.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_North_frame_2.png");
    static Image anim_up_run_3; anim_up_run_3.loadFromFile("NES Slave - Toby Orbon Free Files/Run/Run_North_frame_0.png");
    run_animation_up.push_back(anim_up_run_0);
    run_animation_up.push_back(anim_up_run_1);
    run_animation_up.push_back(anim_up_run_2);
    run_animation_up.push_back(anim_up_run_3);
    //ÂÂÅÐÕ 
    run_animations.push_back(run_animation_right);
    run_animations.push_back(run_animation_left);
    run_animations.push_back(run_animation_down);
    run_animations.push_back(run_animation_up);
}

Image Run::getAnimation(Player* hero) {
    if (hero->sost > 3) hero->sost = 0;
    if (hero->frame > 3) hero->frame = 0;
    return run_animations[hero->sost][hero->frame];
}

Image Run::getAnimation(Enemy* enemy) {
    if (enemy->sost > 3) enemy->sost = 0;
    if (enemy->frame > 3) enemy->frame = 0;
    return run_animations[enemy->sost][enemy->frame];
}
