#include "map.h"
Map::Map() { // ���������� �������� � ���������
	image.loadFromFile("Images/map.png");
	texture.loadFromImage(image);
	sprite.setTexture(texture);
}
void Map::drawMap(RenderWindow* window){
    for (int i = 0; i < HEIGHT_MAP; i++)
        for (int j = 0; j < WIDTH_MAP; j++)
        {
            if (TileMap[i][j] == ' ')  sprite.setTextureRect(IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
            if (TileMap[i][j] == '0')  sprite.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������
            sprite.setPosition(j * 32, i * 32);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
            window->draw(sprite);
        }   
}