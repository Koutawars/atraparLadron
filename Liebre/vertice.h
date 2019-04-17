#include <string>
#include <sstream>
#pragma once
class Vertice
{
public:
	int pocicionX;
	int y;
	Vertice* norte; // arriba
	Vertice* sur; // abajo
	Vertice* este; // derecha
	Vertice* oeste; // izquierda
	Vertice* suroeste; // diagonal inferior izquierda
	Vertice* noroeste; // diagonal superior izquierda
	Vertice* noreste; // diagonal superior derecha
	Vertice* sureste; // diagonal inferior derecha
	int personaje;
	Vertice* mover();

	Vertice* verificar();
	Vertice(int pocicionX, int y, int personaje);
	std::string imprimir();
	~Vertice();

};

