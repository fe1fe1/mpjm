#ifndef DISPARO_PJ_H
#define DISPARO_PJ_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <tuple>
#include "entidad.h"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
class disparo_pj:public
	entidad
{
public:
	void update(float elapsed);
	void draw(sf::RenderWindow &w);
	disparo_pj(const sf::Vector2f &disp_pos, bool deLado);
	sf::Vector2f darPos() override;
	sf::FloatRect hitBox() override;
private:
	sf::Texture texDispPj;
	sf::Sprite spDispPj;
};
	
#endif
	
