#pragma once
#include "Enemigos.h"
using namespace std;

class FinalBoss : public Enemigo
{
private:
	int fireAttack;
	int frozenAttack;

public:

	//Constructor
	FinalBoss(int pHP,
		std::string pNAME,
		int pATTACK,
		int pSHIELD,
		bool pFireAttack,
		int pFrozenAttack);

	//Getters AND Setters
	int getFireAttack();
	int getFrozenAttack();

	void setFireAttack(int pFireAttack);
	void setFrozenAttack(int pFrozenAttack);

	//Metodos Propios
	void printStatus();
};