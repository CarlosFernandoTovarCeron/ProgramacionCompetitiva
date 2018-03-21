#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;
string n;
long d;

long c(long b, long j, long acu){

    if(j==-1){
        return acu%d==0;
    }
    
    long s = n.length();
    long total = 0;
    for(long i=0; i<s; i++){
        long mask = 1 << i;
        if(!(mask&b)){
            long cb = b;
            cb = cb|mask;
            total += c(cb, j-1, acu + (n[j]-'0')*pow(10, i));
        }
    }
    return total;
}

long fact(long n){
    long res = 1;
    for(long i=2; i<=n; i++){
        res*=i;
    }
    return res;
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    long casos;
    cin >> casos;
    while(casos--){

        cin >> n;
        cin >> d;
                
        long r[10];
        for(long i=0; i<10; i++){
            r[i] = 0;
        }
        
        for(long i=0; i<n.length(); i++){
            r[(n[i]-'0')]+=1;
        }
        long res = c(0, n.length()-1, 0);
        
        for(long i=0; i<10; i++){
            if(r[i]>1){
                res/=fact(r[i]);
            }
        }
        
        cout << res << endl;

    }
    return 0;
}
