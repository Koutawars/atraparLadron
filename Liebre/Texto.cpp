#include "pch.h"
#include "Texto.h"

Texto::Texto(){}

Texto::Texto(std::string contenido)
{
	this->contenido = contenido;
	this->pocicionX = 0;
	this->y = 0;
	this->select = false;
}




void Texto::draw(ALLEGRO_FONT *fuente, int r, int g, int b, int flags){
	al_draw_text(fuente, al_map_rgb(r, g, b), this->pocicionX, this->y, flags, this->contenido.c_str());
}


Texto::~Texto()
{
}
