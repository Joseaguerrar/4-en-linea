#ifndef JUGADORHUMANO_HH
#define JUGADORHUMANO_HH

#include <tablero.hh>
#include <IJugador.hh>
#include <string>

using namespace std;

class jugadorHumano : public IJugador {
public:
  jugadorHumano();
  jugadorHumano(string Nombre, Ficha ColorFicha);
  string getNombre();
  Ficha getColorFicha();
  int seleccionarColumna(Tablero tableroActual);

private:
  string nombre;
  Ficha colorFicha;
};

#endif