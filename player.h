#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <cstring>
using namespace std;
struct player{
	player(){};
	player(string nick, double score){
		strcpy(name,nick.c_str());
		puntuacion=score;
	};
	void ingresaNombre(string nombre){
		strcpy(name,nombre.c_str());
	}
	double puntuacion;
	char name [32];
};
#endif
