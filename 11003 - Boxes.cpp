#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

#define INF -100000000

int pesos[1005];
int cargas[1005];

int dp[30005][1005];

int c(int l, int i){

    if(i==-1) return 0;
    if(l==0) return 0;

    if(dp[l][i]!=-1) return dp[l][i];

    int li = cargas[i];

    int iz;
    if(l-pesos[i]>=0){
        iz =  c(min(li, l-pesos[i]), i-1) + 1;
    }else{
        iz = INF;
    }
    int der = c(l, i-1);

    dp[l][i] = max(iz, der);

    return max(iz, der);
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

    int n;
    while(true){
        memset(cargas, -1, sizeof(cargas));
        memset(pesos, -1, sizeof(pesos));
        memset(dp, -1, sizeof(dp));

        cin >> n;
        if(n==0) break;
        for(int i=0; i<n; i++){
            int w, l;
            cin >> w >> l;
            pesos[i] = w;
            cargas[i] = l;
        }
        reverse(cargas, cargas+n);
        reverse(pesos, pesos+n);
        cout << c(30000, n-1) << endl;

    }
    

    /* 
    6
    1376 935
    1799 191
    1192 1195
    2554 2031
    1997 2497
    1651 2452
    0
     */

	return 0;
}
