#include <IJugador.hh>
#include <iostream>
#include <jugadorHumano.hh>
#include <random>
#include <string>

using namespace std;
jugadorHumano::jugadorHumano() {}
jugadorHumano::jugadorHumano(string Nombre, Ficha ColorFicha)
    : nombre(Nombre), colorFicha(ColorFicha) {}

string jugadorHumano::getNombre() { return nombre; }

Ficha jugadorHumano::getColorFicha() { return colorFicha; }

int jugadorHumano::seleccionarColumna(Tablero& tableroActual) {
  int columnaSeleccionada = tableroActual.getColumnas();
  cout << "Ingrese la columna donde desea soltar la ficha: " << endl;
  cin >> columnaSeleccionada;
  columnaSeleccionada--;
  while (!tableroActual.puedeTirar(columnaSeleccionada)) {
    cout << "La colummna seleccionada no es válida, ingrese otra: " << endl;
    cin >> columnaSeleccionada;
    columnaSeleccionada--;
  }
  return columnaSeleccionada;
}
