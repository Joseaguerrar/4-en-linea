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
        cout<<"Columna fuera de rango"<<endl;
        return false;
    }
    //Caso en que la columna este llena
    if(tablero[/*filas o 0 (aun no se sabe como se imprimen con vector)*/][columnas] != '_'){
        cout<<"Columna llena"<<endl;
        return false;
    }
    return true;
}