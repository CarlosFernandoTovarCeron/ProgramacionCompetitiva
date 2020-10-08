
#include <iostream>
#include <cstring>

using namespace std;

int numeros[205];
int dp[205][25][205];
int d, m;

int c(int elementos, int suma, int it){

	if(suma<0) suma+=d;

	if(it==-1){
		if(suma%d==0 and elementos == m){
			return 1;
		}
		else
			return 0;
	}else{

		if(dp[elementos][suma][it]!=-1)
			return dp[elementos][suma][it];

		int iz = c(elementos+1, (suma+numeros[it])%d, it-1);
		int der = c(elementos, suma%d, it-1);

		dp[elementos][suma][it] = iz + der;

		return iz + der;

	}
}

int main() {
	int n, q;
	cin >> n >> q;
	int set = 1;
	while(n!=0 and q!=0){

		for(int i=0; i<n; i++){
			int aux; cin >> aux;
			numeros[i] = aux;
		}

		cout << "SET " << set << ":" << endl;

		for(int i=0; i<q; i++){
			cin >> d >> m;
			memset(dp, -1, sizeof(dp));
			cout << "QUERY " << i+1 << ": "<< c(0, 0, n-1) << endl;
		}

		cin >> n >> q;
		set++;
	}
	return 0;
}
