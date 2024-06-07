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
  EXPECT_FALSE(tablero.puedeTirar(6));
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
  EXPECT_EQ(tablero.getVictoriasAzul(), 0);
  EXPECT_EQ(tablero.getVictoriasRojas(), 0);
}

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

TEST(pruebaTablero, reiniciarTablero){
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