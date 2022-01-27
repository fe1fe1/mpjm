#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include "escena.h"
#include <string>
#include <SFML/Audio/Music.hpp>
#include "player.h"
#include <fstream>
using namespace std;
class juego
{
public:
	
	void correr();
	void cambiar_escena(escena* escena);
	static juego &darInstancia();
	static juego &crear(const sf::VideoMode &videomode, escena* escena, const std::string &nombre);
	static void guardarScore ();
	static void actualizarScore();
private:
	escena *escena_actual, *escena_siguiente;
	sf::RenderWindow ventana;
	void iniciar_juego();
	void update();
	void draw();
	sf::Clock clock;
	juego();
	};

#endif
