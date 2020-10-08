//#include <iostream>
//#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <algorithm>

using namespace std;
#define inf 100000000;
int prices[105];
int favor[105]; // i dim 
int n, x, t, k;

int dp[105][2005][25];

int c(int j, int g, int b){
    
    if(b>2*n){
        return -inf;
    }
    
    if(j==k){
        double gd = (double) g;
        double td = (double) t;
        double nd = (double) n;
        gd = 0.1*(gd + nd*td) + (gd + nd*td);
        int gi = gd;
        double gdi = (double) gi;
        if(gd-gdi>0){
            g = gd + 1.0;
        }else{
            g = gd;
        }
        if(b<=2*n and g<=x*n){
            return 0;
        }else{
            return -inf;
        }
    }
    
    if(dp[j][g][b]!=-1) return dp[j][g][b];
    
    int x, y, z;
    x = c(j+1, g, b);
    y = favor[j] + c(j+1, g+prices[j], b+1);
    z = 2*favor[j] + c(j+1, g+2*prices[j], b+2);
    
    //dp[j+1][g][b] = x;
    //dp[j+1][g+prices[j]][b+1] = y - favor[j];
    //dp[j+1][g+2*prices[j]][b+2] = z - 2*favor[j];
    
    dp[j][g][b] = max(x, max(y, z));
    return dp[j][g][b];
    
}

int main() {
    while(true){
        scanf("%d%d%d%d", &n, &x, &t, &k);
        //cin >> n >> x >> t >> k;
        if(!(n or x or t or k)) break;
        memset(dp, -1, sizeof(dp));
        n++; // yo
        for(int i=0; i<k; i++){
            favor[i] = 0;
        }
        
        for(int i=0; i<k; i++){
            int price;
            //in >> price;
            scanf("%d", &price);
            prices[i] = price;
            
            for(int j=0; j<n; j++){
                int aux;
                //cin >> aux;
                scanf("%d", &aux);
                favor[i]+=aux;
            }
        }
        /*
        for(int i=0; i<k; i++){
            cout << favor[i] << " ";
        }cout << endl;*/
        double f = (double) c(0, 0, 0);
        double nd = (double) n;
        double res = f / nd;
        printf("%.2f\n", res);    // prints out 0.94
        //cout << setprecision(2);
        //cout << fixed;
        //cout <<  res << endl;
        
    }
	return 0;
}

