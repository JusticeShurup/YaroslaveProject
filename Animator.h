#ifndef _ANIMATOR_H_
#define _ANIMATOR_H_
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
class Animator
{
public:
	static Animator* getInstance();
	std::vector < std::vector<Image>> player_animations;
private:
	static Animator* instance;
	Animator();
};
#endif

