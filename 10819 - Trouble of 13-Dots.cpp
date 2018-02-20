#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 1000000000

using namespace std;

int m, n;
int precios[105];
int beneficios[105];
int dp[105][20005];

int c(int j, int gastado){
	if(j==-1){
		if(gastado>2000){
			if(m+200-gastado<0){
				return -INF;
			}else{
				return 0;
			}
		}else{
			if(m-gastado<0){
				return -INF;
			}else{
				return 0;
			}
			
		}
	}
	
	if(m + 200 - gastado<0) return -INF;
	
	if(dp[j][gastado]!=-1) return dp[j][gastado];

	int res = max(c(j-1, gastado), beneficios[j] + c(j-1, gastado+precios[j]));
	dp[j][gastado] = res;
	return res;


}

int main(){
	while(cin >> m >> n){
		memset(dp, -1, sizeof(dp));
		for(int i=0; i<n; i++){
			int aux;
			cin >> aux;
			precios[i] = aux;
			cin >> aux;
			beneficios[i] = aux;
		}
		
		cout << c(n-1, 0) << endl;
		
	}
	

}
