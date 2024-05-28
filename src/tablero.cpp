#include<iostream>
#include<string>
#include<vector>
#include<tablero.hh>
#include<memory>

using namespace std;

//
Tablero::Tablero(int filas, int columnas): tablero(filas,vector<char>(columnas, '_')), filas(filas), columnas(columnas) {}


//Metodo que verifica si el jugador puede soltar una ficha en una columna seleccionada
bool Tablero::puedeTirar(int columna){
    //Caso en que la columna este fuera de rango
    if(columna < 0 && columna > getColumnas()){
        //Hacer los throw
        cout<<"Columna fuera de rango"<<endl; 
        return false;
    }
    //Caso en que la columna este llena
    if(tablero[0][columnas] != '_'){
        // hacer los throw
        cout<<"Columna llena"<<endl; 
        return false;
    }
    return true;
}

//Metodo que retorna una copia del tablero actual
Tablero Tablero::getCopiaTablero(){
    Tablero copiaTablero(filas, columnas);
    copiaTablero.setTablero(tablero);
    return copiaTablero;
}

void Tablero::setTablero(vector<vector<char>> tableroActual){
    tablero = tableroActual;
}
//Metodo que suelta la ficha en la columna indicada que escogio el usuario
bool Tablero::soltarFicha(int columna, char ficha){
    int filasTemp = filas - 1;
    while(tablero[filasTemp][columna] != '_' && filasTemp  >= 0){
        filasTemp--;
    }
    tablero[filasTemp][columna] = ficha;
    return true;
}

//TO DO: Realizar los metodos verificar ganador, soltar ficha,