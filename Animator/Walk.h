#ifndef _WALK_H_
#define _WALK_H_
#include "AnimationState.h"
class Walk : // Состояние ходьба 
    public AnimationState
{
public: 
    Walk();
    virtual Image getAnimation(Player* hero) override;
    virtual Image getAnimation(Enemy* enemy) override;
    ~Walk();
private: 
    std::vector<std::vector<Image>> walk_animations;
    std::vector<Image> walk_animation_right; // 0 номер в массиве
    std::vector<Image> walk_animation_left;  // 1 номер в массиве
    std::vector<Image> walk_animation_down;  // 2 номер в массиве 
    std::vector<Image> walk_animation_up;    // 3 номер в массиве
};
#endif
