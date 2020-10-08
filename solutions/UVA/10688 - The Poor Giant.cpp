#include <iostream>
#include <cstring>

using namespace std;

#define inf 100000000;

int n, k;

int dp[505][505];

int c(int a, int b){
    if(a>b) return 0;
    if(b-a==0) return 0;
    
    if(dp[a][b]!=-1) return dp[a][b];
    
    int minimo = inf;
    for(int i=a; i<=b; i++){
        int bitter = c(i+1, b);
        int sour = c(a, i-1);
        dp[i+1][b] = bitter;
        dp[a][i-1] = sour;
        int suma = bitter + sour + (b-a+1)*(i+k);
        if(minimo>suma){
            minimo = suma;
        }
    }
    dp[a][b] = minimo;
    return minimo;
}

int main() {
    int casos;
    cin >> casos;
    
    for(int i=1; i<=casos; i++){
        memset(dp, -1, sizeof(dp));
        cin >> n >> k;
        cout << "Case " << i << ": " << c(1, n) << endl;
    }
	return 0;
}
