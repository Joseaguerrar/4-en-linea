#ifndef IJUGADOR_HH
#define IJUGADOR_HH

#include <string>
#include <tablero.hh>

using namespace std;

class IJugador {
 public:
  virtual string getNombre() = 0;
  virtual Ficha getColorFicha() = 0;
  virtual int seleccionarColumna(Tablero& tableroActual) = 0;
};

#endif