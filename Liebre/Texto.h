#pragma once
#include <string>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
class Texto
{
public:
	int pocicionX, y;
	std::string contenido;
	Texto(std::string contenido);
	Texto();
	void draw(ALLEGRO_FONT *tipodeletra, int r, int g, int b, int flags);
	bool select;
	~Texto();
};

