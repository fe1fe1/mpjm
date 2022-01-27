#ifndef ANIMACION_H
#define ANIMACION_H
#include "SFML/Graphics.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

class Animacion {

public:
	
	Animacion(sf::Vector2u texTotalSize, float animationTime, sf::Vector2u texCantidad);
	Animacion(sf::Vector2u texTotalSize, float animationTime, sf::Vector2u texCantidad, sf::Vector2u texPosicion);
	
	void update(float elapsed);
	
	sf::IntRect getTexSelected ();
	sf::Vector2u getTexSize();
	sf::Vector2f getPosition();
	void reset();
	~Animacion();

private:
	void texSelect();
	
	unsigned int filaActual=0;
	unsigned int columnaActual=0;
	
	sf::IntRect texRect;
	
	
	sf::Clock reloj;

	float total_time;
	float animationTime;
	float frameTime;
	
	sf::Vector2u texSize;
	sf::Vector2u texCantidad;
	sf::Vector2u framePosicion;
	
};

#endif

