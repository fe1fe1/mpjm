#include "escena_juego.h"
#include "global.h"
#include <iostream>
#include <ostream>
#include <istream>
#include "juego.h"

escena_juego::escena_juego()
{
	global::nivel=1;
}

void escena_juego::update(float elapsed){
	escena::update(elapsed);
	lvl=global::nivel;
	switch (lvl){
		
		// NIVEL 1:
		
	case 1:
		if(lvl1!=nullptr){
			//std::cout<<"Nivel 1 en ejecucion"<<std::endl;
		}else{
			lvl1=new nivel_1 ();
			juego::darInstancia().cambiar_escena(lvl1);
		}
		break;
		
		// NIVEL 2:
		
	case 2:
		
		break;
		
		// NIVEL 3:
		
	case 3:
		
		break;
	}
}
void escena_juego::draw(sf::RenderWindow &w) {
	lvl1->draw(w);
}
