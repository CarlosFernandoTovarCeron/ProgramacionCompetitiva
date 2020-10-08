#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

int p[45];

ll contarsol[3][45];
ll dp[45][33000];
int n, m;

ll c(int j, ll suma){
    if(j==0){
        if(suma==m+16000){
            return 1;
        }else{
            return 0;
        }
    }else{
        
        if(dp[j][suma]!=-1){
            return dp[j][suma];
        }
        
        ll r = c(j-1, suma-p[j]);
        ll s = c(j-1, suma+p[j]);
        contarsol[0][j] += r;
        contarsol[1][j] += s;
        dp[j][suma] = r + s;
        return r + s;
    }
}

int main() {
    while(cin >>n >> m){
        memset(contarsol, 0, sizeof(contarsol));
        memset(dp, -1, sizeof(dp));

        if(n==0 and m==0) break;
        
        for(int i=1; i<=n; i++){
            int aux;
            cin >> aux;
            p[i] = aux;
        }
        ll res = c(n, 0 + 16000);
        if(res!=0){
            for(int j=1; j<=n; j++){
                if(contarsol[0][j]!=0 and contarsol[1][j]!=0){
                    cout << "?";
                }else if(contarsol[0][j]==0 and contarsol[1][j]!=0){
                    cout << "+";
                }else if(contarsol[1][j]==0 and contarsol[0][j]!=0){
                    cout << "-";
                }
            }
            cout << endl;
        }else{
            cout << "*" << endl;
        }
    }
	return 0;
}
