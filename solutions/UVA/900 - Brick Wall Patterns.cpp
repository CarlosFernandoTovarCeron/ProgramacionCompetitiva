#include <iostream>
#include <cstring>

using namespace std;

long long dp[55];

long long t(int n){
    if(n<0)
        return 0;
    
    if(n==0)
        return 1;
    
    if(dp[n]!=-1)
        return dp[n];
    
    long long  a = t(n-2);
    long long  b = t(n-1);
    dp[n] = a+b;
    return (a+b);
}

int main() {
    int n;
    memset(dp, -1, sizeof(dp));
    while(true){
        cin >> n;
        if(n==0)
            break;
        cout << t(n) << endl;
    }

	return 0;
}
