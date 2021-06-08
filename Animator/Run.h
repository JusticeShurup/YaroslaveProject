#ifndef _RUN_H_
#define _RUN_H_
#include "AnimationState.h"
class Run :
    public AnimationState
{
public:
    Run();
    virtual Image getAnimation(Player* hero) override;
    virtual Image getAnimation(Enemy* hero) override;
private: 
    std::vector<std::vector<Image>> run_animations;
    std::vector<Image> run_animation_right;
    std::vector<Image> run_animation_left;
    std::vector<Image> run_animation_down;
    std::vector<Image> run_animation_up;
};
#endif

