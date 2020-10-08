#include <iostream>
#include <algorithm>
#include <cstring>
#define INF -100000000
using namespace std;

int VI[100001];
int VP[100001];

int I(int, int*);
int P(int, int*);

int I(int j, int * s){
    
    if(VI[j]!=-1)
        return VI[j];
    
    if(j<0){
        return 0;
    }else{
        if(s[j]%2==0){
            int iz = I(j-1, s)+s[j];
            int der = I(j-1, s);
            
            if(iz%2==0)
                iz = INF;
            if(der%2==0)
                der = INF;
                
            VI[j] = max(iz, der);
                
            return max(iz, der);
            
        }else{
            int iz = P(j-1, s)+s[j];
            int der = I(j-1, s);
            
            if(iz%2==0)
                iz = INF;
            if(der%2==0)
                der = INF;
            VI[j] = max(iz, der);
            return max(iz, der);
        }
    }
}

int P(int j, int * s){
    if(VP[j]!=-1)
        return VP[j];

    if(j<0){
        return 0;
    }else{
        if(s[j]%2==0){
            int iz = P(j-1, s)+s[j];
            int der = P(j-1, s);
            
            if(iz%2!=0)
                iz = INF;
            if(der%2!=0)
                der = INF;
            VP[j] = max(iz, der);
            return max(iz, der);
            
        }else{
            int iz = I(j-1, s)+s[j];
            int der = P(j-1, s);
            
                        
            if(iz%2!=0)
                iz = INF;
            if(der%2!=0)
                der = INF;
            VP[j] = max(iz, der);
            return max(iz, der);
        }
    }
    
}

int main() {
    memset(VI, -1, sizeof(VI));
    memset(VP, -1, sizeof(VI));
    
    int n;
    cin >> n;
    int s[n];
    for(int i=0; i<n; i++){
        int aux; cin >> aux;
        s[i] = aux;
    }
    
    cout << I(n-1, s) << endl;
    
	return 0;
}
