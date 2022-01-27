#include "bola_lvl1.h"
#include <cmath>
#include <iostream>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include "global.h"
using namespace std;
bola_lvl1::bola_lvl1(const sf::Vector2f &pos,int direccion,int tier,sf::Vector2f pjpos,sf::Sound rebote) {
	texBolaLvl1.loadFromFile("assets/texturas/bola_tailed.png");
	
	reboteSound=rebote;
	
	spBolaLvl1.setTexture(texBolaLvl1);
	spBolaLvl1.setPosition(pos.x,pos.y);
	
	this->tier=tier;
	this->direccion=direccion;
	
	//-------------------------------------------------------------------------
	// DIRECCION, ESCALA Y VELOCIDAD SEGUN TIER (3,2,1) DE BOLA LVL 1:}
	switch (tier){
	case 3: 
		velBola.x=6*direccion; velBola.y=8*direccion; spBolaLvl1.setScale(2,2); animTemp=0.15;
		break;
	case 2:
		velBola.x=4*direccion; velBola.y=6*direccion; spBolaLvl1.setScale(4,4); animTemp=0.35;
		break;
	case 1:
		velBola.x=2*direccion; velBola.y=4*direccion; spBolaLvl1.setScale(6,6); animTemp=0.5;
		break;
	}
	//-------------------------------------------------------------------------
	sf::Vector2u cant(6,1);
	animacionBola = new Animacion(texBolaLvl1.getSize(),animTemp,cant);
}
void bola_lvl1::update(float elapsed){
	spBolaLvl1.setOrigin((animacionBola->getTexSize().x)/2,animacionBola->getTexSize().y/2);
	spBolaLvl1.move(velBola);
	bolaPos=spBolaLvl1.getPosition();
	//-------------------------------------------------------------------------
	// LOGICA DE MOVIMIENTO Y POSICION SEGUN TIER (3,2,1) DE BOLA LVL 1:
	switch (tier){
	case 3:
		//Corrije la posicion en caso de que se pase por el margen superior,inferior,izquierdo,derecho
		spBolaLvl1.setRotation(spBolaLvl1.getRotation()+10);
		if (bolaPos.y<16){ bolaPos.y=16; velBola.y*=-1;   /*reboteSound.play(); */}
		if (bolaPos.y>320){ bolaPos.y=320; velBola.y*=-1; /*reboteSound.play(); */}
		if (bolaPos.x<16){ bolaPos.x=16; velBola.x*=-1;   /*reboteSound.play(); */}
		if (bolaPos.x>624){ bolaPos.x=624; velBola.x*=-1; /*reboteSound.play(); */}
		break;
	case 2:
		//Corrije la posicion en caso de que se pase por el margen superior,inferior,izquierdo,derecho
		spBolaLvl1.setRotation(spBolaLvl1.getRotation()+6);
		if (bolaPos.y<32){ bolaPos.y=32; velBola.y*=-1;   /*reboteSound.play(); */}
		if (bolaPos.y>310){ bolaPos.y=310; velBola.y*=-1; /*reboteSound.play(); */}
		if (bolaPos.x<32){ bolaPos.x=32; velBola.x*=-1;   /*reboteSound.play(); */}
		if (bolaPos.x>608){ bolaPos.x=608; velBola.x*=-1; /*reboteSound.play(); */}	
		break;
	case 1:
		//Corrije la posicion en caso de que se pase por el margen superior,inferior,izquierdo,derecho
		spBolaLvl1.setRotation(spBolaLvl1.getRotation()+2);
		if (bolaPos.y<48){bolaPos.y=48; velBola.y*=-1;    /*reboteSound.play(); */}
		if (bolaPos.y>295){ bolaPos.y=295; velBola.y*=-1; /*reboteSound.play(); */}
		if (bolaPos.x<48){ bolaPos.x=48; velBola.x*=-1;   /*reboteSound.play(); */}
		if (bolaPos.x>592){ bolaPos.x=592; velBola.x*=-1; /*reboteSound.play(); */}	
		break; 
	}
	spBolaLvl1.setPosition(bolaPos);
	animacionBola->update(elapsed);
	//-------------------------------------------------------------------------
	

}


void bola_lvl1::draw(sf::RenderWindow &w){
	spBolaLvl1.setTextureRect(animacionBola->getTexSelected());
	w.draw(spBolaLvl1);
}
int bola_lvl1::darTier(){
	return tier;
}
int bola_lvl1::darDireccion(){
	return direccion;
}
sf::Vector2f bola_lvl1::darPos(){
	return bolaPos;
}
sf::FloatRect bola_lvl1::hitBox(){
	return spBolaLvl1.getGlobalBounds();
}
