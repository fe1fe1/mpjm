#include "nivel_1.h"
#include "global.h"
#include <iostream>
#include <ostream>
#include <istream>
#include <typeinfo>
#include <SFML/Graphics/Color.hpp>
#include <sstream>
#include "temps_mpjm.h"
#include "juego.h"
#include "escena_menu.h"
#include "escena_gameOver.h"
#include "escena_gameBeaten.h"
nivel_1::nivel_1() {
	Pj = new pj (sf::Vector2f(315, 315));
	agregar(Pj);
	reboteSound.setBuffer(reboteBuffer);
	reboteSound.setVolume(25);
	//-----------------------------------------------------------------------/
	// Cargar sonidos
	if(!soundTrack.openFromFile("assets/soundTracks/song_of_storms.ogg")){
		std::cerr<<"ERROR: No se encontro el song_of_storms.ogg en la ruta [assets/soundTracks/song_of_storms.ogg]"<<std::endl;
	}
	soundTrack.setVolume(200);
	soundTrack.play();
	if(!pjHitBuffer.loadFromFile("assets/soundEfects/pj_hit.wav")){
		std::cerr<<"ERROR: No se encontro el pj_hit.wav en la ruta [assets/soundEfects/pj_hit.wav]"<<std::endl;
	}
	if(!bolaHitBuffer.loadFromFile("assets/soundEfects/enemigo_hit.wav")){
		std::cerr<<"ERROR: No se encontro el enemigo_hit.wav en la ruta [assets/soundEfects/enemigo_hit.wav]"<<std::endl;
	}
	if(!nextLVLbuffer.loadFromFile("assets/soundEfects/next_lvl.wav")){
		std::cerr<<"ERROR: No se encontro el next_lvl.wav en la ruta [assets/soundEfects/next_lvl.wav]"<<std::endl;
	}
	if(!nextSUBLVLbuffer.loadFromFile("assets/soundEfects/next_sublvl.wav")){
		std::cerr<<"ERROR: No se encontro el next_sublvl.wav en la ruta [assets/soundEfects/next_sublvl.wav]"<<std::endl;
	}
	// Setear sonidos


    dispBuffer.loadFromFile("assets/soundEfects/disparo.wav");
	dispSound.setBuffer(dispBuffer);
	dispSound.setVolume(35);


	pjHitSound.setBuffer(pjHitBuffer);
	

	bolaHitSound.setBuffer(bolaHitBuffer);
	bolaHitSound.setVolume(35);
	nextLVLsound.setBuffer(nextLVLbuffer);
	nextSUBLVLsound.setBuffer(nextSUBLVLbuffer);
	//-----------------------------------------------------------------------/
	// Cargar fondo
	texFondo.loadFromFile("assets/texturas/fondo.png");
	spFondo.setTexture(texFondo);
	//-----------------------------------------------------------------------/
	// Cargar fuente
	lvl1Font.loadFromFile("assets/fuentes/Cave-Story.ttf" );
	// Setear textos
	lvlTitleText.setFont(lvl1Font);
	lvlTitleText.setPosition(540,0);
	lvlTitleText.setFillColor(sf::Color::Black);
	
	vidasPjText.setFont(lvl1Font);
	vidasPjText.setPosition(10,0);
	vidasPjText.setFillColor(sf::Color::Black);
	
	scoreText.setFont(lvl1Font);
	scoreText.setPosition(10,50);
	scoreText.setFillColor(sf::Color::Black);
	//-----------------------------------------------------------------------/
	cool_down.restart();
	
}
void nivel_1::update (float elapsed) {
	escena::update(elapsed);
	srand(time(nullptr));
	
	//							LOGICA NIVEL 1
	//---------------------------------------------------------------/
	switch (global::subnivel){
	//SUBNIVEL 1:
	case 1:
		if (iniciado) {
			
		} else {
			crearBolalvl1((sf::Vector2f(150+rand()%290,100)),1, 2);
			iniciado = true;
		}
		if (bolaslvl1.size()<1){
			libera_memoria();
			pasar_sublvl();
			crearBolalvl1((sf::Vector2f(300+rand()%290,100)),-1, 2);
			crearBolalvl1((sf::Vector2f(300+rand()%290,100)),1, 2);
		}
		break;
	//SUBNIVEL 2:
	case 2:
		if (bolaslvl1.size()<1){
			libera_memoria();
			pasar_sublvl();
			crearBolalvl1((sf::Vector2f(150+rand()%290,100)),-1, 1);
		}
		break;
	//SUBNIVEL 3:
	case 3:
		if (bolaslvl1.size()<1){
			libera_memoria();
			pasar_sublvl();
			crearBolalvl1((sf::Vector2f(300+rand()%290,100)),-1, 2);
			crearBolalvl1((sf::Vector2f(rand()%290,100)),1, 1);
		}
		break;
	//SUBNIVEL 4:
	case 4:
		if (bolaslvl1.size()<1){
			libera_memoria();
			pasar_sublvl();
			crearBolalvl1((sf::Vector2f(300+rand()%290,100)),1, 1);
			crearBolalvl1((sf::Vector2f(rand()%290,100)),-1 , 1);
		}
		break;
	//SUBNIVEL 5:
	case 5:
		if (bolaslvl1.size()<1){
			libera_memoria();
			pasar_sublvl();
			crearBolalvl1((sf::Vector2f(rand()%290,100)),-1 , 2);
			crearBolalvl1((sf::Vector2f(150+rand()%290,100)),1, 1);
			crearBolalvl1((sf::Vector2f(300+rand()%290,100)),-1, 1);
			
		}
		break;
	//SUBNIVEL 6:
	case 6:
		if (bolaslvl1.size()<1){
			libera_memoria();
			pasar_sublvl();
			crearBolalvl1((sf::Vector2f(100+rand()%290,100)),-1 , 1);
			crearBolalvl1((sf::Vector2f(200+rand()%290,100)),1, 1);
			crearBolalvl1((sf::Vector2f(300+rand()%290,100)),-1 , 1);
			
		}
		break;
	//SUBNIVEL 7:
	case 7:
		if (bolaslvl1.size()<1){
			libera_memoria();
			pasar_sublvl();
			crearBolalvl1((sf::Vector2f(rand()%290,100)),-1 , 2);
			crearBolalvl1((sf::Vector2f(100+rand()%290,100)),1, 1);
			crearBolalvl1((sf::Vector2f(200+rand()%290,100)),-1 , 1);
			crearBolalvl1((sf::Vector2f(300+rand()%290,100)),1, 1);
		}
		break;
	//SUBNIVEL 8:
	case 8:
		if (bolaslvl1.size()<1){
			libera_memoria();
			pasar_sublvl();
			crearBolalvl1((sf::Vector2f(rand()%290,100)),1, 1);
			crearBolalvl1((sf::Vector2f(100+rand()%290,100)),-1 , 1);
			crearBolalvl1((sf::Vector2f(200+rand()%290,100)),1, 1);
			crearBolalvl1((sf::Vector2f(300+rand()%290,100)),-1 , 1);
		}
		break;
	//SUBNIVEL 9:
	case 9:
        if (bolaslvl1.size()<1){
			libera_memoria();
			pasar_sublvl();
			crearBolalvl1((sf::Vector2f(100+rand()%290,100)),1, 1);
			crearBolalvl1((sf::Vector2f(200+rand()%290,100)),-1 , 1);
			crearBolalvl1((sf::Vector2f(300+rand()%290,100)),1, 1);
			crearBolalvl1((sf::Vector2f(400+rand()%290,100)),-1 , 1);
			crearBolalvl1((sf::Vector2f(500+rand()%290,100)),-1 , 1);
		}
		break;
	}
	//---------------------------------------------------------------/
	
	// LOGICA DE DISPAROS PJ:
	//---------------------------------------------------------------/
	// Disparar:
	if (cool_down.getElapsedTime().asSeconds() >= Pj->darVel_disp()) {
		if (Pj->pj_disparando()) {
			entidad* disparo = new disparo_pj(Pj->darPos(),Pj->darOrientacion());
            //dispSound.play();
			agregar(disparo);
			disparosPj.push_back(disparo);
			cool_down.restart();
		}
	}
	//Colision bolas-disparos_pj:
	for(int j=0;j<bolaslvl1.size();j++){
		sf::FloatRect bolaHitBox=bolaslvl1[j]->hitBox();
		for(int i=0;i<disparosPj.size();i++){
			sf::FloatRect dispHitBox=disparosPj[i]->hitBox();
			if(bolaHitBox.intersects(dispHitBox)){
				bolaHitSound.play();
				std::cout<<"colision con bola tier"<<bolaslvl1[j]->darTier()<<std::endl;
				global::score+= 100*bolaslvl1[j]->darTier();
				quitar(disparosPj[i]);
				disparosPj_borrar.push_back(disparosPj[i]);
				bolaslvl1_eliminar.push_back(bolaslvl1[j]);
			}
		}
	}
	//---------------------------------------------------------------/
	
	//Colision pj-bolas
	if (!invulnerable){
		if(reloj.getElapsedTime().asSeconds()>0.1){
			for(int i=0;i<bolaslvl1.size();i++){
				sf::FloatRect bolaHitBox=bolaslvl1[i]->hitBox();
				sf::FloatRect pjHitBox=Pj->hitBox();
				if(pjHitBox.intersects(bolaHitBox)){
					pjHitSound.play();
					std::cout<<"colision"<<std::endl;
					invulnerable=true;
					vidas_pj= vidas_pj-1;
					break;
				}
			}
			reloj.restart();
		}
	}else{
		if(reloj.getElapsedTime().asSeconds()<=3.5){
			Pj->efct_invulnerable();
		}else{
			invulnerable=false;
			Pj->efct_vulnerable();
			reloj.restart();
		}
	}
	//--------------------------------------------/
	//Texto en pantalla
	std::stringstream ss_lvl;
	std::stringstream ss_vidas;
	std::stringstream ss_score;
	ss_vidas<<"VIDAS: "<<vidas_pj;
	ss_lvl<<"Nivel: 1-"<<global::subnivel;
	ss_score<<"Score: "<<global::score;
	vidasPjText.setString(ss_vidas.str());
	lvlTitleText.setString(ss_lvl.str());
	scoreText.setString(ss_score.str());
	//--------------------------------------------/
	
	//Eliminar actores
	eliminarBolaslvl1();
	t_mpjm::borrar(disparosPj_borrar, disparosPj);
	bolaslvl1_eliminar.clear();
	
	//Termino-sigue jugando
	if (vidas_pj<1){
		global::subnivel=1;
		soundTrack.stop();
		juego::darInstancia().cambiar_escena(new escena_gameOver);
	}
    if(global::subnivel>9){
        global::subnivel=1;
		soundTrack.stop();
		juego::darInstancia().cambiar_escena(new escena_gameBeaten);
    }
}

