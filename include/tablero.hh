#ifndef TABLERO_HH
#define TABLERO_HH

#include <memory>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tablero {
 public:
  // Constructores
  Tablero(int filas, int columnas);
  // Metodos
  bool puedeTirar(int columna);
  bool soltarFicha(int columna, char ficha);
  bool comprobarGanador(char ficha);
  bool comprobarEmpate();
  char mostrarTablero();
  int getColumnas();
  int getFilas();
  Tablero getCopiaTablero();
  vector<vector<char>> getTablero();

 private:
  vector<vector<char>> tablero;
  void setTablero(vector<vector<char>> tableroActual);
  int filas;
  int columnas;
};

#endif