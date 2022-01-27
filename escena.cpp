#include "escena.h"
#include "temps_mpjm.h"
#include <typeinfo>
#include <iostream>
escena::escena()
{
}

void escena::update(float elapsed) {
	for (auto e : entidades) {
		e->update(elapsed);
	}
	
	//Para debug----------/
//	for (auto e:a_borrar){
//		std::cout<<"a borrar: "<<e<<std::endl;
//	}
	//--------------------/
	
	t_mpjm::borrar(a_borrar,entidades);
	
	//Para debug----------/
//	for (auto e:entidades){
//		std::cout<<"entidades: "<<e<<std::endl;
//	}
	//--------------------/
	for (auto d : entidades) {
		if (typeid (*d) == typeid (disparo_pj)){
			sf::Vector2f dispPos=d->darPos();
			if(dispPos.y<0){
				std::cout<<"DISPARO FUERA DE PANTALLA"<<std::endl;
				disparosPj_borrar.push_back(d);
				quitar(d);
			}
		}
	}
}
void escena::procesar_evento(const sf::Event &e) {
	
}
void escena::draw(sf::RenderWindow &w) {
	for (auto e : entidades) {
		e->draw(w);
	}	
}
bool escena::termino (){
   return cerrar;
}
void escena::agregar(entidad *e) {
	entidades.push_back(e);
}
void escena::quitar(entidad* e) {
	a_borrar.push_back(e);
}
void escena::libera_memoria(){
	for(int i=0;i<a_borrar.size();i++) { 
		delete a_borrar[i];
        a_borrar[i] = nullptr;
	}
}

void escena::efctoTexto(sf::Text &texto){

        if (reloj.getElapsedTime().asSeconds()>0.5){
		if (texto.getFillColor()==sf::Color::Black){
			texto.setFillColor(sf::Color::White);
			reloj.restart();
		}else{
			texto.setFillColor(sf::Color::Black);
			reloj.restart();
		}
	};

}
