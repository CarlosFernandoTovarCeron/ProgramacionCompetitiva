//============================================================================
// Name        : 11407.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
using namespace std;

#define INF 1000000

int cuadrados[105];
int dp[10001][105];

int c(int cambio, int j){
	if(cambio==0) return 0;
	if(j<0 or cambio<0) return INF;

	if(dp[cambio][j]!=-1) return dp[cambio][j];
	int res = min(1+c(cambio - cuadrados[j], j), c(cambio, j-1));
	dp[cambio][j] = res;
	return res;

}

int main() {

	for(int i=0; i<105; i++){
		cuadrados[i] = (i+1)*(i+1);
	} memset(dp, -1, sizeof(dp));
	int casos; cin >> casos;
	while(casos--){
		int n; cin >> n;
		cout << c(n, 104) << endl;
	}
	return 0;
}
