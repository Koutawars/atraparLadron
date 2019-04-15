#include "pch.h"
#include "Game.h"
Game::Game() {}
Game::~Game() {}

void Game::initialize() {
	dibujar = true;
	comenzarContador = false;
	contador = 0;
	switch (pantalla) {
	case 0:
		this->menu = new std::vector<Texto*>();
		fuente = al_load_font("big_noodle_titling.ttf", 36, NULL);
		break;
	case 1:
		impmuertes = al_load_font("big_noodle_titling.ttf", 20, NULL);
		fuente = al_load_font("big_noodle_titling.ttf", 66, NULL);
		matrix = std::vector< std::vector<const char*> >(5);
		temp = std::vector< std::vector<Nodo*> >(5);
		mapa = al_load_bitmap("tablero.png");
		jugador = al_load_bitmap("fichaPerro.png");
		iaBitmap = al_load_bitmap("fichaGato.png");
		libre = al_load_bitmap("libre.png");
		select = NULL;
		turno = true;
		muertes = 0;
		comenzarContador = true;
		break;

	case 2:
		fuente = al_load_font("big_noodle_titling.ttf", 20, NULL);
		break;
	case 3:
		orientacion = 0;
		choose.push_back(al_load_bitmap("choose0.png"));
		choose.push_back(al_load_bitmap("choose1.png"));
		choose.push_back(al_load_bitmap("choose2.png"));
		choose.push_back(al_load_bitmap("choose3.png"));
		choose.push_back(al_load_bitmap("choose.png"));
		break;
	}
}

