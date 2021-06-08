#ifndef _IDLE_H_
#define _IDLE_H_
#include "AnimationState.h"
class Idle :
    public AnimationState
{
public: 
    Idle();
    virtual Image getAnimation(Player* hero) override;
    virtual Image getAnimation(Enemy* enemy) override;
private: 
    std::vector<std::vector<Image>> idle_animations;
    std::vector<Image> idle_animation_right;
    std::vector<Image> idle_animation_left;
    std::vector<Image> idle_animation_down;
    std::vector<Image> idle_animation_up;
};
#endif
