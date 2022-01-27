#ifndef GLOBAL_H
#define GLOBAL_H
#include "player.h"
#include <string>
#include <SFML/Graphics/Texture.hpp>
using namespace std;

class global {
public:
	int static nivel;
	int static subnivel;
	double static score;
	double static highscore;
	string static score_name;
	string static highscore_name;
	player static jugador;
private:
};

#endif