void Game::update(ALLEGRO_EVENT ev, bool *done) {
	switch (pantalla) {
		case 0: // Menu
		{
			if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (ev.mouse.button & 1)
				{
					// ev.mouse.x ev.mouse.y evento del mouse
					int mouseY = ev.mouse.y;
					int i = 0;
					for (auto texto : *menu) {
						if (mouseY >= texto->y && mouseY <= texto->y + 35) {
							switch (i) {
							case 0:
								this->cambiarPantalla(3);
								break;
							case 1:
								this->cambiarPantalla(2);
								break;
							case 2:
								*done = true;
								break;
							}
						}
						i++;
					}
				}
			}
			if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
				int mouseY = ev.mouse.y;
				int i = 0;
				for (auto texto : *menu) {
					if (mouseY >= texto->y && mouseY <= texto->y + 35) {
						texto->select = true;
						dibujar = true;
					}
					else {
						texto->select = false;
					}
				}
			}
			break;
		}
		case 1:
		{
			if (input.isKeyPressed(ev, ALLEGRO_KEY_BACKSPACE)) {
				cambiarPantalla(0);
			}
			if (input.isKeyPressed(ev, ALLEGRO_KEY_F5)) {
				cambiarPantalla(1);
			}
			if ( this->turno == true && this->mato==false)
			{
				if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
					if (ev.mouse.button & 1)
					{
						int mouseX = ev.mouse.x;
						int mouseY = ev.mouse.y;
						Nodo* aux = this->ptr, * aux2 = NULL;
						while (aux != NULL) {
							while (aux != NULL) {
								if (aux->ficha == 1) {
									if (mouseX > aux->x && mouseX < aux->x + 35 && mouseY > aux->y && mouseY < aux->y + 35) {
										std::cout << aux->imprimir() << std::endl;
										select = aux;
										dibujar = true;
									}
								}
								else if (aux->ficha == 0 && select != NULL && esAdyancente(select, aux)) {
									if (mouseX > aux->x && mouseX < aux->x + 35 && mouseY > aux->y && mouseY < aux->y + 35) {
										aux->ficha = select->ficha;
										select->ficha = 0;
										select = NULL;
										dibujar = true;
										this->turno = false;
									}
								}
								aux2 = aux;
								aux = aux->der;
							}
							aux = aux2;
							if (aux->abj == NULL)break;
							aux = aux->abj;
							while (aux != NULL) {
								if (aux->ficha == 1) {
									if (mouseX > aux->x && mouseX < aux->x + 35 && mouseY > aux->y && mouseY < aux->y + 35) {
										select = aux;
										dibujar = true;
									}
								}
								else if (aux->ficha == 0 && select != NULL && esAdyancente(select, aux)) {
									if (mouseX > aux->x && mouseX < aux->x + 35 && mouseY > aux->y && mouseY < aux->y + 35) {
										aux->ficha = select->ficha;
										select->ficha = 0;
										select = NULL;
										dibujar = true;
										this->turno = false;
									}
								}
								aux2 = aux;
								aux = aux->izq;
							}
							aux = aux2;
							aux = aux->abj;
						}
						if (select != NULL && !dibujar) {
							select = NULL;
							dibujar = true;
						}
					}
				}
			}
			else {
				this->mato = false;
				matar();
				if (this->mato == false && turno == false) {

					std::vector<Nodo*> aleatorio = std::vector<Nodo*>();
					if (this->gato->der != NULL) {
						if (this->gato->der->ficha == 0) {
							aleatorio.push_back(this->gato->der);
						}
					}
					if (this->gato->dig_inf_der != NULL) {
						if (this->gato->dig_inf_der->ficha == 0) {
							aleatorio.push_back(this->gato->dig_inf_der);
						}
					}
					if (this->gato->abj != NULL) {
						if (this->gato->abj->ficha == 0) {
							aleatorio.push_back(this->gato->abj);
						}
					}
					if (this->gato->dig_inf_izq != NULL) {
						if (this->gato->dig_inf_izq->ficha == 0) {
							aleatorio.push_back(this->gato->dig_inf_izq);
						}
					}
					if (this->gato->izq != NULL) {
						if (this->gato->izq->ficha == 0) {
							aleatorio.push_back(this->gato->izq);
						}
					}
					if (this->gato->dig_sup_izq != NULL) {
						if (this->gato->dig_sup_izq->ficha == 0) {
							aleatorio.push_back(this->gato->dig_sup_izq);
						}
					}
					if (this->gato->arb != NULL) {
						if (this->gato->arb->ficha == 0) {
							aleatorio.push_back(this->gato->arb);
						}
					}
					if (this->gato->dig_sup_der != NULL) {
						if (this->gato->dig_sup_der->ficha == 0) {
							aleatorio.push_back(this->gato->dig_sup_der);
						}
					}
					if (aleatorio.size() != 0) {
						this->gato->ficha = 0;
						int indice = rand() % aleatorio.size();
						aleatorio[indice]->ficha = 2;
						this->gato = aleatorio[indice];
					}
					else {
						al_draw_text(fuente, al_map_rgb(255, 255, 255), 300, 200, ALLEGRO_ALIGN_CENTER, "GANASTE!");
						al_flip_display();
						al_rest(5);
						cambiarPantalla(0);
					}
				}
				this->piensa = true;
				this->dibujar = true;
				this->turno = true;

			}
			if (contador >= tiempo)
				dibujar = true;
			break;
		}
		case 2:
		{
			if (input.isKeyPressed(ev, ALLEGRO_KEY_BACKSPACE)) {
				cambiarPantalla(0);
			}
			break;
		}
		case 3:
		{
			if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
			{
				if (ev.mouse.button & 1)
				{
					int mouseX = ev.mouse.x;
					int mouseY = ev.mouse.y;
					for (int i = 0; i < 2; i++) {
						for (int j = 0; j < 2; j++) {
							if (mouseX > 89 + (332 * i) && mouseX < 89 + (332 * i) + 153 && mouseY > 88 + (216 * j) && mouseY < 88 + (216 * j) + 153) {
								orientacion = i + j*2;
								std::cout << orientacion << std::endl;
								cambiarPantalla(1);
							}
						}
					}
				}
			}
			break;
		}
	}
}

