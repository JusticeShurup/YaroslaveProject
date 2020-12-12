
#include <iostream>
#include "Animator.h"
#include <SFML/Graphics.hpp>
#include "Player.h"
#include <vector>
using namespace sf;
View main_view; // Создаю глобальный вид для игрока 
void setPlayerCoordinate(float x , float y) { // Функция отслеживания игрока
    main_view.setCenter(x, y);
}
int main()
{   
    // Создание полоски хп
    Image health_bar; 
    health_bar.loadFromFile("images/healthbar.png");
    Texture health_bar1;
    health_bar1.loadFromImage(health_bar);
    Sprite health_bar2;
    health_bar2.setTexture(health_bar1);
    health_bar2.setPosition(500, 100);
    // Создание полоски хп
    Animator::getInstance();
    float CurrentFrame = 0; // Текущий кадр 
    // Создание персонажа 
    Image image;
    image.loadFromFile("NES Slave - Toby Orbon Free Files/Walk/Walk_South_frame_0.png");
    Player hero(300,300,0,0, 32.0, 32.0, image);
    RenderWindow window(VideoMode(1920, 1080), "Test!");
    hero.setPosition(hero.getCoordinateX(), hero.getCoordinateY());
    main_view.setCenter(hero.getCoordinateX(), hero.getCoordinateY());
    // Создание персонажа 
    Image map_image;
    map_image.loadFromFile("images/map.png");
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    Clock clock;
    main_view.reset(FloatRect(0, 0, 640, 480));
    
    while (window.isOpen())
    {   
        
        float time = clock.getElapsedTime().asMicroseconds(); 
        clock.restart();
        time = time / 800;
        Event event;
        while (window.pollEvent(event)){
           if (event.type == Event::Closed) {
               window.close();
           }
        }
        if (Keyboard::isKeyPressed(Keyboard::W))
        {   
            CurrentFrame += 0.005 * time;
            if (Keyboard::isKeyPressed(Keyboard::LShift)) {
                if (CurrentFrame > 3) CurrentFrame -= 3;
                hero.setSprite(Animator::getInstance()->player_animations[4][CurrentFrame]); // Анимации бега вверх
                hero.sost = 3; hero.speed = 0.1;
                health_bar2.move(0, -0.1 * time); // Передвижение полоски хп вместе с передвижением спрайта игрока
            }
            else {
                if (CurrentFrame > 3) CurrentFrame -= 3;
                hero.setSprite(Animator::getInstance()->player_animations[0][CurrentFrame]); // Вектор класса Аниматор, где 0 - анимации движения вверх
                hero.sost = 3; hero.speed = 0.05;
                health_bar2.move(0, -0.05 * time); // Передвижение полоски хп вместе с передвижением спрайта игрока
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::S))
        {  
            CurrentFrame += 0.005 * time;
            if (Keyboard::isKeyPressed(Keyboard::LShift)) {
                if (CurrentFrame > 3) CurrentFrame -= 3;
                hero.setSprite(Animator::getInstance()->player_animations[5][CurrentFrame]); 
                hero.sost = 2; hero.speed = 0.1;
                health_bar2.move(0, 0.1 * time); // Передвижение полоски хп вместе с передвижением спрайта игрока
            }
            else {
                if (CurrentFrame > 3) CurrentFrame -= 3;
                hero.setSprite(Animator::getInstance()->player_animations[1][CurrentFrame]);
                hero.sost = 2; hero.speed = 0.05;
                health_bar2.move(0, 0.05 * time); // Передвижение полоски хп вместе с передвижением спрайта игрока
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            CurrentFrame += 0.005 * time;
            if (Keyboard::isKeyPressed(Keyboard::LShift)) {
                if (CurrentFrame > 3) CurrentFrame -= 3;
                hero.setSprite(Animator::getInstance()->player_animations[6][CurrentFrame]);
                hero.sost = 1; hero.speed = 0.1;    
                health_bar2.move(-0.1 * time, 0); // Передвижение полоски хп вместе с передвижением спрайта игрока
               
            }
            else {
                if (CurrentFrame > 3) CurrentFrame -= 3;
                hero.setSprite(Animator::getInstance()->player_animations[2][CurrentFrame]);
                hero.sost = 1; hero.speed = 0.05;
                health_bar2.move(-0.05 * time, 0); // Передвижение полоски хп вместе с передвижением спрайта игрока
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            CurrentFrame += 0.005 * time;
            if (Keyboard::isKeyPressed(Keyboard::LShift)) {
                if (CurrentFrame > 3) CurrentFrame -= 3;
                hero.setSprite(Animator::getInstance()->player_animations[7][CurrentFrame]);
                hero.sost = 0; hero.speed = 0.1;
                health_bar2.move(0.1 * time, 0); // Передвижение полоски хп вместе с передвижением спрайта игрока
            }
            else {
                if (CurrentFrame > 3) CurrentFrame -= 3;
                hero.setSprite(Animator::getInstance()->player_animations[3][CurrentFrame]);
                hero.sost = 0; hero.speed = 0.05;
                health_bar2.move(0.05 * time, 0); // Передвижение полоски хп вместе с передвижением спрайта игрока
            }
        }
        hero.Update(time);
        window.clear();
        for (int i = 0; i < HEIGHT_MAP; i++)
            for (int j = 0; j < WIDTH_MAP; j++)
            {
                if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
                if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
                if (TileMap[i][j] == '0') s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
                s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат
                window.draw(s_map);//рисуем квадратики на экран
            }
        window.setView(main_view);
        window.draw(hero.getSprite());
        window.draw(health_bar2);
        window.display();
    }
 
    return 0;
}




