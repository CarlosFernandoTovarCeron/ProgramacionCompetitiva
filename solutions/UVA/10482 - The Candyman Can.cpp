#include <iostream>
#include <cstring>

using namespace std;

int w[50];
int dp[650][650][40];
int suma;

int f(int a, int b, int j){
    if(j==0){
        int c = suma - a - b;
        return max(a, max(b, c)) - min(a, min(b, c));
    }
    
    if(dp[a][b][j]!=-1) return dp[a][b][j];
    
    int dara = f(a + w[j], b, j-1);
    int darb = f(a, b+w[j], j-1);
    int darc = f(a, b, j-1);
    
    dp[a + w[j]][b][j-1] = dara;
    dp[a][b+w[j]][j-1] = darb;
    dp[a][b][j-1] = darc;
    
    dp[a][b][j] = min(dara, min(darb, darc));
    
    return min(dara, min(darb, darc));
    
}

int main() {
    int casos;
    cin >> casos;
    
    for(int c=1; c<=casos; c++){
        int n;
        cin >> n;
        memset(dp,-1, sizeof(dp));
        suma = 0;
        for(int i=1; i<=n; i++){
            int aux;
            cin >> aux;
            suma+=aux;
            w[i] = aux;
        }
        
        cout << "Case " << c << ": " << f(0, 0, n) << endl;
    }
	return 0;
}