void Game::draw(ALLEGRO_DISPLAY *display) {
	switch (pantalla) {
	case 0: {
		int i = 0;
		// recorrer el menu
		for (auto texto : *menu) {
			// se pinta de diferente color si esta seleccionado 
			if(texto->select)
				texto->draw(fuente, 255, 0, 255, ALLEGRO_ALIGN_CENTER);
			else
				texto->draw(fuente, 255, 255, 255, ALLEGRO_ALIGN_CENTER);
			i++;
		}
		break;
	}
	case 1: {
		// dibujo el fondo
		al_draw_bitmap(mapa, 0, 0, NULL);
		Nodo* aux = this->ptr, *aux2 = NULL;
		if (this->piensa == true) {
			al_rest(0.8);
			piensa = false;
		}
		// recorro los nodos y los dibujo 
		while (aux != NULL) {
			while (aux != NULL) {
				if (aux->ficha == 1) {
					al_draw_bitmap(jugador, aux->x, aux->y, ALLEGRO_ALIGN_CENTER);
				}
				else if (aux->ficha == 2) {
					al_draw_bitmap(iaBitmap, aux->x, aux->y, ALLEGRO_ALIGN_CENTER);
				}
				else if (select != NULL) {
					if (esAdyancente(select, aux))
						al_draw_bitmap(libre, aux->x, aux->y, ALLEGRO_ALIGN_CENTER);
				}
				aux2 = aux;
				aux = aux->der;
			}
			aux = aux2;
			if (aux->abj == NULL)break;
			aux = aux->abj;
			while (aux != NULL) {
				if (aux->ficha == 1) {
					al_draw_bitmap(jugador, aux->x, aux->y, ALLEGRO_ALIGN_CENTER);
				}
				else if (aux->ficha == 2) {
					al_draw_bitmap(iaBitmap, aux->x, aux->y, ALLEGRO_ALIGN_CENTER);
				}
				else if (select != NULL) {
					if (esAdyancente(select, aux))
						al_draw_bitmap(libre, aux->x, aux->y, ALLEGRO_ALIGN_CENTER);
				}
				aux2 = aux;
				aux = aux->izq;
			}
			aux = aux2;
			aux = aux->abj;
		}
		al_draw_textf(impmuertes, al_map_rgb(0, 0, 0),550, 20, ALLEGRO_ALIGN_LEFT, "muertos: %d", this->muertes);
		if (muertes >= 3) {
			al_rest(0.5);
			al_draw_text(fuente, al_map_rgb(0, 0, 0), 300, 200, ALLEGRO_ALIGN_CENTER, "PERDISTE!");
			al_flip_display();
			al_rest(4);
			cambiarPantalla(0);
		}

		if (contador > tiempo) {
			al_draw_text(fuente, al_map_rgb(0, 0, 0), 300, 200, ALLEGRO_ALIGN_CENTER, "TIME OUT!");
			al_flip_display();
			al_rest(2);
			cambiarPantalla(0);
		}
		break;
	}
	case 2: {
		//acá debes escribir las reglas
		al_draw_multiline_text(fuente, al_map_rgb(255, 0, 255), 300, 40, 550, 25, ALLEGRO_ALIGN_CENTER, "viendo a ATRAPA EL GATO, en este juego tu mision es atrapar al gato con los perros. pero no te cnfies el gato es muy escurridizo y si te confias matara a tus perros y perderas el juego ");
		break;
	}
	case 3: {
		al_draw_bitmap(choose[4], 0, 0, NULL);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				al_draw_bitmap(choose[i*2+j], 89 + (332 * i), 88 + (216 * j), NULL);
			}
		}
	}
	}

}

