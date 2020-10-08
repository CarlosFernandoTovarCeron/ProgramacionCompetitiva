
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

int matrix[105][105];
int dp[105][105][105][105];

int main(int argc, char** argv) {
    
    
    int n, m;
    while(true){
        cin >> n;
        if(n==0) break;
        cin >> m;
        
        memset(dp, 0, sizeof(dp));
        
        for(int i=1; i<=n; i++){
            string linea;
            cin >> linea;
            linea = "*" + linea;
            for(int j=1; j<=m; j++){
                if(linea[j]=='0'){
                    matrix[i][j] = 0;
                }else{
                    matrix[i][j] = 1;
                }
            }
        }
                
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                for(int k=i; k<=n; k++){
                    for(int l=j; l<=m; l++){
                        if(i==k and j==l){
                            dp[i][j][k][l] = matrix[i][j];
                            continue;
                        }
                        
                        if(j==l){
                            dp[i][j][k][l] = dp[i][j][k-1][l] + matrix[k][l];
                            continue;
                        }
                        
                        if(i==k){
                            dp[i][j][k][l] = dp[i][j][k][l-1] + matrix[k][l];
                            continue;
                        }
                        
                        dp[i][j][k][l] = dp[i][j][k][l-1] + (dp[i][j][k-1][l] - dp[i][j][k-1][l-1]) + matrix[k][l];
                        
                    }
                }
            }
        }
        
        int contador = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                for(int k=i; k<=n; k++){
                    for(int l=j; l<=m; l++){
                        bool todos = abs(k-i+1)*abs(l-j+1) == dp[i][j][k][l];
                        if(todos){
                            contador++;
                        }
                        //cout << i << " "  << j << " " << k << " " << l << " valor " << dp[i][j][k][l] << " compara " << abs(k-i)*abs(l-j)  << endl;
                    }      
                }
                
            }
        }
        
        cout << contador << endl;
        
    
    }
    return 0;
}

