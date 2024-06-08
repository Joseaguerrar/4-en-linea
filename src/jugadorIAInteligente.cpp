#include <IJugador.hh>
#include <algorithm>
#include <iostream>
#include <jugadorIAInteligente.hh>
#include <memory>
#include <string>
#include <tablero.hh>
#include <vector>

using namespace std;

jugadorIAInteligente::jugadorIAInteligente(string Nombre, Ficha ColorFicha,
                                           int Profundidad)
    : nombre(Nombre), colorFichaMax(ColorFicha), profundidad(Profundidad),colorFichaMin((ColorFicha == Ficha::Azul) ? Ficha::Rojo : Ficha::Azul){
  
}

string jugadorIAInteligente::getNombre() { return nombre; }

Ficha jugadorIAInteligente::getColorFicha() { return colorFichaMax; }

int jugadorIAInteligente::seleccionarColumna(Tablero& tableroActual) {
  // TODO: agregar throw para manejar la excepción, igual si llega a este punto
  // el tablero debería estar lleno
  return minimax(tableroActual, profundidad, false).second;
}

pair<int, int> jugadorIAInteligente::minimax(Tablero& tableroActual,
                                             int profundidad, bool max) {
  int mejorColumna = 0;
  if (profundidad == 0 || tableroActual.comprobarGanador(colorFichaMax) ||
      tableroActual.comprobarGanador(colorFichaMin)) {
    return make_pair(funcionHeuristica(tableroActual), mejorColumna);
  }

  if (max) {
    int valorOptimo = -1000000;
    for (int j = 0; j < tableroActual.getColumnas(); j++) {
      if (tableroActual.puedeTirar(j)) {
        Tablero tableroCopia = tableroActual;
        tableroCopia.soltarFicha(j, colorFichaMax);
        int valor = minimax(tableroCopia, profundidad - 1, false).first;
        if (valor > valorOptimo) {
          valorOptimo = valor;
          mejorColumna = j;
        }
      }
    }
    return make_pair(valorOptimo, mejorColumna);
  } else {
    int valorOptimo = 1000000;
    for (int j = 0; j < tableroActual.getColumnas(); j++) {
      if (tableroActual.puedeTirar(j)) {
        Tablero tableroCopia = tableroActual;
        tableroCopia.soltarFicha(j, colorFichaMin);
        int valor = minimax(tableroCopia, profundidad - 1, true).first;
        if (valor < valorOptimo) {
          valorOptimo = valor;
          mejorColumna = j;
        }
      }
    }
    return make_pair(valorOptimo, mejorColumna);
  }
}

int jugadorIAInteligente::funcionHeuristica(Tablero& tableroCopia) {
  // comprueba si MAX ganó o MIN y retorna un valor de acuerdo a eso

  if (tableroCopia.comprobarGanador(colorFichaMax)) {
    return 1000;
  } else if (tableroCopia.comprobarGanador(colorFichaMin)) {
    return -1000;
  }
  // TODO: se debe de cambiar este último return por algo "más específico"
  return -1000;
}

int jugadorIAInteligente::determinarLineasGanadoras(Tablero& tableroCopia, bool isMax){
  int lineasGanadoras = 0
  }