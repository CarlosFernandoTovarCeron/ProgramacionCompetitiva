#include <iostream>
#include <vector>
#include <algorithm>    // std::min_element, std::max_element
#include <cstring>
#define mINF -100000000;

using namespace std;

int v[1002];
int p[1002];
int dp[1002][33];

int csm(int n, int budget){
    
    if(budget<0){
        return mINF;
    }
    
    if(n<0){
        return 0;
    }else{
        
        if(dp[n][budget]!=-1){
            return dp[n][budget];
        }
        
        if(p[n]>budget){
            return csm(n-1, budget);
        }else{
            int iz = csm(n-1, budget - p[n]) + v[n];
            int der = csm(n-1, budget);
            
            int res = max(iz, der);
            dp[n][budget] = res;
            return res;
            
        }
    }
}

int main() {
    
    int casos;
    cin >> casos;
    
    while(casos--){
        
        memset(v, -1, sizeof(v));
        memset(p, -1, sizeof(p));
        memset(dp, -1, sizeof(dp));
        
        int n;
        cin >> n;
        
        for(int i=0; i<n; i++){
            int peso; int valor;
            cin >> valor >> peso;
            v[i] = valor;
            p[i] = peso;
        }
        
        int personas;
        cin >> personas;
        
        vector <int> people;
        for(int i=0; i<personas; i++){
            int aux; cin >> aux;
            people.push_back(aux);
        }

        
        int total = 0;
        for(int i=0; i<people.size(); i++){
            total = total + csm(n-1, people[i]);
        }
                
        cout << total << endl;
        
        
    }
    
	return 0;
}

