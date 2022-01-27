#include "escena_gameOver.h"
#include <SFML/Window/Keyboard.hpp>
#include "escena_menu.h"
#include "juego.h"
#include "global.h"
#include <iostream>
#include <cstring>
using namespace std;

escena_gameOver::escena_gameOver() {
	if(!soundTrack.openFromFile("assets/soundTracks/song_of_storms_piano.ogg")){
		std::cerr<<"ERROR: No se encontro el song_of_storms_piano.ogg en la ruta [assets/soundTracks/song_of_storms_piano.ogg]"<<std::endl;
	}
	soundTrack.setVolume(100);
	soundTrack.play();
	if(!fondoGameOverTex.loadFromFile("assets/texturas/fondoGameOver.png")){
		std::cerr<<"ERROR: No se encontro el archivo fondoGameOver.png en la ruta [assets/texturas/fondoGameOver.png]"<<std::endl;
	}
	fondoGamneOverSp.setTexture(fondoGameOverTex);
	
	if (!pressBuffer.loadFromFile("assets/soundEfects/press_to_continue.wav")){
		std::cerr<<"ERROR: No se encontro el archivo press_to_continue.wav en la ruta [assets/soundEfects/press_to_continue.wav]"<<std::endl;
	}
	pressSound.setBuffer(pressBuffer);
	
	if(!gameOverFont.loadFromFile("assets/fuentes/Cave-Story.ttf")){
		std::cerr<<"ERROR: No se encontro el archivo Cave-Story.ttf en la ruta [assets/fuentes/Cave-Story.ttf]"<<std::endl;
	}
	gameOverText.setFont(gameOverFont);
	gameOverText.setFillColor(sf::Color::Black);
	gameOverText.setString("Game Over");
	gameOverText.setCharacterSize(80);
	gameOverText.setPosition(sf::Vector2f((640-gameOverText.getGlobalBounds().width)/2.0,0));
	gameOverText.setOutlineColor(sf::Color::White);
	gameOverText.setOutlineThickness(2);
	gameOverText.setStyle(sf::Text::Bold);
	
	//--------------------------------------

	scoreText.setFont(gameOverFont);
	highscoreText.setFont(gameOverFont);
	scoreText.setFillColor(sf::Color::White);
	highscoreText.setFillColor(sf::Color::White);
	ss_score<<"Score: "<<global::score;
	scoreText.setString(ss_score.str());
	ss_highscore<<"HIGH SCORE: "<<global::highscore_name<<" <"<<global::highscore<<">";
	highscoreText.setString(ss_highscore.str());
	highscoreText.setCharacterSize(40);
	scoreText.setCharacterSize(100);
	highscoreText.setPosition(sf::Vector2f((640-highscoreText.getGlobalBounds().width)/2.0,100));
	scoreText.setPosition(sf::Vector2f((640-scoreText.getGlobalBounds().width)/2.0,125));
		
	//--------------------------------------
	
	stringLetrasNombre = "nombre: ";
	letrasNombreText.setFont(gameOverFont);
	letrasNombreText.setString(stringLetrasNombre);
	letrasNombreText.setCharacterSize(40);
	letrasNombreText.setFillColor(sf::Color::White);
	letrasNombreText.setPosition(sf::Vector2f((475-letrasNombreText.getGlobalBounds().width)/2.0,275));
	
	
	entradaNombre.setFont(gameOverFont);
	entradaNombre.setMaxChars(10);
	entradaNombre.setSingleWord(true);

	//--------------------------------------

	presionaEscapeText.setFont(gameOverFont);
	presionaEscapeText.setFillColor(sf::Color::White);
	presionaEscapeText.setString("Presiona ESCAPE para volver al MENU");
	presionaEscapeText.setCharacterSize(40);
	presionaEscapeText.setPosition(sf::Vector2f((640-presionaEscapeText.getGlobalBounds().width)/2.0,350));
	
	//--------------------------------------

	player p;
	juego::actualizarScore();
//	if(global::score>global::highscore){ 
//		global::highscore=global::score;
//		global::highscore_name=global::score_name;
//	}
	reloj.restart();
	
}

void escena_gameOver::update (float elapsed) {
	escena::update(elapsed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		soundTrack.stop();
		global::score=0;
		//global::score_name="unknown";
		pressSound.play();
		juego::darInstancia().cambiar_escena(new escena_menu);
	}
}

void escena_gameOver::procesar_evento (const sf::Event & e) {
	if(e.type==sf::Event::KeyPressed && e.key.code==sf::Keyboard::Return){
		string stringIngresado = entradaNombre.getValue();
		stringLetrasNombre += stringIngresado;
		global::score_name=stringIngresado;
		global::jugador.puntuacion=global::score;
		global::jugador.ingresaNombre(stringIngresado);
		if(global::score>global::highscore){ 
			global::highscore=global::score;
			global::highscore_name=stringIngresado;
		}
		juego::guardarScore();
		letrasNombreText.setString(stringLetrasNombre);
		entradaNombre.reset();
	}else entradaNombre.processEvent(e);
}

void escena_gameOver::draw (sf::RenderWindow & w) {
	escena::draw(w);
	w.draw(fondoGamneOverSp);
	w.draw(letrasNombreText);
	w.draw(entradaNombre);
	w.draw(gameOverText);
	w.draw(presionaEscapeText);
	w.draw(highscoreText);
	w.draw(scoreText); 
}

