#include "escena_menu.h"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Color.hpp>
#include "escena_juego.h"
#include "juego.h"
#include <iostream>

escena_menu::escena_menu() {
	if(!soundTrack.openFromFile("assets/soundTracks/undertale_fallen_down.ogg")){
		std::cerr<<"ERROR: No se encontro el undertale_fallen_down.ogg en la ruta [assets/soundTracks/undertale_fallen_down.ogg]"<<std::endl;
	}
	soundTrack.setVolume(40);
	soundTrack.play();
	
	if(!fondoMenuTex.loadFromFile("assets/texturas/fondoMenu.png")){
		std::cerr<<"ERROR: No se encontro el archivo fondoMenu.png en la ruta [assets/texturas/fondoMenu.png]"<<std::endl;
	}
	fondoMenuSp.setTexture(fondoMenuTex);
	if(!menuFont.loadFromFile("assets/fuentes/Cave-Story.ttf" )){
		std::cerr<<"ERROR: No se encontro el archivo Cave-Story.ttf en la ruta [assets/fuentes/Cave-Story.ttf]"<<std::endl;
	}
	
	if (!pressBuffer.loadFromFile("assets/soundEfects/press_to_continue.wav")){
		std::cerr<<"ERROR: No se encontro el archivo press_to_continue.wav en la ruta [assets/soundEfects/press_to_continue.wav]"<<std::endl;
	}
	pressSound.setBuffer(pressBuffer);
	
	tituloText.setFont(menuFont);
	tituloText.setFillColor(sf::Color::Black);
	tituloText.setString("Mi Primer Juego Mal!");
	tituloText.setCharacterSize(80);
	tituloText.setPosition(sf::Vector2f((640-tituloText.getGlobalBounds().width)/2.0,0));
	tituloText.setOutlineColor(sf::Color::White);
	tituloText.setOutlineThickness(2);
	tituloText.setStyle(sf::Text::Bold);
	
	presionaEspacioText.setFont(menuFont);
	presionaEspacioText.setFillColor(sf::Color::Black);
	presionaEspacioText.setString("Presiona ESPACIO para EMPEZAR");
	presionaEspacioText.setCharacterSize(40);
	presionaEspacioText.setPosition(sf::Vector2f((640-presionaEspacioText.getGlobalBounds().width)/2.0,250));
	reloj.restart();
	
}

void escena_menu::update (float elapsed) {
	escena::update(elapsed);
	//Efecto parpadeo para PRESS TO STAR
	efctoTexto(presionaEspacioText);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
		soundTrack.stop();
		pressSound.play();
		juego::darInstancia().cambiar_escena(new escena_juego);
		
	};
}

void escena_menu::procesar_evento (const sf::Event & e) {
	
}

void escena_menu::draw (sf::RenderWindow & w) {
	escena::draw(w);
	w.draw(fondoMenuSp);
	w.draw(tituloText);
	w.draw(presionaEspacioText);
}


