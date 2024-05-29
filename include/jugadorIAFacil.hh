#ifndef JUGADORIAFACIL_HH
#define JUGADORIAFACIL_HH

#include <tablero.hh>
#include <IJugador.hh>
#include <string>

using namespace std;

class jugadorIAFacil : public IJugador {
public:
  jugadorIAFacil(string Nombre, char ColorFicha);
  string getNombre();
  char getColorFicha();
  int seleccionarColumna(Tablero tableroActual);

private:
  string nombre;
  char colorFicha;
};

#endif