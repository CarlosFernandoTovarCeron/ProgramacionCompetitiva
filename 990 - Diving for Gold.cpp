#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <cstdio>
using namespace std;
#define INF -1000000000
typedef pair<int, int> ii;

int tiempo[1001];
int dep[31];
int gold[31];
vector <ii> sol;

int w;
int dp[1001][31];
char ruta[1001][31];

void fsol(int ti, int i){
    if(ti>=0 and i>=0){
        if(ruta[ti][i]=='n'){
        	fsol(ti, i-1);
        }else{
        	fsol(ti - 3*w*dep[i], i-1);
            sol.push_back(make_pair(dep[i], gold[i]));
        }
    }
}

int main() {
//	freopen("in.txt" ,"r", stdin);
//	freopen("out.txt", "w", stdout);

    int t;
    int veces = 0;
    while(cin >> t >> w){
    	if(veces!=0){
            cout << endl;
    	}veces++;
        memset(dp, 0, sizeof(dp));
        memset(ruta, 'n', sizeof(ruta));
        sol.clear();
        int c; cin >> c;
        for(int i=1; i<=c; i++){
            int d, g; cin >> d >> g;
            gold[i] = g;
            dep[i] = d;
        }

        for(int ti = 1; ti<=t; ti++){
            for(int i=1; i<=c; i++){

                int iz = dp[ti][i-1];
                int der = (ti - 3*w*dep[i])<0 ? INF : dp[ti - 3*w*dep[i]][i-1] + gold[i];
                ruta[ti][i] = iz>=der ? 'n' : 'i';
                dp[ti][i] = max(iz, der);
            }
        }

        fsol(t, c);
        cout << dp[t][c] << endl;
        cout << sol.size() << endl;
        for(int i=0; i<(int)sol.size(); i++){
            cout << sol[i].first << " " << sol[i].second << endl;
        }
    }

	return 0;
}
