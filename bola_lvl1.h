#ifndef BOLA_LVL1_H
#define BOLA_LVL1_H

#include "entidad.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Animacion.h"


class bola_lvl1: 
	public entidad 
{
public:
	bola_lvl1(const sf::Vector2f &pos,int direccion,int tier,sf::Vector2f pjpos,sf::Sound rebote);
	
	void update(float elapsed) override;
	void draw(sf::RenderWindow &w) override;
	
	sf::Vector2f darPos() override;
	sf::FloatRect hitBox() override;
	
	int darDireccion();
	int darTier();
	
	sf::Sprite spBolaLvl1;
	sf::Texture texBolaLvl1; 
private:
	Animacion* animacionBola;
	float animTemp;
	
	sf::SoundBuffer reboteBuffer;
	sf::Sound reboteSound;
	
	sf::Vector2f estirar;
	sf::Vector2f velBola;
	sf::Vector2f bolaPos;
	
	
	
	int tier;
	int direccion;
};

#endif

