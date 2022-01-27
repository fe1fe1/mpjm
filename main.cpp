#include <SFML/Window/VideoMode.hpp>
#include <vector>
#include "escena.h"
#include "juego.h"
#include "escena_juego.h"
#include "escena_menu.h"
#include "escena_gameOver.h"
#include "global.h"
int main()
{
	escena *escena = new escena_menu();
	juego &j = juego::crear(sf::VideoMode(640, 400), escena, "IntentoSFML");
	j.correr();
	return 0;
}


