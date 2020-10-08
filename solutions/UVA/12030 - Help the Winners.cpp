#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

int m[20][20];
ll dp[1<<16][16][2][2];
int n;
ll c(int b, int j, int s, int p){
    if(j==0){
        if(p==0 or s==1) return 1; else return 0;
    }
    if(dp[b][j][s][p]!=-1) return dp[b][j][s][p];
    
    ll total = 0;
    for(int i=1; i<=n; i++){
        if(m[j][i] == 1){
            int mask = 1 << i;
            if(!(b&mask)){
                int cb = b;
                cb = cb|mask;
                ll nodo = c(cb, j-1, s, p);
                total += nodo;
                dp[cb][j-1][s][p] = nodo;
            }
        }else if(m[j][i]==2){
            int mask = 1 << i;
            if(!(b&mask)){
                int cb = b;
                cb = cb|mask;
                ll nodo = c(cb, j-1, 1, p);
                total += nodo;
                dp[cb][j-1][1][p] = nodo;

            }
        }else{
            int mask = 1 << i;
            if(!(b&mask)){
                int cb = b;
                cb = cb|mask;
                ll nodo = c(cb, j-1, s, 1);
                total += nodo;
                dp[cb][j-1][s][1] = nodo;
            
            }

        }
    }
    //total+= c(b, j-1, s, 1);

    dp[b][j][s][p] = total;
    return total;
    
}

int main() {
    int casos;
    cin >> casos;
    int caso = 1;
    while(casos--){
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int aux;
                cin >> aux;
                m[i][j] = aux;
            }
        }
        
        cout << "Case " << caso << ": " << c(0, n, 0, 0) << endl;
        caso++;
    }
	return 0;
}
