#include<iostream>
#include<string>
#include<vector>
#include<tablero.hh>
using namespace std;

//
Tablero::Tablero(int filas, int columnas): tablero(filas,vector<char>(columnas, '_')), filas(filas), columnas(columnas) {}


//Metodo que verifica si el jugador puede soltar una ficha en una columna seleccionada
bool Tablero::puedeTirar(int columna){
    //Caso en que la columna este fuera de rango
    if(columna < 0 && columna > getColumnas()){
        cout<<"Columna fuera de rango"<<endl; //Hacer los throw
        return false;
    }
    //Caso en que la columna este llena
    if(tablero[0][columnas] != '_'){
        cout<<"Columna llena"<<endl; // hAcer los throw
        return false;
    }
    return true;
}

//Metodo que retorna una copia del tablero actual
vector<vector<char>> Tablero::getCopiaTablero(){
    vector<vector<char>> copiaTablero = tablero;
    return copiaTablero;
}

//Metodo que suelta la ficha en la columna indicada que escogio el usuario
bool Tablero::soltarFicha(int columna, char ficha){
    int filasTemp = filas - 1;
    while(tablero[filas][columna] == '_'){
        filasTemp--;
    }
    tablero[filasTemp][columna] == ficha;
    return true;
}

//TO DO: Realizar los metodos verificar ganador, soltar ficha,