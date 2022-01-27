#ifndef ESCENA_MENU_H
#define ESCENA_MENU_H
#include "escena.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>

class escena_menu : public escena {
public:
	escena_menu();
	void update (float elapsed);
	void procesar_evento (const sf::Event & e);
	void draw (sf::RenderWindow & w);
private:
	int color = 1;
	double tiempo = 1.5;
	
	sf::Music soundTrack;
	sf::SoundBuffer pressBuffer;
	sf::Sound pressSound;
	
	sf::Texture fondoMenuTex;
	sf::Sprite fondoMenuSp;
	
	sf::Text tituloText;
	sf::Text presionaEspacioText;
	sf::Font menuFont;
};

#endif

