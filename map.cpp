#include "map.h"
Map::Map() { // присвоение картинки и блаблабла
	image.loadFromFile("Images/map.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}
void Map::drawMap(RenderWindow* window){
    for (int i = 0; i < HEIGHT_MAP; i++)
        for (int j = 0; j < WIDTH_MAP; j++)
        {
            if (TileMap[i][j] == ' ')  sprite.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
            if (TileMap[i][j] == '0')  sprite.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
            sprite.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат
            window->draw(sprite);
        }   
}