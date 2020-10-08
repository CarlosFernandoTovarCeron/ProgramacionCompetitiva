#include <iostream>
#include <cstring>
using namespace std;
#define MOD 1000000

int dp[101][101];

int costo(int n, int k){
    if(n<0 or k<0)
        return 0;
    
    if(n==0 and k==0)
        return 1;
        
    if(dp[n][k]!=-1) return dp[n][k];
    
    int suma = 0;
    for(int i=0; i<=n; i++){
        int p = costo(n-i, k-1);
        suma += p % MOD;
    }
    
    dp[n][k] = suma % MOD;
    
    return suma % MOD;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int n, k;
    while(true){
        cin >> n >> k;
        if(n==0 and k==0) break;
        
        cout << costo(n, k) << endl;
    }

	return 0;
}
