//
// Este archivo contiene las definiciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con las 
// declaraciones de auxiliares.h
//

#include <iostream>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"
#include "auxiliares.h"

using namespace std;

bool posValida(tablero& t, pos p){
    return 0 <= p.first && p.first < t.size() && 0 <= p.second && p.second < t.size();
}

int minasTablero(tablero& t){
    int minas = 0;
    for(int i=0; i<t.size(); i++){
        for(int k=0; k<t.size(); k++){
            if(t[i][k]) {
                minas++;
            }
        }
    }
    return minas;
}

void agregarPosAJugadas(jugadas& j, jugadas& jAgregadas, tablero& t, tablero& posDisponibles, pos p) {
    jugada jugada1 = make_pair(p, minasAdyacentes(t, p));
    j.push_back(jugada1);
    jAgregadas.push_back(jugada1);
    posDisponibles[p.first][p.second] = false;
}

void agregarPosDescubribles(jugadas& j, jugadas& jAgregadas, tablero& t, tablero& posDisponibles, jugada jNueva) {
    int i, k;
    pos p = jNueva.first;
    int minas = jNueva.second;
    if (minas == 0) {
        for(i=-1; i<= 1; i++){
            for(k=-1; k<= 1; k++){
                if(!(i==0 && k==0) && posValida(t, make_pair(p.first +i, p.second+k)) && posDisponibles[p.first +i][p.second+k]) {
                    agregarPosAJugadas(j, jAgregadas, t, posDisponibles, make_pair(p.first +i, p.second+k));
                }
            }
        }
    }
}