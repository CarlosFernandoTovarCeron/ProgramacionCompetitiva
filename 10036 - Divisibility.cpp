#include <iostream>
#include <cstring>
using namespace std;

int casos, n, k;
int array[10005];
int dp[105][10005];

bool c(int suma, int it){

	if(it!=-1){
		if(suma<0) suma+=k;

		if(dp[suma][it]!=-1)
			return dp[suma][it]==1;

		int iz = c((suma+array[it])%k, it-1);
		int der = c((suma-array[it])%k, it-1);

		dp[suma][it] = (int) (iz or der);
		return iz or der;
	}else{
		return suma%k==0;
	}

}

int main() {
	cin >> casos;

	while(casos--){
		memset(dp, -1, sizeof(dp));
		cin >> n >> k;
		for(int i=0; i<n; i++){
			int aux; cin >> aux;
			array[i] = aux;
		}
		bool res = c(0, n-1);
		if(res) cout << "Divisible" << endl; else cout << "Not divisible" << endl;
	}
	return 0;
}
