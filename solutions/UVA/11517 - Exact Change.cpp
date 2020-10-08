#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

#define INF 1000000000

int type[105];
int dp[10005][105];
char ruta[10005][105];
int minmon[10005][105];

int recorrer(int i, int j){
    if(j==0)
        return 0;
        
    if(i<0)
        return 0;
        
    if(minmon[i][j]!=-1)
        return minmon[i][j];
        
    int res;
    if(ruta[i][j]=='i')
        res =  1 + recorrer(i-type[j], j-1);
    else if(ruta[i][j]=='n')
        res = recorrer(i, j-1);
    else
        res = min(1 + recorrer(i-type[j], j-1),  recorrer(i, j-1));
        
    minmon[i][j] = res;
    return res;
}

int main() {
    int casos;
    cin >> casos;
    
    while(casos--){
        memset(type, -1, sizeof(type));
        memset(dp, INF, sizeof(dp));
        memset(ruta, 'X', sizeof(ruta));
        memset(minmon, -1, sizeof(minmon));

        int valor; cin >> valor;
        int tipos; cin >> tipos;
        for(int i=1; i<=tipos; i++){
            int aux; cin >> aux;
            type[i] = aux;
        }
        
        for(int i=0; i<=valor; i++){
            dp[i][0] = INF;
        }
        
        for(int i=1; i<=valor; i++){
            for(int j=1; j<=tipos; j++){
                int iz = dp[i][j-1];
                int der = (i-type[j])<=0 ? abs(i - type[j]) : dp[i-type[j]][j-1];
            
                if(iz<der){
                    ruta[i][j] = 'n';
                }else if(iz==der){
                    ruta[i][j] = '=';
                }else{
                    ruta[i][j] = 'i';
                }
                
                dp[i][j] = min(iz, der);
            }
        }
        
//        for(int i=0; i<=valor; i++){
//            for(int j=0; j<=tipos; j++){
//                cout << ruta[i][j] << " ";
//            }cout << endl;
//        }

        int necesarias = recorrer(valor, tipos);
        cout << valor + dp[valor][tipos] << " " << necesarias << endl;

    }
    
	return 0;
}
