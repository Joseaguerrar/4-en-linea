#include <iostream>
#include <jugadorIAInteligente.hh>
#include <memory>
#include <string>
#include <tablero.hh>
#include <vector>
using namespace std;

jugadorIAInteligente::jugadorIAInteligente(string Nombre, char ColorFicha)
    : nombre(Nombre), colorFicha(ColorFicha) {}

string jugadorIAInteligente::getNombre() { return nombre; }

char jugadorIAInteligente::getColorFicha() { return colorFicha; }

int jugadorIAInteligente::seleccionarColumna(Tablero tableroActual) {
  Tablero copiaTablero = tableroActual.getCopiaTablero();
  copiaTablero = minimax(copiaTablero, 5, true);

  vector<vector<char>> tableroSinModificar = tableroActual.getTablero();
  vector<vector<char>> tableroModificado = copiaTablero.getTablero();

  for (int i = 0; i < tableroActual.getFilas(); i++) {
    for (int j = 0; j < tableroActual.getColumnas(); j++) {
      if (tableroSinModificar[i][j] != tableroModificado[i][j]) {
        return j;
      }
    }
  }
  // TODO: agregar throw para manejar la excepción, igual si llega a este punto
  // el tablero debería estar lleno
  cout << "No hay jugada posible" << endl;
  return 0;
}

Tablero jugadorIAInteligente::minimax(Tablero tableroCopia, int profundidad, bool max) {}