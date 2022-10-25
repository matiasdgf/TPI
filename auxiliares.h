
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

template<typename T> int apariciones(T x, vector<T> v){
    int cant = 0;
    for(int i=0;i<v.size();i++){
        if(v[i]==x) {
            cant++;
        }
    }
    return cant;
}

template<typename T> bool esPermutacion(vector<T> v1, vector<T> v2){
    bool permutacion = false;
    if (v1.size() == v2.size()) {
        int i = 0;
        permutacion = true;
        while (i < v1.size() && permutacion) {
            permutacion = apariciones(v1[i],v2) == 1;
            i++;
        }
    }
    return permutacion;
}

bool posValida(tablero& t, pos p);
int minasTablero(tablero& t);
void agregarPosAJugadas(jugadas& j, jugadas& jAgregadas, tablero& t, tablero& posDisponibles, pos p);
void agregarPosDescubribles(jugadas& j, jugadas& jAgregadas, tablero& t, tablero& posDisponibles, jugada jNueva);