void Game::loadContent(){
	switch (pantalla) {
	case 0: {
		// creando las opciones del menu
		menu->push_back(new Texto("Iniciar"));
		menu->push_back(new Texto("Reglas"));
		menu->push_back(new Texto("Salir"));
		int i = 0;
		// colocando la posición de las opciones de menu
		for (auto texto : *menu) {
			texto->x = 100;
			texto->y = 140 + 60 * i;
			i++;
		}
		break;
	}
	case 1:
	{
		for (int i = 0; i < 5; i++)
			matrix[i].resize(5);
		for (int i = 0; i < 5; i++)
			temp[i].resize(5);
		int margin = 90, posX = 120, posY = 46;

		// creación del mapa
		switch (this->orientacion)
		{
		case 0:
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++) {
					if (i < 2) {
						if ((j + i) % 2 == 0) {
							matrix[j][i] = "1/";
						}
						else {
							matrix[j][i] = "1 ";
						}
					}
					else
					{
						if ((i + j) % 2 == 0) {
							matrix[j][i] = "0/";
						}
						else {
							matrix[j][i] = "0 ";
						}
					}
				}
			}
			matrix[0][2] = "1/";
			matrix[1][2] = "0 ";
			matrix[2][2] = "2/";
			matrix[3][2] = "0 ";
			matrix[4][2] = "1/";
			break;

		}
		case 1:
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++) {
					if (i > 2) {
						if ((i + j) % 2 == 0) {
							matrix[i][j] = "1/";
						}
						else {
							matrix[i][j] = "1 ";
						}
					}
					else
					{
						if ((i + j) % 2 == 0) {
							matrix[i][j] = "0/";
						}
						else {
							matrix[i][j] = "0 ";
						}
					}
				}
			}
			matrix[2][0] = "1/";
			matrix[2][1] = "0 ";
			matrix[2][2] = "2/";
			matrix[2][3] = "0 ";
			matrix[2][4] = "1/";
			break;
		}
		case 2:
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++) {
					if (i < 2) {
						if ((i + j) % 2 == 0) {
							matrix[i][j] = "1/";
						}
						else {
							matrix[i][j] = "1 ";
						}
					}
					else
					{
						if ((i + j) % 2 == 0) {
							matrix[i][j] = "0/";
						}
						else {
							matrix[i][j] = "0 ";
						}
					}
				}
			}
			matrix[2][0] = "1/";
			matrix[2][1] = "0 ";
			matrix[2][2] = "2/";
			matrix[2][3] = "0 ";
			matrix[2][4] = "1/";
			break;
		}
		case 3:
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++) {
					if (i > 2) {
						if ((i + j) % 2 == 0) {
							matrix[j][i] = "1/";
						}
						else {
							matrix[j][i] = "1 ";
						}
					}
					else
					{
						if ((i + j) % 2 == 0) {
							matrix[j][i] = "0/";
						}
						else {
							matrix[j][i] = "0 ";
						}
					}
				}
			}
			matrix[0][2] = "1/";
			matrix[1][2] = "0 ";
			matrix[2][2] = "2/";
			matrix[3][2] = "0 ";
			matrix[4][2] = "1/";

			break;


		}

		}
		// creación de nodos
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++) {
				// conversión de string a entero de la matrix
				std::stringstream strValue;
				strValue << matrix[i][j][0];
				int intValue;
				strValue >> intValue;
				// creación del nodo su distancia(margin) y su posición de la esquina
				temp[i][j] = new Nodo((j * margin) + posX, (i * margin) + posY, intValue);
			}
		}
		this->gato = temp[2][2];
		// conectando caminos entre nodos
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (matrix[i][j][1] == '/') {
					//derecha
					if (j + 1 < 5) { 
						CrearCamino(temp[i][j], temp[i][j + 1], 0);
					}
					//diagonal derecha inferior
					if ((j + 1 < 5) && (i + 1 < 5)) {
						CrearCamino(temp[i][j], temp[i + 1][j + 1], 1);
					}
					//abajo
					if (i + 1 < 5) {
						CrearCamino(temp[i][j], temp[i + 1][j], 2);
					}
					//diagonal inferior izquierda
					if ((i + 1) < 5 && (j - 1) > -1) {
						CrearCamino(temp[i][j], temp[i + 1][j - 1], 3);
					}
				}
				else {
					//derecha
					if (j + 1 < 5) {
						CrearCamino(temp[i][j], temp[i][j + 1], 0);
					}
					//abajo
					if (i + 1 < 5) {
						CrearCamino(temp[i][j], temp[i + 1][j], 2);
					}
				}
			}
		}
		// imprimir matrix temporal
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++) {
				std::cout << " [" << matrix[i][j] << "] ";
			}
			std::cout << std::endl;
		}
		// colocando el primer nodo como padre
		this->ptr = temp[0][0];
		break;
	}
	}
}

//quitar el contenido
void Game::unLoadContent() {
	switch (pantalla) {
	case 0:
		free(menu);
		al_destroy_font(fuente);
		break;
	case 1:
		al_destroy_bitmap(mapa);
		al_destroy_bitmap(jugador);
		al_destroy_bitmap(iaBitmap);
		al_destroy_bitmap(libre);
		al_destroy_font(fuente);
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				delete temp[i][j];
			}
		}
		matrix.clear();
		temp.clear();

		break;
	case 3: {
		for (int i = 0; i < choose.size(); i++) al_destroy_bitmap(choose[i]);
		choose.clear();
		break;
	}
	}
}

