/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: invitado
 *
 * Created on 21 de marzo de 2018, 10:21 AM
 */

#include <iostream>
#define inf 10000000;
using namespace std;

int suma[1005];
int l, c, n;
int costo(int j, int dis){
    if(j==n+1){
        return 0;
    }
    int minimo = inf;
    int dismin = inf;
    for(int k=j; k<=n; k++){
        int lecturas = suma[k] - suma[j-1];
        if(lecturas>l) break;
        int tlibre = l-lecturas;
        int disaux;
        if(tlibre==0){
            disaux = 0;
        }else if(tlibre>=1 and tlibre<=10){
            disaux = -c;
        }else{
            disaux = (tlibre-10)*(tlibre-10);
        }
        int nodo = 1+costo(k+1, dis+disaux);
        if(nodo < minimo){
            minimo = nodo;
            dismin = dis+disaux;
        }else if(nodo == minimo){
            if(dis+disaux<dismin){
                minimo = nodo;
                dismin = dis+disaux;
            }
        }
    }
    
    return minimo;
}

int main(int argc, char** argv) {
    
    while(true){
        cin >> n;
        if(n==0){
            break;
        }
       
        cin >> l >> c;
        int s = 0;
        suma[0] = 0;
        for(int i=1; i<=n; i++){
            int aux;
            cin >> aux;
            s+=aux;
            suma[i] = s;
        }
        
        
        
        cout << costo(1, 0) << endl;
        
    }

    return 0;
}

