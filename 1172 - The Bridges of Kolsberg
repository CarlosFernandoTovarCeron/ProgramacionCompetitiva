#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct nodo{
    long long tsum;
    int cpuentes;
    
    bool operator>(const nodo & r){
        if(tsum==r.tsum){
            return cpuentes < r.cpuentes;
        }
        
        return tsum > r.tsum;
    }
    
    nodo operator+(const nodo & r){
        nodo aux;
        aux.tsum = tsum + r.tsum;
        aux.cpuentes = cpuentes + r.cpuentes;
        return aux;
    }
        
};

long long tnorte[1005];
long long  tsur[1005];
int norte, sur;
nodo dp[1005][1005];
char nombresNorte[1005][20];
char nombresSur[1005][20];

int main() {
    int casos;
    scanf("%d", &casos);
    while(casos--){
        scanf("%d", &norte);
        for(int i=0; i<norte; i++){
            long long t;
            scanf("%*s %s %lld", &nombresNorte[i],  &t);
            tnorte[i] = t;
        }
        
        scanf("%d", &sur);
        for(int i=0; i<sur; i++){
            long long t;
            scanf("%*s %s %lld", &nombresSur[i],  &t);
            tsur[i] = t;
        }
        nodo res;
        res.tsum = 0;
        res.cpuentes = 0;
        for(int k=0; k<=max(norte, sur); k++){
            dp[norte][k] = res;
            dp[k][sur] = res;
        }
        
        for(int i=norte-1; i>=0; i--){
            for(int j=sur-1; j>=0; j--){
                nodo iz = dp[i+1][j];
                nodo der = dp[i][j+1];
                nodo maximo;
                if(iz>der){
                    maximo = iz;
                }else{
                    maximo = der;
                }
                if(!strcmp(nombresNorte[i], nombresSur[j])){
                    nodo aux;
                    aux.tsum = tnorte[i] + tsur[j];
                    aux.cpuentes = 1;
                    nodo p = dp[i+1][j+1];
                    dp[i+1][j+1] = p;
                    p = p + aux;
                    if(p>maximo){
                        maximo = p;
                    }
                    
                }
                dp[i][j] = maximo;
            }
        }
        
        nodo respuesta = dp[0][0];
        printf("%lld %d\n", respuesta.tsum, respuesta.cpuentes );

    }
	return 0;
}
