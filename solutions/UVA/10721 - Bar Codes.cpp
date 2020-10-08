#include <iostream>
#include <cstring>
#include <memory.h>

using namespace std;

int n, k, m;
long long dp[55][55];

long long  c(int n, int k){
    
    if(n==0LL and k==0LL) return 1LL;
    if(n==0LL) return 0LL; if(k==0LL) return 0LL;
    
    if(dp[n][k]!=-1LL) return dp[n][k];
    
    long long suma = 0LL;
    for(int i=1; i<=m; i++){
        if(n-i<0) break;
        suma+=c(n-i, k-1);
    }
    
    dp[n][k] = suma;
    
    return suma;
}

int main() {
    while(cin >> n >> k >> m){
        memset(dp, -1LL, sizeof(dp));
        cout << c(n, k) << endl;
    }
	return 0;
}
