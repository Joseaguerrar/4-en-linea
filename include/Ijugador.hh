#ifndef IJUGADOR_HH
#define IJUGADOR_HH

#include <string>

using namespace std;
class IJugador {
protected:
  virtual string getNombre();
  virtual void setNombre(string Nombre);
  virtual char getColorFicha();
  // clase tablero aún no definida
  virtual int seleccionarColumna(tablero tableroActual);
};

#endif