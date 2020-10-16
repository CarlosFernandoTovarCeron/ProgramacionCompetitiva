#include <iostream>
#include <cstring>

using namespace std;

long long n, m;
long long sum[1005];
long long a[1005];
long long dp[1005][1005];

long long f(long long n, long long k){

    if(n==0) {
        return 0;
    }

    if(k==1 && n>=1) {
        return sum[n];
    }
    
    if(dp[n][k] != -1) {
        return dp[n][k];
    }

    long long one = f(n-1, k-1) % m;
    long long two = f(n-1, k) % m;
    long long res = (a[n] * one + two) % m;

    dp[n][k] = res;

    return res;
}


int main() {
    while(true) {
        memset(dp, -1, sizeof(dp));
        cin >> n >> m;
        if(n==0 && m==0) {
            break;
        }
        long long acu = 0;
        for(long long i=1; i<=n; i++) {
            long long aux;
            cin >> aux;
            a[i] = aux;
            acu+=aux;
            sum[i] = acu % m;
        }

        long long maximum = 0;
        for(long long k=1; k<=n; k++) {
            maximum = max(maximum, f(n, k));
        }

        cout << maximum << endl;
    }
    return 0;
}
