#include <string>
#include <sstream>
#pragma once
class Nodo
{
public:
	int x;
	int y;
	Nodo* arb; // arriba
	Nodo* abj; // abajo
	Nodo* der; // derecha
	Nodo* izq; // izquierda
	Nodo* dig_inf_izq; // diagonal inferior izquierda
	Nodo* dig_sup_izq; // diagonal superior izquierda
	Nodo* dig_sup_der; // diagonal superior derecha
	Nodo* dig_inf_der; // diagonal inferior derecha
	int ficha;
	Nodo* mover();

	Nodo* verificar();
	Nodo(int x, int y, int ficha);
	std::string imprimir();
	~Nodo();

};