void nivel_1::draw (sf::RenderWindow & w) {
	w.draw(spFondo);
	w.draw(vidasPjText);
	w.draw(lvlTitleText);
	w.draw(scoreText);
	escena::draw(w);
}
void nivel_1::crearBolalvl1(const sf::Vector2f &pos,int direccion,int tier){
	sf::Vector2f estirado = Pj->darPos();
	bola_lvl1* bola=new bola_lvl1 (pos,direccion,tier,estirado,reboteSound);
	agregar(bola);
	bolaslvl1.push_back(bola);
	std::cout<<"bola creada"<<std::endl;
}
void nivel_1::eliminarBolaslvl1(){
	for(int i=0;i<bolaslvl1_eliminar.size();i++){
		int tier=bolaslvl1_eliminar[i]->darTier();
		int direccion=bolaslvl1_eliminar[i]->darDireccion();
		sf::Vector2f pos=bolaslvl1_eliminar[i]->darPos();
		std::cout<<"bola pos x:"<<pos.x<<std::endl;
		std::cout<<"bola pos y:"<<pos.y<<std::endl;
		//Divide la bola:
		if (tier==1){
			crearBolalvl1(pos,direccion,2);
			crearBolalvl1(pos,direccion*(-1),2);
			quitar(bolaslvl1_eliminar[i]);
		}
		if (tier==2){
			crearBolalvl1(pos,direccion,3);
			crearBolalvl1(pos,direccion*(-1),3);
			quitar(bolaslvl1_eliminar[i]);
		}
		if (tier==3){
			quitar(bolaslvl1_eliminar[i]);
		}
		
	} 
	//Eliminar bola del vector de bolaslvl1:
	t_mpjm::borrar(bolaslvl1_eliminar,bolaslvl1);
}
void nivel_1::pasar_sublvl(){
	nextSUBLVLsound.play();
	global::subnivel++;
	global::score+=1000*vidas_pj;
	vidas_pj++;
}

