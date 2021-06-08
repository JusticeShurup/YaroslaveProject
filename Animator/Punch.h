#ifndef _PUNCH_H_
#define _PUNCH_H_
#include "AnimationState.h"
class Punch :
    public AnimationState
{
public:
    Punch();
    virtual Image getAnimation(Player* hero) override;
    virtual Image getAnimation(Enemy* enemy) override;
private: 
    std::vector<std::vector<Image>> punch_animations;
    std::vector<Image> punch_animation_right;
    std::vector<Image> punch_animation_left;
    std::vector<Image> punch_animation_down;
    std::vector<Image> punch_animation_up;
};
#endif

