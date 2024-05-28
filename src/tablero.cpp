#include <iostream>
#include <memory>
#include <string>
#include <tablero.hh>
#include <vector>

using namespace std;

// Constructor inicializado en las filas y columnas que quiere el usuario
Tablero::Tablero(int filas, int columnas)
    : tablero(filas, vector<char>(columnas, '_')),
      filas(filas),
      columnas(columnas) {}

// Metodo que obtiene la cantidad de columnas para ser utilizadas en otras
// clases
int Tablero::getColumnas() { return columnas; }

// Metodo que obtiene la cantidad de filas para ser utilizxadas en otras clases
int Tablero::getFilas() { return filas; }

// Metodo que verifica si el jugador puede soltar una ficha en una columna
// seleccionada
bool Tablero::puedeTirar(int columna) {
  // Caso en que la columna este fuera de rango
  if (columna < 0 && columna > getColumnas()) {
    throw invalid_argument("Columna seleccionada fuera del rango de la matriz");
    return false;
  }
  // Caso en que la columna este llena
  if (tablero[0][columnas] != '_') {
    throw range_error("Columna llena, no puede agregar mas caracteres");
    return false;
  }
  return true;
}

// Metodo que retorna una copia del tablero actual
Tablero Tablero::getCopiaTablero() {
  Tablero copiaTablero(filas, columnas);
  copiaTablero.setTablero(tablero);
  return copiaTablero;
}

// Metodo privado que setea el tablero actual en una variable tablero
void Tablero::setTablero(vector<vector<char>> tableroActual) {
  tablero = tableroActual;
}

// Metodo que suelta la ficha en la columna indicada que escogio el usuario
bool Tablero::soltarFicha(int columna, char ficha) {
  int filasTemp = filas - 1;
  while (tablero[filasTemp][columna] != '_' && filasTemp >= 0) {
    filasTemp--;
  }
  tablero[filasTemp][columna] = ficha;
  return true;
}

//Comprobar ganador
bool Tablero:: comprobarGanador(char ficha) {
  //Filas//
  for (int i = 0; i < filas; ++i) {
    for (int j = 0; j < columnas - 3; ++j) {
      if (tablero[i][j] == ficha && tablero[i][j + 1] == ficha && tablero[i][j + 2] == ficha && tablero[i][j + 3] == ficha) {
          return true;
      }
    }
  }
  //Columnas//
  for (int i = 0; i < filas-3; ++i) {
    for (int j = 0; j < columnas; ++j) {
      if (tablero[i][j] == ficha && tablero[i+1][j] == ficha && tablero[i+2][j] == ficha && tablero[i+3][j] == ficha) {
          return true;
      }
    }
  }
  //Diagonal Derecha
  for (int i = 0; i < filas-3; ++i) {
    for (int j = 0; j < columnas - 3; ++j) {
      if (tablero[i][j] == ficha && tablero[i+1][j + 1] == ficha && tablero[i+2][j + 2] == ficha && tablero[i+3][j + 3] == ficha) {
          return true;
      }
    }
  }
  //Diagonal Izquierda
  for (int i = 0; i < filas-3; ++i) {
    for (int j = 0; j < columnas; ++j) {
      if (tablero[i][j] == ficha && tablero[i+1][j - 1] == ficha && tablero[i+2][j -2 ] == ficha && tablero[i+3][j - 3] == ficha) {
          return true;
      }
    }
  }
}
bool Tablero:: comprobarEmpate(){
  //Si alguno es vacío, retorna falso//
  for (int i = 0; i < filas; i++){
    for (int j = 0; j < columnas; j++){
        if (true)
        {
         tablero[i][j]=='_';
         return false;
        } 
    }
  }
  return true;
}
