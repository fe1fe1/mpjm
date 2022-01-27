#ifndef PJ_H
#define PJ_H

#include "entidad.h"
#include "disparo_pj.h"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include "Animacion.h"
class pj :
	public entidad
{
public:
	pj(const sf::Vector2f &pos);
	
	void update(float elapsed) override;
	void draw(sf::RenderWindow &w) override;
	
	sf::FloatRect hitBox() override;
	sf::Vector2f darPos() override;
	
	bool darOrientacion();
	bool pj_disparando();
	double darVel_disp ();
	
	void efct_invulnerable(); 
	void efct_vulnerable();
	
	
private:
	bool deLado=false;
	bool corriendo=false;
	
	Animacion* animacionIdle;
	Animacion* animacionRun;
	
	sf::Clock reloj;
	sf::Vector2f pj_pos;
	
	sf::Texture texPj;
	sf::Sprite spPj;
	
	sf::Texture texPjIdle;
	sf::Sprite spPjIdle;
	
	sf::Texture texPjRun;
	sf::Sprite spPjRun;
	
	double vel_disp = 0.5;
	const float pj_vel = 8;
};
	
#endif
	
