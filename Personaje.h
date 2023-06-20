#pragma once
#include <iostream>

class personaje {
private:
	std::string nombre;
	int vida;
	int ataque;

public:
	personaje(const std::string& nombre, int vida, int ataque)
		: nombre(nombre), vida(vida), ataque(ataque) {}

	const std::string& getNombre() const {
		return nombre;
	}

	int getVida() const {
		return vida;
	}

	void setVida(int newv) {
		vida = newv;
	}

	int getAtaque() const {
		return ataque;
	}
};