//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

//#include <stdio.h>
#include <iostream>


#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/
int minasAdyacentes(tablero& t, pos p) {
    int i, k;
    int minas = 0;
    for(i=-1; i<= 1; i++){
        for(k=-1; k<= 1; k++){
            if(!(i==0 && k==0) && posValida(t, make_pair(p.first + i, p.second + k)) && t[p.first + i][p.second + k]) {
                minas++;
            }
        }
    }
    return minas;
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/
void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    bool estaPos = false;
    int i = 0;
    while (i < b.size() && !estaPos) {
        if (b[i] == p) {
            b[i] = b[b.size()-1];
            b[b.size()-1] = p;
            estaPos = true;
        }
        i++;
    }
    if(estaPos){
        b.pop_back();
    } else
    {
        b.push_back(p);
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    bool hayMinaEnJugada = false;
    int i = 0;
    while (i < j.size() && !t[(j[i].first).first][(j[i].first).second]) {
        i++;
    }
    return i < j.size();
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j) {
    return !perdio(t, j) && minasTablero(t) + j.size() == t.size()*t.size();
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    tablero posDisponibles;
    int i; int k;

    for (i = 0; i < t.size(); i++) {
        vector<bool> fila (t.size(),true);
        for (k = 0; k < t.size(); k++) {
            fila[k] = !t[i][k];
        }
        posDisponibles.push_back(fila);
    }

    for (i = 0; i < b.size(); i++) {
        posDisponibles[b[i].first][b[i].second] = false;
    }

    for (i = 0; i < j.size(); i++) {
        posDisponibles[(j[i].first).first][(j[i].first).second] = false;
    }

    jugadas jAgregadas, jAgregadasNuevas;
    agregarPosAJugadas(j, jAgregadas, t, posDisponibles, p);
    if(!t[p.first][p.second]) {
        while (jAgregadas.size() > 0) {
            for (i = 0; i < jAgregadas.size(); i++) {
                if(jAgregadas[i].second == 0) {
                    agregarPosDescubribles(j, jAgregadasNuevas, t, posDisponibles, jAgregadas[i]);
                }
            }
            jAgregadas = jAgregadasNuevas;
            jAgregadasNuevas.clear();
        }
    }
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    return false;
}
