#include <bits/stdc++.h>
using namespace std;
#define inf 100000000

struct ii{
    int f;
    int s;
 
    ii(int a, int b){
        f = a;
        s = b;
    }
 
    bool operator < (const ii& A){
        return f < A.f;
    }
 
    bool operator == (const ii& A){
        return f==A.f;
    }
};

vector <ii> a;
vector <ii> b;
int dp[1000000];
int ruta[1000000];

/*
int c(int j){
    int maximo = 0;
    for(auto k=lower_bound(a.begin() , a.end() , ii(b[j].f, 0)); k-a.begin()>= 0; k--){
        if(b[j].f>a[k-a.begin()].f and j>a[k-a.begin()].s){
            //cout << "entra" << endl;
            int nodo = c(a[k-a.begin()].s);
            maximo = max(nodo, maximo);
        }
    }
    
    return 1 + maximo;
    
}*/

void solve(int j){
    if(ruta[j]!=-1){
        solve(ruta[j]);
    }
    cout << b[j].f << endl;

}
 
int main(){

    int aux, i = 0;
    while(cin >> aux){
        ii paux(aux, i);
        a.push_back(paux);
        b.push_back(paux);
        i++;
    }
    sort(a.begin() , a.end());
    memset(ruta, -1, sizeof(ruta));
    for(int j=0; j<i; j++){
        int maximo = 0;
        for(auto k=lower_bound(a.begin() , a.end() , ii(b[j].f, 0)); k-a.begin()>= 0; k--){
            if(b[j].f>a[k-a.begin()].f and j>a[k-a.begin()].s){
                int nodo = dp[a[k-a.begin()].s];
                if(nodo >= maximo){
                    maximo = nodo;
                    ruta[j] = a[k-a.begin()].s;
                }
            }
        }
        
        dp[j] =  1 + maximo;
    }
    
    int maximo = -1, j;
    for(int k=i-1; k>=0; k--){
        if(dp[k]>maximo){
            maximo = dp[k];
            j = k;
        }
    }
    
    cout << dp[j] << endl;
    cout << "-" << endl;
    solve(j);
    
}
