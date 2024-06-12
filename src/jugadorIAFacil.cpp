#include <IJugador.hh>
#include <jugadorIAFacil.hh>
#include <random>
#include <string>

using namespace std;
// Constructor inicializado
jugadorIAFacil::jugadorIAFacil(string Nombre, Ficha ColorFicha)
    : nombre(Nombre), colorFicha(ColorFicha) {}
// Método que retorna el nombre
string jugadorIAFacil::getNombre() { return nombre; }
// Método que retorna el color de la ficha
Ficha jugadorIAFacil::getColorFicha() { return colorFicha; }
// Método que selecciona una columna, con base a un random
int jugadorIAFacil::seleccionarColumna(Tablero& tableroActual) {
  int numeroColumnas = tableroActual.getColumnas();
  // Creación del random
  random_device rd;
  mt19937 eng(rd());
  uniform_int_distribution<int> distr(0, tableroActual.getColumnas() - 1);
  int columnaSeleccionada = distr(eng);
  // Mientras que no pueda tirar (si la columna está llena), vuelve a pedir otro
  // random
  while (!tableroActual.puedeTirar(columnaSeleccionada)) {
    columnaSeleccionada = distr(eng);
  }
  return columnaSeleccionada;
}
