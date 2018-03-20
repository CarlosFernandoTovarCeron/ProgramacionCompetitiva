#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

bool isOn(int a, int i){
    int mask = 1 << i;
    return mask&a;
}

typedef long long ll;

int n, g;
ll dp[8388608][23][2];

ll c(int b, int a, bool m){

    bool f = true;
    for(int i = 1; i<=n;i++){
        if((!isOn(b, i))){
            f = false;
            break;
        }
    }
    
    if(f) return 1;
    
    ll total = 0;

    bool y = true;
    for(int i = 1; i<=n;i++){
        if(!isOn(b, i) and ((m==1 and i>a) or (m==0 and i<a))){
            y = false;
            break;
        }
    }
    
    if(y){
        return 0;
    }
    
     if(dp[b][a][(int)m]!=-1){
        return dp[b][a][(int)m];
    }
    
    for(int i = 1; i<=n;i++){
       
        if(!isOn(b, i)  and ((m==1 and i>a) or (m==0 and i<a))){
            int cb = b;
            int mask = 1 << i;
            cb = cb | mask;
            total += c(cb, i, !m);
        }
    }
    dp[b][a][(int)m] = total;
    return total;
}

int main(){
    memset(dp, -1, sizeof(dp));
    while(cin >> n >> g){
        if(g==1){
            cout << 1 << endl;
        }else{
            int a = 1 << g;
            int mask = 1 << 0;
            a = a | mask;
            cout << c(a, g, 0) << endl;
        }
    }

}
