#ifndef ESCENA_JUEGO_H
#define ESCENA_JUEGO_H
#include "escena.h"
#include "bola_lvl1.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "nivel_1.h"
#include <vector>
class escena_juego :
	public escena
{
public:
	escena_juego();
	void update(float elapsed);
	void draw(sf::RenderWindow &w);
	int lvl;
	
private:
	nivel_1 *lvl1=nullptr;
};
	
	
#endif
