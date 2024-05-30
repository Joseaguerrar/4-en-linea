#ifndef TABLERO_HH
#define TABLERO_HH

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

enum class Ficha { Rojo, Azul, Vacio };

class Tablero {
 public:
  // Constructores
  Tablero(int filas, int columnas);
  // Metodos
  Ficha getColorFicha();
  bool puedeTirar(int columna);
  void soltarFicha(int columna, Ficha ficha);
  bool comprobarGanador(Ficha ficha);
  bool comprobarEmpate();
  void mostrarTablero();
  int getColumnas();
  int getFilas();
  Tablero getCopiaTablero();
  vector<vector<Ficha>> getTablero();

 private:
  Ficha colorFicha;
  vector<vector<Ficha>> tablero;
  void setTablero(vector<vector<Ficha>> tableroActual);
  int filas;
  int columnas;
};

#endif