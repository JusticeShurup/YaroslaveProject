#include <iostream>

#include "Animator/Hurt.h"
#include "Animator/Animator.h"
#include "Animator/AnimationState.h"
#include "Animator/Idle.h"
#include "Animator/Walk.h"
#include "Animator/Run.h"
#include "Animator/Punch.h"

#include "map.h"
#include <vector>
#include "Controller.h"
#include "Enemy.h"
using namespace sf;
View main_view; // Создаю глобальный вид для игрока 
void setPlayerView(Player* hero) { // Функция отслеживания игрока
    main_view.setCenter(hero->getCoordinateX(), hero->getCoordinateY());
}
int main()
{   
    Map map;
    Animator::getInstance();
    Controller::getInstance();
    HUD hud;
    float CurrentFrame = 0; // Текущий кадр
    // Создание врага
    // Создание врага 
    // Создание персонажа 
    Player hero(300,300,100,100, 32, 32, "NES Slave - Toby Orbon Free Files/Walk/Walk_North_frame_0.png");
    RenderWindow window(VideoMode(1920, 1080), "Test!");
    hero.setPosition(hero.getCoordinateX(), hero.getCoordinateY());
    Controller::getInstance()->setPlayer(&hero);
    main_view.setCenter(hero.getCoordinateX(), hero.getCoordinateY());
    Controller::getInstance()->setHUD(&hud);
    // Создание персонажа 
    Clock clock;
    main_view.reset(FloatRect(0, 0, 640, 480)); // 640 480
 
    while (window.isOpen())
    {   
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;
        CurrentFrame += 0.005f * time;
        if (CurrentFrame > 3) CurrentFrame = 0;
        hero.frame = CurrentFrame;
        if(Controller::getInstance()->getEnemy()!=nullptr)
            Controller::getInstance()->getEnemy()->frame = CurrentFrame;
        Controller::getInstance()->playerUpdate(time, &map);
        Animator::getInstance()->setAnimation(&hero, Controller::getInstance()->getAnimationState());
        if(Controller::getInstance()->getEnemy() != nullptr)
            Controller::getInstance()->getEnemy()->Update(time, &map, &hero);
        if (Controller::getInstance()->getEnemy() != nullptr) 
            Animator::getInstance()->setAnimation(Controller::getInstance()->getEnemy());
        setPlayerView(&hero);
        window.clear();
        Controller::getInstance()->getHUD()->HUDupdate(&hero);
        Controller::getInstance()->getHUD()->sostBar();
        map.drawMap(&window);
        window.draw(Controller::getInstance()->getHUD()->getHP_bar_sprite());
        window.draw(Controller::getInstance()->getHUD()->getStamina_bar_sprite());
        window.setView(main_view);
        window.draw(hero.getSprite());
        if (Controller::getInstance()->getEnemy() != nullptr) {
            window.draw(Controller::getInstance()->getEnemy()->getSprite());
            window.draw(Controller::getInstance()->getEnemy()->getHP_bar());
        }
        window.display();

    }
 
    return 0;
}




