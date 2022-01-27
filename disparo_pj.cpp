#include "disparo_pj.h"
#include <iostream>


disparo_pj::disparo_pj(const sf::Vector2f &disp_pj_pos, bool deLado)

{
	texDispPj.loadFromFile("assets/texturas/nuevo_disp.png");
	spDispPj.setTexture(texDispPj);
	if (!deLado) spDispPj.setPosition(disp_pj_pos.x+20,disp_pj_pos.y-30);
	else spDispPj.setPosition(disp_pj_pos.x-20,disp_pj_pos.y-30);
	spDispPj.setScale(0.5, 0.5);
	spDispPj.setOrigin(texDispPj.getSize().x/2,texDispPj.getSize().y/2);
}

void disparo_pj::update(float elapsed) {
	spDispPj.move(0,-20);
	std::cout<<"disparo existente"<<std::endl;
}
sf::Vector2f disparo_pj::darPos() {
	return spDispPj.getPosition();
}
void disparo_pj::draw(sf::RenderWindow &w) {
	w.draw(spDispPj); 
}
sf::FloatRect disparo_pj::hitBox(){
	return spDispPj.getGlobalBounds();
}
