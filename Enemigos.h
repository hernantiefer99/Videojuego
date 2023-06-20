#pragma once
#include <iostream>

class Enemigo
{
private:
	int hp;
	std::string name;
	int attack;
	int defense;

public:
	//Constructor
	Enemigo(int pHP, std::string pNAME, int pATTACK, int pDEFENSE);

	//getters
	int getHP();

	std::string getNAME();

	int getATTACK();

	int getDEFENSE();
	//setters

	void setHP(int pHP);

	void setNAME(std::string pNAME);

	void setATTACK(int pATTACK);

	void setDEFENSE(int pDEFENSE);

	//Metodos propios
	void printStatusBasic();
};