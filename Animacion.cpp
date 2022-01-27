#include "Animacion.h"
#include <iostream>

Animacion::Animacion(sf::Vector2u texTotalSize, float animationTime, sf::Vector2u texCantidad) {
	
	if(texCantidad.x==0||texCantidad.y==0) std::cerr<<"texCantidad TIENE QUE SER > 0"<<std::endl;
	
	total_time=0;
	this->texCantidad=texCantidad;
	frameTime=animationTime/texCantidad.x*texCantidad.y;
	
	texSize.x=(texTotalSize.x/texCantidad.x);
	texSize.y=(texTotalSize.y/texCantidad.y);
	
	this->framePosicion.x=0;
	this->framePosicion.y=0;
	
	
	texRect.height=texSize.y;
	texRect.width=texSize.x;
	
}

Animacion::Animacion(sf::Vector2u texTotalSize, float animationTime, sf::Vector2u texCantidad, sf::Vector2u framePosicion) {
	
	if(texCantidad.x==0||texCantidad.y==0) std::cerr<<"texCantidad TIENE QUE SER > 0"<<std::endl;
	
	total_time=0;
	this->texCantidad=texCantidad;
	frameTime=animationTime/texCantidad.x*texCantidad.y;
	
	texSize.x=(texTotalSize.x/texCantidad.x);
	texSize.y=(texTotalSize.y/texCantidad.y);
	
	this->framePosicion.x=framePosicion.x-1;
	this->framePosicion.y=framePosicion.y-1;
	
	texRect.width=texSize.x;
	texRect.height=texSize.y;
}

void Animacion::update(float elapsed){
	total_time+=elapsed;
	if (total_time >= frameTime){
		total_time-=frameTime;
		if (framePosicion.x<texCantidad.x-1){
			framePosicion.x++;
		}else{
			reset();
		}
	}
	texRect.left=framePosicion.x*texRect.width;
	texRect.top=framePosicion.y*texRect.height;
}

void Animacion::reset (){
	framePosicion.x=0;
}

sf::Vector2f Animacion::getPosition(){
	sf::Vector2f pos (framePosicion);
	return pos;
}

sf::Vector2u Animacion::getTexSize(){
	return texSize;
}

sf::IntRect Animacion::getTexSelected(){
	return texRect;
}

void Animacion::texSelect(){
	texRect.left=(texSize.x*columnaActual);
	texRect.top=(texSize.y*filaActual);
}


Animacion::~Animacion() {
	
}















