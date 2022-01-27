#ifndef t_mpjm
#define t_mpjm
#include <iostream>
template <typename T>
void borrar (std::vector <T*> &a_borrar, std::vector <T*> &vector){
	for (auto b : a_borrar) {
		auto it = find(vector.begin(), vector.end(), b);
		if (it != vector.end()){
			vector.erase(it);
		}
	}
	a_borrar.clear();
}

#endif
