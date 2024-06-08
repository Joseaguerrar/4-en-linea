#include <iostream>
#include <memory>
#include <string>
#include <tablero.hh>
#include <vector>

using namespace std;

// Constructor inicializado en las filas y columnas que quiere el usuario
Tablero::Tablero(int filas, int columnas)
    : tablero(filas, vector<Ficha>(columnas, Ficha::Vacio)),
      filas(filas),
      columnas(columnas) {}

// Metodo que devuelve el tablero actual
vector<vector<Ficha>> Tablero::getTablero() { return tablero; }

// Metodo que obtiene la cantidad de columnas para ser utilizadas en otras
// clases
int Tablero::getColumnas() { return columnas; }

// Metodo que obtiene la cantidad de filas para ser utilizadas en otras clases
int Tablero::getFilas() { return filas; }

// Metodo que devuelve el enum de colorFicha
Ficha Tablero::getColorFicha() { return colorFicha; }

// Metodo que verifica si el jugador puede soltar una ficha en una columna
// seleccionada
bool Tablero::puedeTirar(int columna) {
  // Caso en que la columna este fuera de rango
  if (columna < 0 || columna >= columnas) {
    return false;
  }
  // Caso en que la columna este llena
  if (tablero[0][columna] != Ficha::Vacio) {
    return false;
  }
  return true;
}

// Metodo privado que setea el tablero actual en una variable tablero
void Tablero::setTablero(vector<vector<Ficha>> tableroActual) {
  tablero = tableroActual;
}

// metodo para reiniciar el tablero y volver a jugar si se desea
void Tablero::reiniciarTablero() {
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      tablero[i][j] = Ficha::Vacio;
    }
  }
}

// Metodo que suelta la ficha en la columna indicada que escogio el usuario
void Tablero::soltarFicha(int columna, Ficha ficha) {
  int filasTemp = filas - 1;
  while (tablero[filasTemp][columna] != Ficha::Vacio && filasTemp >= 0) {
    filasTemp--;
  }
  tablero[filasTemp][columna] = ficha;
}

// Metodo que comprueba al ganador
bool Tablero::comprobarGanador(Ficha ficha) {
  // Filas//
  for (int i = 0; i < filas; ++i) {
    for (int j = 0; j < columnas - 3; ++j) {
      if (tablero[i][j] == ficha && tablero[i][j + 1] == ficha &&
          tablero[i][j + 2] == ficha && tablero[i][j + 3] == ficha) {
            if (ficha==Ficha::Azul)
            {
              setvictoriasA(getVictoriasAzul()+1);
            }
            else if (ficha==Ficha::Rojo)
            {
              setvictoriasR(getVictoriasRojas()+1);
            } 
        return true;
      }
    }
  }
  // Columnas//
  for (int i = 0; i < filas - 3; ++i) {
    for (int j = 0; j < columnas; ++j) {
      if (tablero[i][j] == ficha && tablero[i + 1][j] == ficha &&
          tablero[i + 2][j] == ficha && tablero[i + 3][j] == ficha) {
             if (ficha==Ficha::Azul)
            {
              setvictoriasA(getVictoriasAzul()+1);
            }
            else if (ficha==Ficha::Rojo)
            {
              setvictoriasR(getVictoriasRojas()+1);
            } 
        return true;
      }
    }
  }
  // Diagonal Derecha
  for (int i = 0; i < filas - 3; ++i) {
    for (int j = 0; j < columnas - 3; ++j) {
      if (tablero[i][j] == ficha && tablero[i + 1][j + 1] == ficha &&
          tablero[i + 2][j + 2] == ficha && tablero[i + 3][j + 3] == ficha) {
             if (ficha==Ficha::Azul)
            {
              setvictoriasA(getVictoriasAzul()+1);
            }
            else if (ficha==Ficha::Rojo)
            {
              setvictoriasR(getVictoriasRojas()+1);
            } 
        return true;
      }
    }
  }
  // Diagonal Izquierda
  for (int i = 0; i < filas - 3; ++i) {
    for (int j = 3; j < columnas; ++j) {
      if (tablero[i][j] == ficha && tablero[i + 1][j - 1] == ficha &&
          tablero[i + 2][j - 2] == ficha && tablero[i + 3][j - 3] == ficha) {
             if (ficha==Ficha::Azul)
            {
              setvictoriasA(getVictoriasAzul()+1);
            }
            else if (ficha==Ficha::Rojo)
            {
              setvictoriasR(getVictoriasRojas()+1);
            } 
        return true;
      }
    }
  }

  victoriasFichaAzul--;
  victoriasFichaRoja--;
  return false;
}

// Metodo que comprueba si hubo un empate
bool Tablero::comprobarEmpate() {
  // Si alguno es vacío, retorna falso//
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      if (tablero[i][j] == Ficha::Vacio) {
        return false;
      }
    }
  }
  return true;
}

// Metodo que muestra el tablero (sera necesario para imprimir el juego en
// consola)
void Tablero::mostrarTablero() {
  // Nuevo
  cout<<endl;
  for (int i = 0; i < columnas; i++) {
    cout<< " " << i + 1 << " ";
  }
  cout << endl;
  // Nuevo
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      if (tablero[i][j] == Ficha::Rojo) {
        cout << "|O|";
      } else if (tablero[i][j] == Ficha::Azul) {
        cout << "|X|";
      } else {
        cout << "|_|";
      }
    }
    cout << endl;
  }
}
void Tablero::setvictoriasA(int n){
  victoriasFichaAzul=n;
}
void Tablero::setvictoriasR(int n){
  victoriasFichaRoja=n;
}
// Retorna el numero de victorias del jugador con fichas azules
int Tablero::getVictoriasAzul() { return victoriasFichaAzul; }
// Retorna el numero de victorias del jugador con fichas rojas
int Tablero::getVictoriasRojas() { return victoriasFichaRoja; }