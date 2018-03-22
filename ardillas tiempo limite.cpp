#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int nueces[2505][2505];
int dp[2505][2505];

int t, h, f;
int c(int arbol, int altura){

	if(altura<0){
		return 0; 
	}

	if(dp[arbol][altura]!=-1){
		return dp[arbol][altura];
	}

	int abajo = nueces[arbol][altura] +  c(arbol, altura-1);
	int maximo = abajo;
	for(int i=0; i<t; i++){
		if(arbol!=i){
			int nodo = nueces[arbol][altura] + c(i, altura-f);
			if(altura-f>=0){
				dp[i][altura-f] = nodo - nueces[arbol][altura];
			}
			maximo = max(nodo, maximo);
		}
		
	}
	dp[arbol][altura] = maximo;
	return maximo;
}

int main(){
	freopen("i", "r", stdin);
	freopen("o", "w", stdout);
	int casos;
	cin >> casos;

	while(casos--){
		cin >> t >> h >> f;
		memset(nueces, 0, sizeof(nueces));
		memset(dp, -1, sizeof(dp));
		for(int i=0; i<t; i++){
			int cnueces;
			cin >> cnueces;

			for(int j=0; j<cnueces; j++){
				int aux;
				cin >> aux;
				nueces[i][aux]++;
			}
		}
		int maximo = c(0, h+f);
		cout << maximo << endl;


	}

	cin >> casos;

	
}
