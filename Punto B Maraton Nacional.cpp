#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[2100000];
long long total, sumar;
int ceros[25];
int gs[25];
int n, d, mask, mask1, mask2, mask3, tripla, i, j, k, aux, cantidadceros;
int main() {

    while(scanf("%d %d", &n, &d), n){
        for(i=0; i<n; i++){
            scanf("%d", &aux);
            gs[i] = aux;
        }
        //memset(dp, 0, sizeof(dp));
        dp[(int) (1 << n)-1] = 1;
        int contador = 0;
        for(int estado=(1 << n)-2; estado>=0; estado--){

            if(__builtin_popcount(estado)%3!=0){
                continue;
            }
            
            cantidadceros = 0;
            for(i=0; i<n; i++){
                mask = 1 << i;
                if(!(mask&estado)){
                    ceros[cantidadceros] = i;
                    cantidadceros++;
                }else{
                    ceros[cantidadceros] = 0;
                }
            }
                        
            total = 0;
            i = 0;
            for(j=i+1; j<cantidadceros; j++){
                for(k=j+1; k<cantidadceros; k++){
                    if(max(gs[ceros[i]], max(gs[ceros[j]], gs[ceros[k]])) - 
                        min(gs[ceros[i]], min(gs[ceros[j]], gs[ceros[k]])) <= d
                    ){

                        mask1 = 1 << ceros[i];
                        mask2 = 1 << ceros[j];
                        mask3 = 1 << ceros[k];
                        tripla = 0;
                        tripla = tripla | mask1 | mask2 | mask3;
                        sumar = dp[estado|tripla];  
                        total+=sumar;
                    }
                }
            }
            
            dp[estado] = total;
        }
        printf("%lld\n",  dp[0]);
    }
	return 0;
}
