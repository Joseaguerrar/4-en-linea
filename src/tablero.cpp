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
    // Hacer los throw
    cout << "Columna fuera de rango" << endl;
    return false;
  }
  // Caso en que la columna este llena
  if (tablero[0][columnas] != '_') {
    // Hacer los throw
    cout << "Columna llena" << endl;
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
bool verificarGanador(char ficha) {

}

