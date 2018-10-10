#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

unsigned int countSetBits(int n)
{
    unsigned int count = 0;
    while (n)
    {
      n &= (n-1) ;
      count++;
    }
    return count;
}

int gs[25];
long long dp[2100000];
long long factorial[10];
int n, d;
int main() {
    int res=1, cont=1;
    while(cont!=10){
        res=res*cont;
        factorial[cont] = res;
        cont++;
    }
    
    int n, d;
    while(cin >> n >> d){
        if(n == 0 and d == 0) break;
        
        for(int i=0; i<n; i++){
            int aux;
            cin >> aux;
            gs[i] = aux;
        }
        memset(dp, 0, sizeof(dp));
        dp[(int) pow(2, n)-1] = 1;
        for(int estado=pow(2, n)-2; estado>=0; estado--){

            if(countSetBits(estado)%3!=0) continue;

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
            for(int i=0; i<cantidadceros; i++){
                for(int j=i+1; j<cantidadceros; j++){
                    for(int k=j+1; k<cantidadceros; k++){
                        if(max(gs[ceros[i]], max(gs[ceros[j]], gs[ceros[k]])) - 
                            min(gs[ceros[i]], min(gs[ceros[j]], gs[ceros[k]])) <= d
                        ){
    
                            int mask1 = 1 << ceros[i];
                            int mask2 = 1 << ceros[j];
                            int mask3 = 1 << ceros[k];
                            int tripla = 0;
                            tripla |= mask1;
                            tripla |= mask2;
                            tripla |= mask3;
                            
                            long long sumar = dp[estado|tripla];  
                            total+=sumar;
                        }
                    }
                }
            }
            
            dp[estado] = total;
        }
        
        cout << dp[0]/factorial[n/3] << endl;
        
    }
	return 0;
}
