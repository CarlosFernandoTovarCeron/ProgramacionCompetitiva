#include <iostream>
#include <cstring>
#include <algorithm>

#define mINF -1000000000

using namespace std;

int dp[202][22][22];
int v[22][22];
int C;

int s(int b, int f, int c){

	if(b<0){
		return mINF;
	}

	if(f<C){
		if(v[f][c]==-1){
			return mINF;
		}else{

			if(dp[b][f][c]!=-1)
				return dp[b][f][c];

			int iz = s(b-v[f][c], f+1, 0) + v[f][c];
			int der = s(b, f, c+1);
			int dpbfc = max(iz, der);
			dp[b][f][c] = dpbfc;
			return dpbfc;
		}
	}else{
		return 0;
	}
}

int main() {

	int t;
	cin >> t;

	for(int i=0; i<t; i++){
		memset(dp, -1, sizeof(dp));
		memset(v, -1, sizeof(v));

		int b, c;
		cin >> b >> c;
		C = c;

		for(int l=0; l<c; l++){
			int k;
			cin >> k;

			for(int r=0; r<k; r++){
				int aux; cin >> aux;
				v[l][r] = aux;
			}
		}
		int sol = s(b, 0, 0);
		if(sol<0){
			cout << "no solution" << endl;
		}else{
			cout << sol << endl;
		}
	}

	return 0;
}
