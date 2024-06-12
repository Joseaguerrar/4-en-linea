#include <gtest/gtest.h>

#include <tablero.hh>

// Prueba de que se está creando bien el tablero
TEST(pruebaTablero, constructor) {
  Tablero tablero(4, 4);
  EXPECT_EQ(tablero.getColumnas(), 4);
  EXPECT_EQ(tablero.getFilas(), 4);
  for (int i = 0; i < tablero.getFilas(); i++) {
    for (int j = 0; j < tablero.getColumnas(); j++) {
      Ficha celda = tablero.getTablero()[i][j];
      EXPECT_EQ(celda, Ficha::Vacio);
    }
  }
}
// Prueba de que se está soltando la ficha en la columna 0
TEST(pruebaTablero, soltarFicha) {
  Tablero tablero(5, 5);
  tablero.soltarFicha(0, Ficha::Azul);
  EXPECT_EQ(tablero.getTablero()[4][0], Ficha::Azul);
}
// Prueba de que se está soltando la ficha en la columna 3
TEST(pruebaTablero, soltarFicha2) {
  Tablero tablero(5, 5);
  tablero.soltarFicha(3, Ficha::Azul);
  tablero.soltarFicha(3, Ficha::Rojo);
  EXPECT_EQ(tablero.getTablero()[3][3], Ficha::Rojo);
}
// Prueba de que se está soltando las fichas una arriba de otra
TEST(pruebaTablero, soltarFicha3) {
  Tablero tablero(5, 5);
  tablero.soltarFicha(1, Ficha::Azul);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Azul);
  EXPECT_EQ(tablero.getTablero()[0][1], Ficha::Azul);
}
// Prueba de que se está soltando la ficha en la columna de límite superior
TEST(pruebaTablero, soltarFicha4) {
  Tablero tablero(5, 5);
  tablero.soltarFicha(4, Ficha::Azul);
  EXPECT_EQ(tablero.getTablero()[4][4], Ficha::Azul);
}
// Prueba de que se puede tirar en la columna 0
TEST(pruebaTablero, puedeTirar) {
  Tablero tablero(5, 5);
  EXPECT_TRUE(tablero.puedeTirar(0));
}
// Prueba de que se puede tirar en la columna de límite superior
TEST(pruebaTablero, puedeTirar2) {
  Tablero tablero(5, 5);
  EXPECT_TRUE(tablero.puedeTirar(4));
}
// Prueba de que la columna seleccionada está fuera del rango, por lo que no se
// puede tirar
TEST(pruebaTablero, fueraRango) {
  Tablero tablero(5, 5);
  EXPECT_FALSE(tablero.puedeTirar(6));
}
// Prueba de que la columna seleccionada está llena, por lo que no se puede
// tirar
TEST(pruebaTablero, tableroLleno) {
  Tablero tablero(4, 4);
  tablero.soltarFicha(2, Ficha::Rojo);
  tablero.soltarFicha(2, Ficha::Rojo);
  tablero.soltarFicha(2, Ficha::Azul);
  tablero.soltarFicha(2, Ficha::Rojo);
  EXPECT_FALSE(tablero.puedeTirar(2));
}
// Prueba de que se está haciendo un empate, no hubo ningún ganador y el tablero
// está lleno Además de que las victorias se mantienen en 0
TEST(pruebaTablero, empate) {
  Tablero tablero(2, 2);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Azul);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Azul);
  EXPECT_FALSE(tablero.comprobarGanador(Ficha::Rojo));
  EXPECT_FALSE(tablero.comprobarGanador(Ficha::Azul));
  EXPECT_TRUE(tablero.comprobarEmpate());
  EXPECT_EQ(tablero.getVictoriasAzul(), 0);
  EXPECT_EQ(tablero.getVictoriasRojas(), 0);
}
// Prueba de que se está ganando el jugador con ficha roja de manera vertical
// Además de que se aumentan las victorias al jugador de ficha roja
TEST(pruebaTablero, ganadorColumna) {
  Tablero tablero(4, 4);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Rojo);
  EXPECT_TRUE(tablero.comprobarGanador(Ficha::Rojo));
  EXPECT_EQ(tablero.getVictoriasAzul(), 0);
  EXPECT_EQ(tablero.getVictoriasRojas(), 1);
}
// Prueba de que se está ganando el jugador con ficha roja de manera horizontal
// Además de que se aumentan las victorias al jugador de ficha roja
TEST(pruebaTablero, ganadorFila) {
  Tablero tablero(4, 4);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(2, Ficha::Rojo);
  tablero.soltarFicha(3, Ficha::Rojo);
  EXPECT_TRUE(tablero.comprobarGanador(Ficha::Rojo));
  EXPECT_EQ(tablero.getVictoriasAzul(), 0);
  EXPECT_EQ(tablero.getVictoriasRojas(), 1);
}
// Prueba de que se está ganando el jugador con ficha azul de manera diagonal
// derecha Además de que se aumentan las victorias al jugador de ficha azul
TEST(pruebaTablero, ganadorDiagonalDerecha) {
  Tablero tablero(4, 4);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(2, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Azul);
  tablero.soltarFicha(1, Ficha::Azul);
  tablero.soltarFicha(2, Ficha::Azul);
  tablero.soltarFicha(3, Ficha::Azul);
  EXPECT_TRUE(tablero.comprobarGanador(Ficha::Azul));
  EXPECT_EQ(tablero.getVictoriasAzul(), 1);
  EXPECT_EQ(tablero.getVictoriasRojas(), 0);
}
// Prueba de que se está ganando el jugador con ficha azul de manera diagonal
// izquierda Además de que se aumentan las victorias al jugador de ficha azul
TEST(pruebaTablero, ganadorDiagonalIzquierda) {
  Tablero tablero(4, 4);
  tablero.soltarFicha(3, Ficha::Rojo);
  tablero.soltarFicha(3, Ficha::Rojo);
  tablero.soltarFicha(3, Ficha::Rojo);
  tablero.soltarFicha(2, Ficha::Rojo);
  tablero.soltarFicha(2, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Azul);
  tablero.soltarFicha(1, Ficha::Azul);
  tablero.soltarFicha(2, Ficha::Azul);
  tablero.soltarFicha(3, Ficha::Azul);
  EXPECT_TRUE(tablero.comprobarGanador(Ficha::Azul));
  EXPECT_EQ(tablero.getVictoriasAzul(), 1);
  EXPECT_EQ(tablero.getVictoriasRojas(), 0);
}
// Prueba de que se está copiando correctamente el tablero actual con el tablero
// copia
TEST(pruebaTablero, copiaCorrectamenteCreada) {
  Tablero tablero(4, 4);
  Tablero copia = tablero;
  EXPECT_EQ(tablero.getColumnas(), 4);
  EXPECT_EQ(tablero.getFilas(), 4);
  for (int i = 0; i < tablero.getFilas(); i++) {
    for (int j = 0; j < tablero.getColumnas(); j++) {
      Ficha celda = tablero.getTablero()[i][j];
      Ficha celdaCopia = copia.getTablero()[i][j];
      EXPECT_EQ(celda, celdaCopia);
    }
  }
}
// Prueba de que está ganado el jugador de ficha azul de manera diagonal
// izquierda, además de que se
// está incrementando las victorias para el jugador de ficha azul, lusgo se
// comprueba que se reinicie
// correctamente el tablero y se verifica que todos los campos del tablero
// actual estén vacíos Por último de vuelve a comprobar que el jugador de ficha
// azul gana de manera de diagonal izquierda
// y se le aumentan las victorias 2 a 0 a favor del jugador de ficha azul
TEST(pruebaTablero, reiniciarTablero) {
  Tablero tablero(4, 4);
  tablero.soltarFicha(3, Ficha::Rojo);
  tablero.soltarFicha(3, Ficha::Rojo);
  tablero.soltarFicha(3, Ficha::Rojo);
  tablero.soltarFicha(2, Ficha::Rojo);
  tablero.soltarFicha(2, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Azul);
  tablero.soltarFicha(1, Ficha::Azul);
  tablero.soltarFicha(2, Ficha::Azul);
  tablero.soltarFicha(3, Ficha::Azul);
  EXPECT_TRUE(tablero.comprobarGanador(Ficha::Azul));
  EXPECT_EQ(tablero.getVictoriasAzul(), 1);
  EXPECT_EQ(tablero.getVictoriasRojas(), 0);

  tablero.reiniciarTablero();

  for (int i = 0; i < tablero.getFilas(); i++) {
    for (int j = 0; j < tablero.getColumnas(); j++) {
      Ficha celda = tablero.getTablero()[i][j];
      EXPECT_EQ(celda, Ficha::Vacio);
    }
  }
  tablero.soltarFicha(3, Ficha::Rojo);
  tablero.soltarFicha(3, Ficha::Rojo);
  tablero.soltarFicha(3, Ficha::Rojo);
  tablero.soltarFicha(2, Ficha::Rojo);
  tablero.soltarFicha(2, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Azul);
  tablero.soltarFicha(1, Ficha::Azul);
  tablero.soltarFicha(2, Ficha::Azul);
  tablero.soltarFicha(3, Ficha::Azul);
  EXPECT_TRUE(tablero.comprobarGanador(Ficha::Azul));
  EXPECT_EQ(tablero.getVictoriasAzul(), 2);
  EXPECT_EQ(tablero.getVictoriasRojas(), 0);
}

