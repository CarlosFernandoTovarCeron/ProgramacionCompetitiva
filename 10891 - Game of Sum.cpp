#include <iostream>
#include <cstring>

using namespace std;

#define inf 1000000000

int a[105];
int s[105];
int dp[105][105][5];

int c(int i, int j, int t){
    if(i>j) return 0;
    
    if(dp[i][j][t] != -inf){
        return dp[i][j][t];
    }
    
    if(t==1){
        int maximo = -inf;
        //tomar der
        for(int k=i; k<=j; k++){
            int nodo = s[j] - s[k] + a[k] + c(i, k-1, 0);
            maximo = max(nodo, maximo);
        }
        
        for(int k=j; k>=i; k--){
            int nodo = s[k] - s[i] + a[i] + c(k+1, j, 0);
            maximo = max(nodo, maximo);
        }
        dp[i][j][t] = maximo;
        return maximo;
    }else{
        int minimo = inf;
        //tomar der
        for(int k=i; k<=j; k++){
            int nodo = (-1)*(s[j] - s[k] + a[k]) + c(i, k-1, 1);
            minimo = min(nodo, minimo);
        }
        
        for(int k=j; k>=i; k--){
            int nodo = (-1)*(s[k] - s[i] + a[i]) + c(k+1, j, 1);
            minimo = min(nodo, minimo);
        }
        dp[i][j][t] = minimo;
        return minimo;
    }
}

int main() {
    int n;
    while(true){
        cin >> n;
        if(n==0) break;
        
        for(int i=0; i<105; i++){
            for(int j=0; j<105; j++){
                dp[i][j][0] = -inf;
                dp[i][j][1] = -inf;
            }
        }

        int suma = 0;
        for(int i=0; i<n; i++){
           int aux;
           cin >> aux;
           suma+=aux;
           s[i] = suma;
           a[i] = aux;
        }
        
        cout << c(0, n-1, 1) << endl;
    }
	return 0;
}
