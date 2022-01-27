#ifndef ESCENA_H
#define ESCENA_H

#include <vector>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "entidad.h"
#include "pj.h"
#include <SFML/System/Clock.hpp>
#include "bola_lvl1.h"

class escena 
{
public:
	escena();
	virtual void update(float elapsed);
	virtual void draw(sf::RenderWindow &w);
	virtual void procesar_evento(const sf::Event &e);
	virtual bool termino ();
	bool invulnerable = false;
	int vidas_pj = 1;
protected:
	pj *Pj;
	sf::Clock reloj;

    bool cerrar = false;

	void agregar(entidad *e);
	void quitar(entidad *e);
	void libera_memoria();

    void efctoTexto (sf::Text &texto);

	std::vector <entidad*> disparosPj;
	std::vector <entidad*> disparosPj_borrar;
	std::vector <entidad*> entidades;
	std::vector <entidad*> a_borrar;
};

#endif
