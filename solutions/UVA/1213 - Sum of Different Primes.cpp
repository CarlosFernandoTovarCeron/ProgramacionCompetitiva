#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector <int> vi;

vi primos;

int dp[1121][15][1121];

void generarPrimos(){
    for(int i=2; i<=1120; i++){
        int div = 0;
        for(int j=1; j<=i; j++){
            if(i%j==0){
                div++;
            }
        }
        if(div==2){
            primos.push_back(i);
        }
    }
}

int costo(int n, int k, int i){

    if(n<0)
        return 0;
        
    if(n==0 and k==0)
        return 1;
        
    if(i<0 or k<0)
        return 0;
        
    if(dp[n][k][i]!=-1)
        return dp[n][k][i];
        
    int iz = costo(n-primos[i], k-1, i-1);
    int der = costo(n, k, i-1);
    dp[n][k][i] = iz + der;
    return (iz + der);
    
}

int main() {
    generarPrimos();
    memset(dp, -1, sizeof(dp));
    int n, k;
    while(true){
        cin >> n >> k;
        if(n==0 and k==0)
            break;
            
        cout << costo(n, k, primos.size()-1) << endl;
    }
	return 0;
}
