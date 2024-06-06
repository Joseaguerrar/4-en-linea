#ifndef IJUGADOR_HH
#define IJUGADOR_HH

#include <string>
#include <tablero.hh>

using namespace std;

class IJugador {
 protected:
  virtual string getNombre();
  virtual void setNombre(string Nombre);
  virtual Ficha getColorFicha();
  virtual int seleccionarColumna(Tablero tableroActual);
};

#endif