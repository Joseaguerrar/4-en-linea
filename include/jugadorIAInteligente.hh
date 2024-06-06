#ifndef JUGADORIAINTELIGENTE_HH
#define JUGADORIAINTELIGENTE_HH

#include <IJugador.hh>
#include <memory>
#include <string>
#include <tablero.hh>

using namespace std;

class jugadorIAInteligente : public IJugador {
 public:
  jugadorIAInteligente();
  jugadorIAInteligente(string Nombre, Ficha ColorFicha, int Profundidad);
  string getNombre();
  Ficha getColorFicha();
  int seleccionarColumna(Tablero tableroActual);

 private:
  pair<int, int> minimax(Tablero& tableroActual, int profundidad, bool max);
  //TODO: de momento no está bien implementada
  int distanciaHeuristica(Tablero& tableroCopia);
  string nombre;
  int profundidad;
  Ficha colorFichaMax;
  Ficha colorFichaMin;
};

#endif