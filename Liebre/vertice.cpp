#include "pch.h"
#include "vertice.h"
#include <string>
#include <sstream>


Vertice* Vertice::mover()
{
	return NULL;
}


Vertice* Vertice::verificar()
{
	return NULL;
}

Vertice::Vertice(int pocicionX,int y,int personaje)
{
	this->norte = NULL;
	this->sur = NULL;
	this->este = NULL;
	this->oeste = NULL;
	this->suroeste = NULL;
	this->noroeste = NULL;
	this->noreste = NULL;
	this->sureste = NULL;
	this->pocicionX = pocicionX;
	this->y = y;
	this->personaje = personaje;
}

std::string Vertice::imprimir() {
	std::ostringstream result;
	result << "pocicionX->[" << this->pocicionX << "] - " << "y->[" << this->y << "] - " << "personaje->[" << this->personaje << "]";
	return result.str();
}

Vertice::~Vertice()
{
}
