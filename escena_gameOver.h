#ifndef ESCENA_GAMEOVER_H
#define ESCENA_GAMEOVER_H
#include "escena.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <sstream>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/Music.hpp>
#include <string>
#include "InputBox.h"
#include <SFML/Graphics/Color.hpp>
using namespace std;

class escena_gameOver : public escena {
public:
	escena_gameOver();
	void update (float elapsed);
	void procesar_evento (const sf::Event & e);
	void draw (sf::RenderWindow & w);
private:
	sf::Music soundTrack;
	
	sf::SoundBuffer pressBuffer;
	sf::Sound pressSound;
	
	sf::Texture fondoGameOverTex;
	sf::Sprite fondoGamneOverSp;
	
	string stringLetrasNombre;
	
	std::stringstream ss_highscore;
	std::stringstream ss_score;
	
	InputText entradaNombre;
	
	sf::Text letrasNombreText;
	
	sf::Text gameOverText;
	sf::Text presionaEscapeText;
	sf::Text scoreText;
	sf::Text highscoreText;
	sf::Font gameOverFont;
};

#endif

