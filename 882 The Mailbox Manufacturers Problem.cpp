#include <iostream>
#include <cstring>

using namespace std;

#define inf 1000000000;

int dp[15][105][105];

int c(int r, int i, int j){
	
	if(i>j){
		return 0;
	}
	
	if(r==1){
		return (j*(j+1)/2) - (i*(i+1)/2) + i;
	}
	
	if(dp[r][i][j]!=-1) return dp[r][i][j];
	
	int ret = inf;
	for(int n=i; n<=j; n++){
		int explota = n + c(r-1, i, n-1);
		int noexplota = n + c(r, n+1, j);
		ret = min(ret, max(explota, noexplota));
	}
	
	dp[r][i][j] = ret;

	return ret;

}


int main(){
	int casos;
	cin >> casos;
    memset(dp, -1, sizeof(dp));
	while(casos--){
		int k, m;
		cin >> k >> m;
		cout << c(k, 1, m) << endl;
	}


}
