#ifndef _MAP_H_
#define	_MAP_H_
#include <SFML/Graphics.hpp>
const int HEIGHT_MAP = 25; // Высота карты
const int WIDTH_MAP = 40; // Ширина карты
using namespace sf;
class Map{
public:
	String TileMap[HEIGHT_MAP] = {
	"0000000000000000000000000000000000000000",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0000000000000000000000000000000000000000",
	};
	Map();
	void drawMap(RenderWindow* window);
private:
	Image image;
	Texture texture;
	Sprite sprite;
};
#endif



