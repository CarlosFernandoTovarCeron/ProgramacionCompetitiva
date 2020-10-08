#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

long long dp[2100000];
int gs[25];
int n, d;

long long funcion(int estado){
    if(estado == (1 << n) - 1) return 1;
    
    if(dp[estado]!=-1) return dp[estado];
    int ceros[25];
    int cantidadceros = 0;
    for(int i=0; i<n; i++){
        int mask = 1 << i;
        if(!(mask&estado)){
            ceros[cantidadceros] = i;
            cantidadceros++;
        }else{
            ceros[cantidadceros] = 0;
        }
    }
    
    long long total = 0;
    int i = 0;
    for(int j=i+1; j<cantidadceros; j++){
        for(int k=j+1; k<cantidadceros; k++){
           
            if(max(gs[ceros[i]], max(gs[ceros[j]], gs[ceros[k]])) - 
                min(gs[ceros[i]], min(gs[ceros[j]], gs[ceros[k]])) <= d
            ){
                int mask1 = 1 << ceros[i];
                int mask2 = 1 << ceros[j];
                int mask3 = 1 << ceros[k];
                int tripla = 0;
                tripla = tripla | mask1 | mask2 | mask3;
                long long sumar = funcion(estado|tripla);  
                total+=sumar;
            }
        }
    }
    
    dp[estado] = total;
    return total;
}
int main() {

    while(scanf("%d %d", &n, &d), n){
        for(int i=0; i<n; i++){
            int aux;
            scanf("%d", &aux);
            gs[i] = aux;
        }
        memset(dp, -1, sizeof(dp));
        long long res = funcion(0);
        printf("%lld\n", res);
    }
	return 0;
}
