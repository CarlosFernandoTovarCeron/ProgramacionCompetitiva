#include <iostream>
#include <cstring>

#define INF 100000000
using namespace std;

int w[15][1005];
int dp[15][1005];

int x;

int c(int al, int r){
    
    if(al>9 or al<0) return INF;
    
    if(r==(x/100)){
        if(al!=9)
            return INF;
        else
            return 0;
    }
    
    if(dp[al][r]!=-1){
        return dp[al][r];
    }
    
    int p = w[al][r];
    int subir = 60 + c(al-1, r+1) + p;
    int mantener = 30 + c(al, r+1) + p;
    int bajar = 20 + c(al+1, r+1) + p;
    dp[al][r] = min(subir, min(mantener, bajar));
    return dp[al][r];
}

int main() {
    int ca;
    cin >> ca;
    while(ca--){
        memset(dp, -1, sizeof(dp));
        cin >> x;
        for(int i=0; i<=9; i++){
            for(int j=0; j<x/100; j++){
                int aux;
                cin >> aux;
                w[i][j]  = -aux;
            }
        }
        
        cout << c(9, 0) << endl << endl;
    }
	return 0;
}
