#pragma once
#include "Enemigos.h"
#include <iostream>

Enemigo::Enemigo(int pHP, std::string pNAME, int pATTACK, int pDEFENSE) {
	hp = pHP;
	name = pNAME;
	attack = pATTACK;
	defense = pDEFENSE;
}

//getters
int Enemigo::getHP() {
	return hp;
}

std::string Enemigo::getNAME() {
	return name;
}

int Enemigo::getATTACK() {
	return attack;
}

int Enemigo::getDEFENSE() {
	return defense;
}

//setters

void Enemigo::setHP(int pHP) {
	hp = pHP;
}

void Enemigo::setNAME(std::string pNAME) {
	name = pNAME;
}

void Enemigo::setATTACK(int pATTACK) {
	attack = pATTACK;
}

void Enemigo::setDEFENSE(int pDEFENSE) {
	defense = pDEFENSE;
}

//Metodos propios

void Enemigo::printStatusBasic() {
	std::cout << "El nombre del enemigo es " << getNAME() << " tiene una vida de " << getHP() << std::endl;
}