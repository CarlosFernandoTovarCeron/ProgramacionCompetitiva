#include <iostream>
#include <cstring>

using namespace std;

int t[105];
int b[105];
int dp[105][105];

int n;

int c(int j, int bolasgastadas){
	if(j==n+1){
		return 0;
	}else{
        if(dp[j][bolasgastadas]!=-1) return dp[j][bolasgastadas];
        
		int bolasdisp = b[j-1] - bolasgastadas;
		if(bolasdisp>0){
			int iz = (t[j]/2) + c(j+1, bolasgastadas+1);
			int der = t[j] + c(j+1, bolasgastadas);
			dp[j][bolasgastadas] = min(iz, der);
			return min(iz, der);
		}else{
		    dp[j][bolasgastadas] = t[j] + c(j+1, bolasgastadas);
			return dp[j][bolasgastadas];
		}
		
	}
}

int main(int argc, char** argv) {
	
	while(cin >> n, n){
	    memset(dp, -1, sizeof(dp));
		int bolasacumuladas = 0;
		b[0] = 0;
		for(int i=1; i<=n; i++){
			int ti, bi;
			cin >> ti >> bi;
			bolasacumuladas += bi;
			t[i] = ti;
			b[i] = bolasacumuladas;
		}
		
		cout << c(1, 0) << endl;
		
	}
	
	return 0;
}
