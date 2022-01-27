#include "juego.h"
#include <iostream>
#include <string>
#include <fstream>
#include "global.h"
#include "player.h"
using namespace std;
juego* instancia = nullptr;
juego::juego()
{
}
	

juego &juego::crear(const sf::VideoMode &videomode, escena* escena, const std::string &nombre) {
	if (instancia) {
		std::cerr << "Error: el juego ya se esta ejecutando.";
	}
	else {
		juego &j = darInstancia();
		j.ventana.create(videomode, nombre, sf::Style::Close);
		j.escena_siguiente = nullptr;
		j.escena_actual = escena;
		j.ventana.setFramerateLimit(60);
		
	}
	return darInstancia();
}

juego &juego::darInstancia() {
	if (!instancia) {
		instancia = new juego();
	}
	return *instancia;
}

void juego::actualizarScore (){
	
	fstream archi("puntajes.bin",ios::binary|ios::in|ios::out|ios::ate);
	if (!archi.is_open()){
		std::cerr<<"ERROR: No se puedo abrir el archivo puntajes.bin, se generaro uno nuevo.";
		archi.close();
		ofstream generar ("puntajes.bin",ios::binary);
		generar.close();
		archi.open("puntajes.bin",ios::binary|ios::in|ios::out|ios::ate);
	}
	int tam_archi = archi.tellg();
	int size = tam_archi/sizeof(player);
	archi.seekg(0);
	
	for(int i=0;i<size;i++) { 
		player j;
		archi.read(reinterpret_cast<char*>(&j), sizeof(player));
		if (j.puntuacion>global::highscore){
			global::highscore=j.puntuacion;
			global::highscore_name=j.name;
		}
	}
	archi.close();
}

void juego::correr() {
	
	while (ventana.isOpen() && escena_actual != nullptr) {
		sf::Event e;
		while (ventana.pollEvent(e)) {
			if (e.type == sf::Event::Closed) {
//				archi.write(reinterpret_cast<char*>(&global::jugador), sizeof(player));
//				archi.close();
				ventana.close();
			}
			else {
				escena_actual->procesar_evento(e);
			}
		}
		update();
		draw();
		if (escena_siguiente != nullptr) {
			delete escena_actual;
			escena_actual= escena_siguiente;
			escena_siguiente = nullptr;
			
		}
	}
}

void juego::update() {
	escena_actual->update(clock.getElapsedTime().asSeconds());
//	if (escena_actual->termino()){
//		ventana.close();
//	}
	clock.restart();
}

void juego::draw() {
	ventana.clear(sf::Color(0, 0, 0, 255));
	escena_actual->draw(ventana);
	ventana.display();
}
//PARA GUARDAR 
void juego::guardarScore (){
	fstream archi ("puntajes.bin",ios::binary|ios::in|ios::out|ios::ate);
	archi.write(reinterpret_cast<char*>(&global::jugador), sizeof(player));
	archi.close();
	
}
void juego::cambiar_escena(escena* escena){
	escena_siguiente=escena;
}
