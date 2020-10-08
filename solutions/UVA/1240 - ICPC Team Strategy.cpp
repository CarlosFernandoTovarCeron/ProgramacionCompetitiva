#include <stdio.h>
#include <cstring>
#include <algorithm>

#define inf 10000000

using namespace std;

int tiempo[4][20];
int dp[10000][4][600];
int problemas, casos, aux;

int c(int b, int j, int t){
    if(t>280) return -inf;
    
    if(dp[b][j][t]!=-1){
        return dp[b][j][t];
    }
    
    bool existe = false;
    for(int i=1; i<=problemas; i++){
        int mask = 1 << i;
        if(!(mask&b)){
            for(int k=1; k<=3; k++){
                if(j!=k){
                    if(tiempo[k][i]<=280 - t){
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

    scanf("%d", &casos);
    while(casos--){
        memset(dp, -1, sizeof(dp));
        scanf("%d", &problemas);
        for(int i=1; i<=3; i++){
            for(int j=1; j<=problemas; j++){
                scanf("%d", &aux);
                tiempo[i][j] = aux;
            }
        }
        
        printf("%d\n", c(0, 0, 0));

    }
	return 0;
}