// Prueba de que se esta reiniciando el tablero al haber un empate (tablero
// lleno)
TEST(pruebaTablero, reiniciarTableroLleno) {
  Tablero tablero(4, 4);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Azul);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Azul);
  tablero.soltarFicha(2, Ficha::Rojo);
  tablero.soltarFicha(2, Ficha::Rojo);
  tablero.soltarFicha(2, Ficha::Azul);
  tablero.soltarFicha(2, Ficha::Azul);
  tablero.soltarFicha(3, Ficha::Azul);
  tablero.soltarFicha(3, Ficha::Azul);
  tablero.soltarFicha(3, Ficha::Azul);
  tablero.soltarFicha(3, Ficha::Rojo);
  EXPECT_FALSE(tablero.comprobarGanador(Ficha::Azul));
  EXPECT_FALSE(tablero.comprobarGanador(Ficha::Rojo));
  EXPECT_EQ(tablero.getVictoriasAzul(), 0);
  EXPECT_EQ(tablero.getVictoriasRojas(), 0);

  tablero.reiniciarTablero();

  for (int i = 0; i < tablero.getFilas(); i++) {
    for (int j = 0; j < tablero.getColumnas(); j++) {
      Ficha celda = tablero.getTablero()[i][j];
      EXPECT_EQ(celda, Ficha::Vacio);
    }
  }
}