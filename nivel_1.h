#ifndef NIVEL_1_H
#define NIVEL_1_H
#include "escena.h"
#include "bola_lvl1.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <sstream>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

class nivel_1 : public escena {
public:
	nivel_1();
	void update (float elapsed);
	void draw (sf::RenderWindow & w);
private:
	//Sound Track y efectos
    
    bool termino_nivel = false;

	sf::Music soundTrack;
	
	sf::SoundBuffer reboteBuffer;
	sf::Sound reboteSound;
	
	sf::SoundBuffer nextSUBLVLbuffer;
	sf::SoundBuffer nextLVLbuffer;
	sf::Sound nextSUBLVLsound;
	sf::Sound nextLVLsound;
	
	sf::SoundBuffer pjHitBuffer;
	sf::Sound pjHitSound;
	
	sf::SoundBuffer bolaHitBuffer;
	sf::Sound bolaHitSound;

    sf::SoundBuffer dispBuffer;
    sf::Sound dispSound;
	
	//Textos
	sf::Text lvlTitleText;
	sf::Font lvl1Font;
	
	sf::Text vidasPjText;
	
	sf::Text scoreText;
	
	//Fondo
	sf::Texture texFondo;
	sf::Sprite spFondo;
	//Vectores de Disparos del PJ
	//Vectores de Bolas LVL 1
	std::vector <bola_lvl1*> bolaslvl1;
	std::vector <bola_lvl1*> bolaslvl1_eliminar;
	//Enfriamiento de disparo;
	sf::Clock cool_down;
	
	bool iniciado = false;
	
	void pasar_sublvl();
	//Para crear/eliminar Bolas LVL 1
	void crearBolalvl1(const sf::Vector2f &pos,int direccion,int tier);
	void eliminarBolaslvl1();
	
};

#endif

