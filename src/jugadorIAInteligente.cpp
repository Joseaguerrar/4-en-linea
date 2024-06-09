#include <IJugador.hh>
#include <algorithm>
#include <iostream>
#include <jugadorIAInteligente.hh>
#include <memory>
#include <string>
#include <tablero.hh>
#include <vector>
#include <limits>

using namespace std;

jugadorIAInteligente::jugadorIAInteligente(string Nombre, Ficha ColorFicha,
                                           int Profundidad)
    : nombre(Nombre), colorFichaMax(ColorFicha), profundidad(Profundidad), colorFichaMin((ColorFicha == Ficha::Azul) ? Ficha::Rojo : Ficha::Azul){
  
}

string jugadorIAInteligente::getNombre() { return nombre; }

Ficha jugadorIAInteligente::getColorFicha() { return colorFichaMax; }

int jugadorIAInteligente::seleccionarColumna(Tablero& tableroActual) {
  // TODO: agregar throw para manejar la excepción, igual si llega a este punto
  // el tablero debería estar lleno
  int menosInfinito = numeric_limits<int>::min();
  int masInfinito = numeric_limits<int>::max();
  return minimax(tableroActual, profundidad,menosInfinito,masInfinito,true).second;
}

pair<int, int> jugadorIAInteligente::minimax(Tablero& tableroActual,
                                             int profundidad, int alfa, int beta, bool max) {
  int mejorColumna = -1;  // Inicializamos a un valor no válido
  if (profundidad == 0 || tableroActual.comprobarGanador(colorFichaMax) ||
      tableroActual.comprobarGanador(colorFichaMin)) {
    return make_pair(funcionHeuristica(tableroActual), mejorColumna);
  }

  if (max) {
    int valor = numeric_limits<int>::min();
    for (int j = 0; j < tableroActual.getColumnas(); j++) {
      if (tableroActual.puedeTirar(j)) {
        cout << j << endl;
        Tablero tableroCopia = tableroActual;
        tableroCopia.soltarFicha(j, colorFichaMax);
        int valorActual = minimax(tableroCopia, profundidad - 1, alfa, beta, false).first;
        if (valorActual > valor) {
          valor = valorActual;
          mejorColumna = j;
        }
        alfa = std::max(alfa, valor);
        if (alfa >= beta) {
          break;  // Poda beta
        }
      }
    }
    return make_pair(valor, mejorColumna);
  } else {
    int valor = numeric_limits<int>::max();
    for (int j = 0; j < tableroActual.getColumnas(); j++) {
      if (tableroActual.puedeTirar(j)) {
        Tablero tableroCopia = tableroActual;
        tableroCopia.soltarFicha(j, colorFichaMin);
        int valorActual = minimax(tableroCopia, profundidad - 1, alfa, beta, true).first;
        if (valorActual < valor) {
          valor = valorActual;
          mejorColumna = j;
        }
        beta = std::min(beta, valor);
        if (alfa >= beta) {
          break;  // Poda alfa
        }
      }
    }
    return make_pair(valor, mejorColumna);
  }
}

int jugadorIAInteligente::funcionHeuristica(Tablero& tableroCopia) {
  // comprueba si MAX ganó o MIN y retorna un valor de acuerdo a eso

  if (tableroCopia.comprobarGanador(colorFichaMax)) {
    return 1000;
  } else if (tableroCopia.comprobarGanador(colorFichaMin)) {
    return -1000;
  }
  return determinarLineasGanadoras(tableroCopia, true) - determinarLineasGanadoras(tableroCopia, false);
}

int jugadorIAInteligente::determinarLineasGanadoras(Tablero& tableroCopia, bool isMax){
  int lineasGanadoras = 0
  }