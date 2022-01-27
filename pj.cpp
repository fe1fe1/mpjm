#include "pj.h"
#include "entidad.h"
#include "disparo_pj.h"
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include <SFML/System/Vector2.hpp>

pj::pj(const sf::Vector2f &pos)
{
	texPjIdle.loadFromFile("assets/texturas/YeOldyNecroGuy_idle_ninguno.png");
	texPjRun.loadFromFile("assets/texturas/YeOldyNecroGuy_walk_ninguno.png");
	
	spPjIdle.setTexture(texPjIdle);
	spPjIdle.setPosition(pos);
	spPjIdle.setScale(3,3);
	spPjIdle.setColor(sf::Color::White);
	
	spPjRun.setTexture(texPjRun);
	spPjRun.setPosition(pos);
	spPjRun.setScale(3,3);
	spPjRun.setColor(sf::Color::White);
	
	sf::Vector2u cantIdle(4,1);
	sf::Vector2u cantRun(6,1);
	animacionIdle = new Animacion (texPjIdle.getSize(),0.5,cantIdle);
	animacionRun = new Animacion (texPjRun.getSize(),0.5,cantRun);
}
void pj::update(float elapsed) {
	sf::Vector2f pj_pos;
	spPjIdle.setOrigin(animacionIdle->getTexSize().x/2,animacionIdle->getTexSize().y/2);
	spPjRun.setOrigin(animacionRun->getTexSize().x/2,animacionRun->getTexSize().y/2);
	//------------------------------------------------------------------------------------------------------------
	// MOVIMIWNTO DEL PJ:
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		spPjRun.move(-pj_vel, 0);
		spPjRun.setScale(-3,3);
		spPjIdle.setScale(-3,3);
		corriendo=true;
		deLado=true;
		pj_pos=spPjRun.getPosition();
		animacionIdle->reset();
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			spPjRun.move(pj_vel, 0);
			spPjRun.setScale(3,3);
			spPjIdle.setScale(3,3);
			pj_pos=spPjRun.getPosition();
			corriendo=true;
			deLado=false;
			animacionIdle->reset();
		}else{corriendo=false; animacionRun->reset();pj_pos=spPjRun.getPosition();}
	}
	//------------------------------------------------------------------------------------------------------------
	// CORRECCION DE POSICION DEL PJ:
	if (pj_pos.x < 25) pj_pos.x = 25;
	if (pj_pos.x > 615)pj_pos.x = 615;
	
	spPjRun.setPosition(pj_pos);
	spPjIdle.setPosition(pj_pos);
	//------------------------------------------------------------------------------------------------------------
	if(corriendo){
		animacionRun->update(elapsed);
	}else{
		animacionIdle->update(elapsed);
	}
}

bool pj::darOrientacion(){
	return deLado;
}

void pj::draw(sf::RenderWindow &w) {
	if(corriendo){
		spPjRun.setTextureRect(animacionRun->getTexSelected());
	}else{
		spPjIdle.setTextureRect(animacionIdle->getTexSelected());
	}
	if(corriendo){
		w.draw(spPjRun);
	}else{
		w.draw(spPjIdle);
	}
}
sf::FloatRect pj::hitBox(){
	return spPjIdle.getGlobalBounds();
}
sf::Vector2f pj::darPos(){
	return spPjIdle.getPosition();
};

bool pj::pj_disparando (){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		return true;
	}else{
		return false;
	}
}

double pj::darVel_disp (){
	return vel_disp;
}
void pj::efct_invulnerable(){
	//Crea efecto de parpadeo de INVULNERABILIDAD
	if (reloj.getElapsedTime().asSeconds()>0.1){
		if (spPjIdle.getColor()==sf::Color::White){
			spPjIdle.setColor(sf::Color::Transparent);
			reloj.restart();
		}else{
			spPjIdle.setColor(sf::Color::White);
			reloj.restart();
		}
	}
}
void pj::efct_vulnerable(){
	spPjIdle.setColor(sf::Color::White);
}
