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
  Tablero minimax(Tablero tableroActual, int profundidad, bool max);
  string nombre;
  Ficha colorFicha;
};

#endif