#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdio.h>

using namespace std;
#define inf 100000000.0

double precios[105];
double dp[10005][105];
int n, x;

double c(int total, int j){
    if(j==0){
        if(total>5000){
            long double res = (long double) total;
            //cout << total << " " << res << endl;
            return res;
        }else{
            return inf;
        }
    }
    
    if(dp[total][j]!=-1.0){
        return dp[total][j];
    }
    
    if(j==x){
        return c(total, j-1);
    }
    
    long double maximo = min( c(total+precios[j], j-1)  , c(total, j-1)  );
    dp[total][j] = maximo;
    
    return maximo;
    
}

int main(int argc, char** argv) {
//    freopen("in", "r", stdin);
//    freopen("out", "w", stdout);

    while(true){
        cin >> n >> x;
        if(n==0 and x==0) break;
        
        for(int i=0; i<10005; i++){
            for(int j=0; j<105; j++){
                dp[i][j] = -1.0;
            }
        }

        for(int i=1; i<=n;i++){
            long double aux;
            cin >> aux;
            aux = aux * 100;
            precios[i] = aux;
        }
        long double cres = c(precios[x], n)*100.0;
        printf("%.2Lf\n", (precios[x]/cres)*10000);

    }
    

    return 0;
}
