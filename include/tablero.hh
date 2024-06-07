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
  //función para que el minimax pueda volver a tener su copia al estado original en que se le pasó el tablero
  void quitarFicha();
  void mostrarTablero();
  void reiniciarTablero();
  int getColumnas();
  int getFilas();
  int getVictoriasAzul();
  int getVictoriasRojas();
  vector<vector<Ficha>> getTablero();

 private:
  Ficha colorFicha;
  vector<vector<Ficha>> tablero;
  void setTablero(vector<vector<Ficha>> tableroActual);
  int filas;
  int columnas;
  int victoriasFichaRoja;
  int victoriasFichaAzul;
};

#endif