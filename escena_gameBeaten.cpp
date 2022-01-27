#include "escena_gameBeaten.h"

escena_gameBeaten::escena_gameBeaten(){

    if(!soundTrack.openFromFile("assets/soundTracks/undertale_fallen_down.ogg")){
		std::cerr<<"ERROR: No se encontro el undertale_fallen_down.ogg en la ruta [assets/soundTracks/undertale_fallen_down.ogg]"<<std::endl;
	}
    soundTrack.setVolume(40);
	soundTrack.play();

    if(!fondoGameBeatenTex.loadFromFile("assets/texturas/fondoFinal.png")){
		std::cerr<<"ERROR: No se encontro el archivo fondoMenu.png en la ruta [assets/texturas/fondoMenu.png]"<<std::endl;
	}

    fondoGameBeatenSp.setTexture(fondoGameBeatenTex);

    if(!gameBeatenFont.loadFromFile("assets/fuentes/Cave-Story.ttf" )){
		std::cerr<<"ERROR: No se encontro el archivo Cave-Story.ttf en la ruta [assets/fuentes/Cave-Story.ttf]"<<std::endl;
	}

    //-----------------------TITLE-----------------------------	
    
	gameBeatenText.setFont(gameBeatenFont);
	gameBeatenText.setFillColor(sf::Color::Black);
	gameBeatenText.setString("GAME FINISHED!");
	gameBeatenText.setCharacterSize(80);
	gameBeatenText.setPosition(sf::Vector2f((640-gameBeatenText.getGlobalBounds().width)/2.0,0));
	gameBeatenText.setOutlineColor(sf::Color::White);
	gameBeatenText.setOutlineThickness(2);
	gameBeatenText.setStyle(sf::Text::Bold);

    //-----------------------SCORE-----------------------------	

    scoreText.setFont(gameBeatenFont);
	highscoreText.setFont(gameBeatenFont);
	scoreText.setFillColor(sf::Color::White);
	highscoreText.setFillColor(sf::Color::White);
	ss_score<<"Score: "<<global::score;
	scoreText.setString(ss_score.str());
    ss_highscore<<"Highscore : "<<global::highscore_name<<" <"<<global::highscore<<">";
	highscoreText.setString(ss_highscore.str());
	highscoreText.setCharacterSize(40);
	scoreText.setCharacterSize(100);
	highscoreText.setPosition(sf::Vector2f((640-highscoreText.getGlobalBounds().width)/2.0,125));
	scoreText.setPosition(sf::Vector2f((640-scoreText.getGlobalBounds().width)/2.0,150));
    
    //-----------------------PRESS TO CONTINUE-----------------------------	

	presionaEscape.setFont(gameBeatenFont);
	presionaEscape.setFillColor(sf::Color::Black);
	presionaEscape.setString("Presiona ESCAPE para ir al MENU");
	presionaEscape.setCharacterSize(40);
	presionaEscape.setPosition(sf::Vector2f((640-presionaEscape.getGlobalBounds().width)/2.0,300));
	reloj.restart();

}

void escena_gameBeaten::update(float elapsed){
     escena::update(elapsed);
	//Efecto parpadeo para PRESS TO STAR
	efctoTexto(presionaEscape);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		soundTrack.stop();
		juego::darInstancia().cambiar_escena(new escena_menu);
		
	};
}

void escena_gameBeaten::draw (sf::RenderWindow & w) {
	escena::draw(w);
	w.draw(fondoGameBeatenSp);
	w.draw(gameBeatenText);
	w.draw(presionaEscape);
	w.draw(scoreText); 
	w.draw(highscoreText); 
}
