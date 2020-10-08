
#include <iostream>
using namespace std;

int arreglo[105];
int sum[105][105];

int main() {
	int n; cin >> n;

	for(int i=0; i<n; i++){
		int aux; cin >> aux;
		arreglo[i] = aux;
	}

	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(i==j){
				sum[i][j] = arreglo[i]; //or j
			}else{
				sum[i][j] = sum[i][j-1] + arreglo[j];
			}
		}
	}

	int maxi = -1;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			int c = j-i+1;
			int centro = c - sum[i][j];
			int iz = i == 0 ? 0 : sum[0][i-1];
			int der = j == n-1 ? 0 : sum[j+1][n-1];
			maxi = max(maxi, centro + iz + der);

		}
	}

	cout << maxi << endl;


	return 0;
}
