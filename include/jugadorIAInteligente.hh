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

  //aca se llama al minimax para que se seleccione la mejor columna posible
  int seleccionarColumna(Tablero& tableroActual);

 private:
  pair<int, int> minimax(Tablero& tableroActual, int profundidad,int alfa,int beta, bool max);
  // TODO: de momento no está bien implementada
  int determinarLineasGanadoras(Tablero& tableroCopia, bool isMax);
  int funcionHeuristica(Tablero& tableroCopia);
  int columnasDisponibles(Tablero& tableroCopia);
  string nombre;
  int profundidad;
  Ficha colorFichaMax;
  Ficha colorFichaMin;
};

#endif