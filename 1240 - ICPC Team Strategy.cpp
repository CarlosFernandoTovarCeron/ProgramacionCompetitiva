#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

#define inf 10000000

using namespace std;

int tiempo[4][20];
int dp[10000][4][600];

int problemas;

int c(int b, int j, int t){
    if(t>280) return -inf;
    
    if(dp[b][j][t]!=-1){
        return dp[b][j][t];
    }
    
    int tiemporestante = 280 - t;
    bool existe = false;
    for(int i=1; i<=problemas; i++){
        int mask = 1 << i;
        if(!(mask&b)){
            for(int k=1; k<=3; k++){
                if(j!=k){
                    if(tiempo[k][i]<=tiemporestante){
                        existe = true;
                    }
                }
            }
        }
    }
    
    if(!existe){
        return 0;
    }
    
    int maximo = -1;
    for(int i=1; i<=problemas; i++){
        int mask = 1 << i;
        if(!(mask&b)){
            for(int k=1; k<=3; k++){
                if(j!=k){
                    int cb = b|mask;
                    int nodo = 1 + c(cb, k, t + tiempo[k][i]);
                    dp[cb][k][t+tiempo[k][i]] = nodo - 1;
                    maximo = max(nodo, maximo);
                }
            }
        }
    }
    dp[b][j][t] = maximo;
    return maximo;
    
}

int main() {
    int casos;
    cin >> casos;
    while(casos--){
        memset(dp, -1, sizeof(dp));
        cin >> problemas;
        string linea;
        getline(cin, linea); // nada
        for(int i=1; i<=3; i++){
            getline(cin, linea);
            stringstream ss;
            ss << linea;
            for(int j=1; j<=problemas; j++){
                int aux;
                ss >> aux;
                tiempo[i][j] = aux;
            }
        }
        
        cout << c(0, 0, 0) << endl;
        
        
    }
	return 0;
}
