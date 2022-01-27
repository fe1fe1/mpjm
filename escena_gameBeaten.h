#ifndef ESCENA_GAMEBEATEN_H
#define ESCENA_GAMEBEATEN_H 
#include "escena.h"
#include "escena_menu.h"
#include <iostream>
#include "juego.h"
#include "escena_juego.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Event.hpp>
#include <sstream>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include <string>
#include <SFML/Graphics/Color.hpp>
#include "global.h"

class escena_gameBeaten : public escena {
public:
    escena_gameBeaten();
    void update (float elapsed);
    void draw (sf::RenderWindow & w);
private:
    sf::Music soundTrack;

    sf::Texture fondoGameBeatenTex;
	sf::Sprite fondoGameBeatenSp;

	std::stringstream ss_score;
	std::stringstream ss_highscore;

    sf::Font gameBeatenFont;
    sf::Text gameBeatenText;
    sf::Text presionaEscape;  
    sf::Text pressSpace;
    sf::Text scoreText;
	sf::Text highscoreText;


};

#endif
