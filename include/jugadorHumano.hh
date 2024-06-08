#ifndef JUGADORHUMANO_HH
#define JUGADORHUMANO_HH

#include <IJugador.hh>
#include <string>
#include <tablero.hh>

using namespace std;

class jugadorHumano : public IJugador {
 public:
  jugadorHumano();
  jugadorHumano(string Nombre, Ficha ColorFicha);
  string getNombre();
  Ficha getColorFicha();
  int seleccionarColumna(Tablero& tableroActual);

 private:
  string nombre;
  Ficha colorFicha;
};

#endif