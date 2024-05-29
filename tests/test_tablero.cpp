#include <gtest/gtest.h>
#include <tablero.hh>

TEST(pruebaTablero, constructor){
    Tablero tablero(4,4);
    EXPECT_EQ(tablero.getColumnas(), 4);
    EXPECT_EQ(tablero.getFilas(), 4);
    for(int i = 0; i < tablero.getFilas(); i++){
        for(int j = 0; j < tablero.getColumnas(); j++){
            Ficha celda = tablero.getTablero()[i][j];
            EXPECT_EQ(celda, Ficha::Vacio);
        }
    }
}

TEST(pruebaTablero, soltarFicha){
    Tablero tablero(5,5);
    tablero.soltarFicha(0, Ficha::Azul);
    EXPECT_EQ(tablero.getTablero()[4][0], Ficha::Azul);
}

TEST(pruebaTablero, soltarFicha2){
    Tablero tablero(5,5);
    tablero.soltarFicha(3, Ficha::Azul);
    tablero.soltarFicha(3, Ficha::Rojo);
    EXPECT_EQ(tablero.getTablero()[3][3], Ficha::Rojo);
}

TEST(pruebaTablero, soltarFicha3){
    Tablero tablero(5,5);
    tablero.soltarFicha(1, Ficha::Azul);
    tablero.soltarFicha(1, Ficha::Rojo);
    tablero.soltarFicha(1, Ficha::Rojo);
    tablero.soltarFicha(1, Ficha::Rojo);
    tablero.soltarFicha(1, Ficha::Azul);
    EXPECT_EQ(tablero.getTablero()[0][1], Ficha::Azul);
}

TEST(pruebaTAblero, soltarFicha4){
    Tablero tablero(5,5);
    tablero.soltarFicha(4, Ficha::Azul);
    EXPECT_EQ(tablero.getTablero()[4][4], Ficha::Azul);    
}

//To Do: Terminar pruebas, puede tirar , comprobar empate y comprobar ganador





