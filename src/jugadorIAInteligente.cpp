#include <iostream>
#include <jugadorIAInteligente.hh>
#include <memory>
#include <IJugador.hh>
#include <string>
#include <tablero.hh>
#include <vector>
#include <algorithm>

using namespace std;

jugadorIAInteligente::jugadorIAInteligente(string Nombre, Ficha ColorFicha)
    : nombre(Nombre), colorFichaMax(ColorFicha) {
  if (ColorFicha == Ficha::Azul) {
    colorFichaMin = Ficha::Rojo;
  } else {
    colorFichaMin = Ficha::Azul;
  }
}

string jugadorIAInteligente::getNombre() { return nombre; }

Ficha jugadorIAInteligente::getColorFicha() { return colorFichaMax; }

int jugadorIAInteligente::seleccionarColumna(Tablero tableroActual) {
  // TODO: agregar throw para manejar la excepción, igual si llega a este punto
  // el tablero debería estar lleno
  cout << "No hay jugada posible" << endl;
  return 0;
}

int jugadorIAInteligente::minimax(Tablero* tableroActual, int profundidad,
                                  bool max) {
  vector<vector<Ficha>> tableroFichas = tableroActual->getTablero();
  if (profundidad == 0 || tableroActual->comprobarGanador(colorFichaMax) ||
      tableroActual->comprobarGanador(colorFichaMin)) {
    return distanciaHeuristica(tableroActual);
  }
  if (max) {
    int valorOptimo = -1000;
    for (int j = 0; j < tableroActual->getColumnas(); j++) {
      // comprueba si puede tirar y luego suelta la ficha
      if (tableroActual->puedeTirar(j)) {
        Tablero tableroCopia(*tableroActual);
        tableroActual->soltarFicha(j, colorFichaMax);
        valorOptimo = std::max(valorOptimo, minimax(tableroActual, profundidad -1, false));
        tableroActual = &tableroCopia;
      }
    }
    return valorOptimo;
  } else {
    int columnaAseleccionar = 1000;
    for (int j = 0; j < tableroActual->getColumnas(); j++){
      if(tableroActual->puedeTirar(j)){
        Tablero tableroCopia(*tableroActual);
        tableroActual->soltarFicha(j, colorFichaMin);
        columnaAseleccionar = std::min(columnaAseleccionar, minimax(tableroActual, profundidad-1,true));
        tableroActual = &tableroCopia;
      }
    }
    return columnaAseleccionar;
  }
}

int jugadorIAInteligente::distanciaHeuristica(Tablero* tableroCopia) {
  // comprueba si MAX ganó o MIN y retorna un valor de acuerdo a eso

  if (tableroCopia->comprobarGanador(colorFichaMax)) {
    return 1000;
  } else if (tableroCopia->comprobarGanador(colorFichaMin)) {
    return -1000;
  }
  // TODO: se debe de cambiar este último return por algo "más específico"
  return -1000;
}
