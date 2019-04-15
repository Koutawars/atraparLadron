#include "pch.h"
#include "Nodo.h"
#include <string>
#include <sstream>


Nodo* Nodo::mover()
{
	return NULL;
}


Nodo* Nodo::verificar()
{
	return NULL;
}

Nodo::Nodo(int x,int y,int ficha)
{
	this->arb = NULL;
	this->abj = NULL;
	this->der = NULL;
	this->izq = NULL;
	this->dig_inf_izq = NULL;
	this->dig_sup_izq = NULL;
	this->dig_sup_der = NULL;
	this->dig_inf_der = NULL;
	this->x = x;
	this->y = y;
	this->ficha = ficha;
}

std::string Nodo::imprimir() {
	std::ostringstream result;
	result << "x->[" << this->x << "] - " << "y->[" << this->y << "] - " << "ficha->[" << this->ficha << "]";
	return result.str();
}

Nodo::~Nodo()
{
}
