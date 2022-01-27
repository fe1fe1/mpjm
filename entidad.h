#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <SFML/Graphics/RenderWindow.hpp>
class entidad
{
public:
	entidad();
	virtual void update(float elapsed) = 0;
	virtual void draw(sf::RenderWindow &w) = 0;
	virtual sf::Vector2f darPos() = 0;
	virtual sf::FloatRect hitBox() = 0;
};

#endif
