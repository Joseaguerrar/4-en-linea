#include <gtest/gtest.h>

#include <tablero.hh>

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

TEST(pruebaTablero, soltarFicha) {
  Tablero tablero(5, 5);
  tablero.soltarFicha(0, Ficha::Azul);
  EXPECT_EQ(tablero.getTablero()[4][0], Ficha::Azul);
}

TEST(pruebaTablero, soltarFicha2) {
  Tablero tablero(5, 5);
  tablero.soltarFicha(3, Ficha::Azul);
  tablero.soltarFicha(3, Ficha::Rojo);
  EXPECT_EQ(tablero.getTablero()[3][3], Ficha::Rojo);
}

TEST(pruebaTablero, soltarFicha3) {
  Tablero tablero(5, 5);
  tablero.soltarFicha(1, Ficha::Azul);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Azul);
  EXPECT_EQ(tablero.getTablero()[0][1], Ficha::Azul);
}

TEST(pruebaTablero, soltarFicha4) {
  Tablero tablero(5, 5);
  tablero.soltarFicha(4, Ficha::Azul);
  EXPECT_EQ(tablero.getTablero()[4][4], Ficha::Azul);
}

TEST(pruebaTablero, puedeTirar) {
  Tablero tablero(5, 5);
  EXPECT_TRUE(tablero.puedeTirar(0));
}

TEST(pruebaTablero, puedeTirar2) {
  Tablero tablero(5, 5);
  EXPECT_TRUE(tablero.puedeTirar(4));
}

TEST(pruebaTablero, fueraRango) {
  Tablero tablero(5, 5);
  EXPECT_THROW(tablero.puedeTirar(6), invalid_argument);
}

TEST(pruebaTablero, tableroLleno) {
  Tablero tablero(4, 4);
  tablero.soltarFicha(2, Ficha::Rojo);
  tablero.soltarFicha(2, Ficha::Rojo);
  tablero.soltarFicha(2, Ficha::Azul);
  tablero.soltarFicha(2, Ficha::Rojo);
  EXPECT_FALSE(tablero.puedeTirar(2));
}

TEST(pruebaTablero, empate) {
  Tablero tablero(2, 2);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Azul);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Azul);
  EXPECT_TRUE(tablero.comprobarEmpate());
}

TEST(pruebaTablero, ganadorColumna) {
  Tablero tablero(4, 4);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(0, Ficha::Rojo);
  EXPECT_TRUE(tablero.comprobarGanador(Ficha::Rojo));
}

TEST(pruebaTablero, ganadorFila) {
  Tablero tablero(4, 4);
  tablero.soltarFicha(0, Ficha::Rojo);
  tablero.soltarFicha(1, Ficha::Rojo);
  tablero.soltarFicha(2, Ficha::Rojo);
  tablero.soltarFicha(3, Ficha::Rojo);
  EXPECT_TRUE(tablero.comprobarGanador(Ficha::Rojo));
}

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
}

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
}

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