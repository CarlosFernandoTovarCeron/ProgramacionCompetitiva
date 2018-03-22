#include <iostream>
#include <cstring>

using namespace std;

int habilidades[20], n, dp[1<<15];

int c(int b){
    int cont = 0;
    for(int i=0; i<n; i++){
        int mask = 1 << i;
        if(!(b&mask)){
            cont++;
        }
    }
    
    if(cont<3){
        return 0;
    }
    
    if(dp[b]!=-1) return dp[b];

    int maximo = -1;   
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                int equipo = habilidades[i] + habilidades[j] + habilidades[k];
                int maski = 1 << i;
                int maskj = 1 << j;
                int maskk = 1 << k;
                int cb = b;
                if(!(cb&maski) and !(cb&maskj) and !(cb&maskk)){
                    cb = cb|maski;
                    cb = cb|maskj;
                    cb = cb|maskk;
                    int bueno = equipo>=20 ? 1 : 0;
                    int nodo = c(cb);
                    dp[cb] = nodo;
                    maximo = max(maximo, bueno + nodo );
                }
            }
        }
    }
    dp[b] = maximo;
    return maximo;

    
}

int main() {
    int casos = 1;
    while(true){
        memset(dp, -1, sizeof(dp));
        cin >> n;
        if(n==0){
            break;
        }
        
        for(int i=0; i<n; i++){
            int aux; cin >> aux;
            habilidades[i] = aux;
        }
        
        cout << "Case " << casos << ": " << c(0) << endl;
        casos++;
    }
	return 0;
}
