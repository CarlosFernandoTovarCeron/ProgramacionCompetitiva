#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;
#define inf 1000000000

int c[33][303][5];
int ms[100];
int t1, t2, n;
int dp[33][303];
int ruta[33][303];

vector <int> sol;
 
void solve(int sitio, int t){
	if(sitio!=n){
		sol.push_back(ruta[sitio][t]);
		solve(sitio+1, t + ruta[sitio][t]);
	}
}


int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	
    while(true){
        cin >> t1 >> t2;
        if(t1==0 and t2==0) break;
        cin >> n;
        for(int i=0; i<n; i++){
            int m;
            cin >> m;
            ms[i] = m;
            c[i][0][0] = 0;
            c[i][0][1] = 0;
            for(int j=1; j<=m; j++){
                int aux;
                cin >> aux;
                c[i][j][0] = aux;
            }
            for(int j=1; j<=m; j++){
                int aux;
                cin >> aux;
                c[i][j][1] = aux;
            }
        }
        
        
        for(int i=0; i<=(t1+t2)*2; i++){
        	dp[n][i] = inf;
		}
		
		dp[n][t1] = 0;

        for(int sitio = n-1; sitio>=0; sitio--){

            for(int t=0; t<=t1+t2; t++){
            	int minimo = inf;
	            for(int j=0; j<=ms[sitio]; j++){
	                int nodo = c[sitio][ms[sitio]-j][1] + c[sitio][j][0] + dp[sitio+1][t+j];   
	                if(nodo<minimo){
	                    minimo = nodo;
	                    ruta[sitio][t] = j;
	                }
	            }
	            dp[sitio][t] = minimo;
			}
        }
        
        cout << dp[0][0] << endl;
		solve(0, 0);
		for(int i=0; i<sol.size()-1; i++){
			cout << sol[i] << " ";
		}
		cout << sol[sol.size()-1];
		cout << endl << endl;
		sol.clear();

    }
    return 0;
}
