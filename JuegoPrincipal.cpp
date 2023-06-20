// JuegoMazmorras.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "Header.h"
#include <iostream>
#include "Enemigos.h"
#include "FinalBoss.h"
#include "Heroe.h"
#include "personaje.h"
using namespace std;

const int FILAS = 10;
const int COLUMNAS = 10;

void Laberinto(char tablero[FILAS][COLUMNAS]) {
	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			std::cout << tablero[i][j] << " ";
		}
		std::cout << endl;
	}
}

void Fight(Heroe& heroe1, Enemigo& enemigo1) {
	std::cout << "Acabas de emepezar una pelea con " << enemigo1.getNAME() << endl;

	while (true) {
		std::cout << "Es tu turno " << heroe1.getNombre() << endl;
		std::cout << "1. Atacar" << endl;
		std::cout << "2. Escapar" << endl;

		int aci;
		cin >> aci;

		if (aci == 1) {
			int dano = heroe1.getVida();
			enemigo1.setHP(enemigo1.getHP() - dano);
			std::cout << "Has hecho " << dano << "puntos de dano " << endl;
		}
		else if (aci == 2) {
			std::cout << "Has escapado del enemigo" << endl;
			break;
		}
		else {
			std::cout << "Error." << endl;
			continue;
		}

		if (enemigo1.getHP() <= 0) {
			std::cout << "Has derrotado al enemigo" << endl;
			break;
		}

		int dano = enemigo1.getATTACK();
		heroe1.setVida(heroe1.getVida() - dano);
		std::cout << enemigo1.getNAME() << "El enemigo te ha atacado y has recibido " << dano << " puntos de dano " << endl;

		if (heroe1.getVida() <= 0)
			std::cout << "Nuestro heroe ha sido eliminado. El mundo esta perdido " << endl;
		break;
	}
}

void FightB(Heroe& heroe2, FinalBoss& fb1) {
	std::cout << "Acabas de emepezar una pelea con " << fb1.getNAME() << endl;

	while (true) {
		std::cout << "Es tu turno Heroe" << heroe2.getNombre() << endl;
		std::cout << "1. Atacar" << endl;
		std::cout << "2. Escapar" << endl;

		int aci;
		cin >> aci;

		if (aci == 1) {
			int dano = heroe2.getVida();
			fb1.setHP(fb1.getHP() - dano);
			std::cout << "Has hecho " << dano << "puntos de dano " << endl;
		}
		else if (aci == 2) {
			std::cout << "Has escapado del Boss" << endl;
			break;
		}
		else {
			std::cout << "Error." << endl;
			continue;
		}

		if (fb1.getHP() <= 0) {
			std::cout << "Has derrotado al Final Boss el mundo esta salvado" << endl;
			break;
		}

		int dano = fb1.getATTACK();
		heroe2.setVida(heroe2.getVida() - dano);
		std::cout << fb1.getNAME() << " te ha atacado y has recibido " << dano << " puntos de dano " << endl;

		if (heroe2.getVida() <= 0)
			std::cout << "Nuestro heroe ha sido eliminado. El mundo esta perdido " << endl;
		break;
	}
}



int main()
{
	char CLaberinto[FILAS][COLUMNAS];

	for (int i = 0; i < FILAS; i++) {
		for (int j = 0; j < COLUMNAS; j++) {
			CLaberinto[i][j] = '.';
		}
	}

	int FJ = 3;
	int CJ = 4;
	CLaberinto[FJ][CJ] = 'PJ';

	int FE = 1;
	int CE = 2;
	CLaberinto[FE][CE] = 'PE';

	int FFBE = 6;
	int FFBJ = 7;
	CLaberinto[FFBE][FFBJ] = 'PFB';

	Laberinto(CLaberinto);

	Heroe heroe("Heroe", 500, 100);

	Enemigo enemigo(500, "Enemigo", 50, 65);

	FinalBoss finalboss(800, "Jefazo", 100, 34, 65, 70);

	char mover;
	while (true) {
		std::cout << "Usa una de las siguientes teclas para moverte por el laberinto (W,A,S,D)";
		std::cin >> mover;

		CLaberinto[FJ][CJ] = '.';

		switch (mover) {
		case 'W':
			FJ--;
			break;

		case 'A':
			CJ--;
			break;

		case 'S':
			FJ++;
			break;

		case 'D':
			CJ++;
			break;

		default:
			std::cout << "Tecla invalida" << endl;
			break;
		}

		if (FJ < 0 || FJ >= FILAS || CJ < 0 || CJ >= COLUMNAS) {
			std::cout << "Has sobrepasado el limite del tablero.";
			break;
		}

		if (FJ == FE && CJ == CE) {
			Fight(heroe, enemigo);
			break;
		}

		Laberinto(CLaberinto);

		if (FJ == FFBE && CJ == FFBJ) {
			FightB(heroe, finalboss);
			break;
		}
	}
	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
