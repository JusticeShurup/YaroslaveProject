#pragma once
#include "AnimationState.h"
class Hurt :
    public AnimationState
{
public:
    Hurt();
    virtual Image getAnimation(Player*) override;
    virtual Image getAnimation(Enemy*) override;
private:
    std::vector<std::vector<Image>> hurt_animations;
    std::vector<Image> hurt_animation_right;
    std::vector<Image> hurt_animation_left;
    std::vector<Image> hurt_animation_down;
    std::vector<Image> hurt_animation_up;
};

