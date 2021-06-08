#ifndef ENEMY_AI
#define ENEMY_AI
#include "Enemy.h"
class EnemyAI
{
public:
	EnemyAI(Enemy *enemy);
	void doPunch();
	void run();
	void walk();
private:
	Enemy* enemy;

};
#endif
