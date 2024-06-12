#ifndef JUGADORIAFACIL_HH
#define JUGADORIAFACIL_HH

#include <IJugador.hh>
#include <string>
#include <tablero.hh>

using namespace std;

class jugadorIAFacil : public IJugador {
 public:
  jugadorIAFacil();
  jugadorIAFacil(string Nombre, Ficha ColorFicha);
  string getNombre();
  Ficha getColorFicha();
  int seleccionarColumna(Tablero& tableroActual);

 private:
  string nombre;
  Ficha colorFicha;
};

#endif