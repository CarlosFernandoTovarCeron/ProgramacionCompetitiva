#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int v[101];
int dp[101][50001];

int m(int n, int d){
    if(n<0){
        return d;
    }else{
        if(dp[n][d]!=-1)
            return dp[n][d];

        int iz = m(n-1, d+v[n]);
        int der = m(n-1, abs(d-v[n]));
        int res = min(iz, der);
        dp[n][d] = res;
        return res;
    }
}

int main() {

    int c;
    cin >> c;

    while(c--){
        memset(dp, -1, sizeof(dp));
        memset(v, -1, sizeof(v));

        int n;
        cin >> n;

        for(int i=0; i<n; i++){
            int aux; cin >> aux;
            v[i] = aux;
        }
        cout << m(n-1, 0) << endl;

    }

	return 0;
}
