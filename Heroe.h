#pragma once
#include "personaje.h"
class Heroe : public personaje {
public:
	Heroe(const std::string& nombre, int vida, int ataque)
		:personaje(nombre, vida, ataque) {}
};