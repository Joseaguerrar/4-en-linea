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
    : nombre(Nombre), colorFichaMax(ColorFicha), profundidad(Profundidad), colorFichaMin((ColorFicha == Ficha::Azul) ? Ficha::Rojo : Ficha::Azul){
  
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
  return determinarLineasGanadoras(tableroCopia, true) - determinarLineasGanadoras(tableroCopia, false);
}

int jugadorIAInteligente::determinarLineasGanadoras(Tablero& tableroCopia, bool isMax){
  Ficha ficha;
  if(isMax){
    ficha = colorFichaMax;
  }else{
    ficha = colorFichaMin;
  }
  int lineasGanadoras = 0;
  int filas = tableroCopia.getFilas();
  int columnas = tableroCopia.getColumnas();
  vector<vector<Ficha>> tablero = tableroCopia.getTablero();
  for (int i = 0; i < filas; ++i) {
    for (int j = 0; j < columnas - 3; ++j) {
      if (tablero[i][j] == ficha && tablero[i][j + 1] == ficha &&
          tablero[i][j + 2] == ficha && tablero[i][j + 3] == ficha) {
        lineasGanadoras++;
      }
    }
  }
  // Columnas//
  for (int i = 0; i < filas - 3; ++i) {
    for (int j = 0; j < columnas; ++j) {
      if (tablero[i][j] == ficha && tablero[i + 1][j] == ficha &&
          tablero[i + 2][j] == ficha && tablero[i + 3][j] == ficha) {
        lineasGanadoras++;;
      }
    }
  }
  // Diagonal Derecha
  for (int i = 0; i < filas - 3; ++i) {
    for (int j = 0; j < columnas - 3; ++j) {
      if (tablero[i][j] == ficha && tablero[i + 1][j + 1] == ficha &&
          tablero[i + 2][j + 2] == ficha && tablero[i + 3][j + 3] == ficha) {
        lineasGanadoras++;
      }
    }
  }
  // Diagonal Izquierda
  for (int i = 0; i < filas - 3; ++i) {
    for (int j = 3; j < columnas; ++j) {
      if (tablero[i][j] == ficha && tablero[i + 1][j - 1] == ficha &&
          tablero[i + 2][j - 2] == ficha && tablero[i + 3][j - 3] == ficha) {
        lineasGanadoras++;
      }
    }
  }
  return lineasGanadoras;
}