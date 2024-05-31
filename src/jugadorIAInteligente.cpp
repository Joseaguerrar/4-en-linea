#include <iostream>
#include <jugadorIAInteligente.hh>
#include <memory>
#include <string>
#include <tablero.hh>
#include <vector>
using namespace std;

jugadorIAInteligente::jugadorIAInteligente(string Nombre, Ficha ColorFicha)
    : nombre(Nombre), colorFicha(ColorFicha) {}

string jugadorIAInteligente::getNombre() { return nombre; }

Ficha jugadorIAInteligente::getColorFicha() { return colorFicha; }

int jugadorIAInteligente::seleccionarColumna(Tablero tableroActual) {


  // TODO: agregar throw para manejar la excepción, igual si llega a este punto
  // el tablero debería estar lleno
  cout << "No hay jugada posible" << endl;
  return 0;
}

Tablero jugadorIAInteligente::minimax(Tablero tableroCopia, int profundidad,
                                      bool max) {}