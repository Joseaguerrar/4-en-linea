#ifndef JUGADORIAINTELIGENTE_HH
#define JUGADORIAINTELIGENTE_HH

#include <IJugador.hh>
#include <memory>
#include <string>
#include <tablero.hh>

using namespace std;

class jugadorIAInteligente : public IJugador {
 public:
  jugadorIAInteligente(string Nombre, char ColorFicha);
  string getNombre();
  char getColorFicha();
  int seleccionarColumna(Tablero tableroActual);

 private:
  Tablero minimax(Tablero tableroActual, int profundidad, bool max);
  string nombre;
  char colorFicha;
};

#endif