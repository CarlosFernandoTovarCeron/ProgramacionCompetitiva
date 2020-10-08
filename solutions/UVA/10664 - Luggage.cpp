#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <string>

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
    string useless;
    getline(cin, useless);

    while(c--){
        memset(dp, -1, sizeof(dp));
        memset(v, -1, sizeof(v));
        int n = 0;
        string linea;
        getline(cin, linea);
        stringstream ss;
        ss << linea;
        int aux;
        while(ss >> aux){
            v[n] = aux; n++;
        }

        if(m(n-1, 0)==0){
        	cout << "YES" << endl;
        }else{
        	cout << "NO" << endl;
        }

    }

	return 0;
}
