#ifndef JUGADORIAINTELIGENTE_HH
#define JUGADORIAINTELIGENTE_HH

#include <IJugador.hh>
#include <memory>
#include <string>
#include <tablero.hh>

using namespace std;

class jugadorIAInteligente : public IJugador {
 public:
  jugadorIAInteligente(string Nombre, Ficha ColorFicha);
  string getNombre();
  Ficha getColorFicha();
  int seleccionarColumna(Tablero tableroActual);

 private:
  int minimax(Tablero* tableroActual, int profundidad, bool max);
  //TODO: de momento no está bien implementada
  int distanciaHeuristica(Tablero* tableroCopia);
  string nombre;
  Ficha colorFichaMax;
  Ficha colorFichaMin;
};

#endif