// mata 
void Game::matar() {
	if (this->gato->der != NULL && mato==false) {
		if (this->gato->der->ficha == 1) {
			if (this->gato->der->der != NULL) {
				if (this->gato->der->der->ficha == 0) {
					this->gato->der->ficha = 0;
					this->gato->ficha = 0;
					this->gato->der->der->ficha = 2;
					this->gato = this->gato->der->der;
					this->turno = true;
					this->mato = true;	
				}
			}
		}
	}
	if (this->gato->dig_inf_der != NULL && mato == false) {
		if (this->gato->dig_inf_der->ficha == 1) {
			if (this->gato->dig_inf_der->dig_inf_der != NULL) {
				if (this->gato->dig_inf_der->dig_inf_der->ficha == 0) {
					this->gato->dig_inf_der->ficha = 0;
					this->gato->ficha = 0;
					this->gato->dig_inf_der->dig_inf_der->ficha = 2;
					this->gato = this->gato->dig_inf_der->dig_inf_der;
					this->turno = true;
					this->mato = true;
				}
			}
		}
	}
	if (this->gato->abj != NULL && mato == false) {
		if (this->gato->abj->ficha == 1) {
			if (this->gato->abj->abj != NULL) {
				if (this->gato->abj->abj->ficha == 0) {
					this->gato->abj->ficha = 0;
					this->gato->ficha = 0;
					this->gato->abj->abj->ficha = 2;
					this->gato = this->gato->abj->abj;
					this->turno = true;
					this->mato = true;
				}
			}
		}
	}
	if (this->gato->dig_inf_izq != NULL && mato == false) {
		if (this->gato->dig_inf_izq->ficha == 1) {
			if (this->gato->dig_inf_izq->dig_inf_izq != NULL) {
				if (this->gato->dig_inf_izq->dig_inf_izq->ficha == 0) {
					this->gato->dig_inf_izq->ficha = 0;
					this->gato->ficha = 0;
					this->gato->dig_inf_izq->dig_inf_izq->ficha = 2;
					this->gato = this->gato->dig_inf_izq->dig_inf_izq;
					this->turno = true;
					this->mato = true;
				}
			}
		}
	}
	if (this->gato->izq != NULL && mato == false) {
		if (this->gato->izq->ficha == 1) {
			if (this->gato->izq->izq != NULL) {
				if (this->gato->izq->izq->ficha == 0) {
					this->gato->izq->ficha = 0;
					this->gato->ficha = 0;
					this->gato->izq->izq->ficha = 2;
					this->gato = this->gato->izq->izq;
					this->turno = true;
					this->mato = true;
				}
			}
		}
	}
	if (this->gato->dig_sup_izq != NULL && mato == false) {
		if (this->gato->dig_sup_izq->ficha == 1) {
			if (this->gato->dig_sup_izq->dig_sup_izq != NULL) {
				if (this->gato->dig_sup_izq->dig_sup_izq->ficha == 0) {
					this->gato->dig_sup_izq->ficha = 0;
					this->gato->ficha = 0;
					this->gato->dig_sup_izq->dig_sup_izq->ficha = 2;
					this->gato = this->gato->dig_sup_izq->dig_sup_izq;
					this->turno = true;
					this->mato = true;
				}
			}
		}
	}
	if (this->gato->arb != NULL && mato == false) {
		if (this->gato->arb->ficha == 1) {
			if (this->gato->arb->arb != NULL) {
				if (this->gato->arb->arb->ficha == 0) {
					this->gato->arb->ficha = 0;
					this->gato->ficha = 0;
					this->gato->arb->arb->ficha = 2;
					this->gato = this->gato->arb->arb;
					this->turno = true;
					this->mato = true;
				}
			}
		}
	}
	if (this->gato->dig_sup_der != NULL && mato == false) {
		if (this->gato->dig_sup_der->ficha == 1) {
			if (this->gato->dig_sup_der->dig_sup_der != NULL) {
				if (this->gato->dig_sup_der->dig_sup_der->ficha == 0) {
					this->gato->dig_sup_der->ficha = 0;
					this->gato->ficha = 0;
					this->gato->dig_sup_der->dig_sup_der->ficha = 2;
					this->gato = this->gato->dig_sup_der->dig_sup_der;
					this->turno = true;
					this->mato = true;
				}
			}
		}
	}
	if (mato) {
		muertes++;
	}
}

// recuperar el singleton
Game &Game::GetInstance()
{
	static Game instance;
	return instance;
}

// función para cambiar pantalla
void Game::cambiarPantalla(int pantalla) {
	this->unLoadContent();
	this->pantalla = pantalla;
	this->initialize();
	this->loadContent();
	dibujar = true;
}

// función para crear un camino de doble vía
void Game::CrearCamino(Nodo* a, Nodo* b, int dire) {
	switch (dire)
	{
	case 0:
		a->der = b;
		b->izq = a;
		break;
	case 1:
		a->dig_inf_der = b;
		b->dig_sup_izq = a;
		break;
	case 2:
		a->abj = b;
		b->arb = a;
		break;
	case 3:
		a->dig_inf_izq = b;
		b->dig_sup_der = a;
		break;
	case 4:
		a->izq = b;
		b->der = a;
		break;
	case 5:
		a->dig_sup_izq = b;
		b->dig_inf_der = a;
		break;
	case 6:
		a->arb = b;
		b->abj = a;
		break;
	case 7:
		a->dig_sup_der = b;
		b->dig_inf_izq = a;
		break;
	default:
		break;
	}
}

bool Game::esAdyancente(Nodo *seleccionada, Nodo *b) {
	return (seleccionada->abj == b || seleccionada->der == b || seleccionada->izq == b ||  seleccionada->arb == b || seleccionada->dig_inf_der == b || seleccionada->dig_inf_izq == b || seleccionada->dig_sup_der == b || seleccionada->dig_sup_izq == b);
}