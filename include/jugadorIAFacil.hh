#ifndef JUGADORIAFACIL_HH
#define JUGADORIAFACIL_HH

#include <Ijugador.hh>
#include <string>
using namespace std;

class jugadorIAFacil : public IJugador {
public:
  jugadorIAFacil(string Nombre, char ColorFicha);
  string getNombre();
  char getColorFicha();
  void setNombre(string Nombre);
  int seleccionarColumna(tablero tableroActual);

private:
  string nombre;
  char colorFicha;
};

#endif