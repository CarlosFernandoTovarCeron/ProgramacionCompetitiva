#include <iostream>

using namespace std;

int l;
int cont = 1;
int a[250];
int s[250];
int dp[250][15000];
char ruta[250][15000];

void construirSolucion(int j, int v1){
	if(j==cont) return;
	if(ruta[j][v1]=='n'){
		return;
	}else if(ruta[j][v1]=='i'){
		cout << "starboard" << endl;
		construirSolucion(j+1, v1+a[j]);
	}else if(ruta[j][v1]=='d'){
		cout << "port" << endl;
		construirSolucion(j+1, v1);
	}
}

int main(int argc, char** argv) {
    int t;
    cin >> t;
    while(t--){

        cin >> l;
        l = l*100;

        int aux = -1;
        cont = 1;
        while(true){
            cin >> aux;
            if(aux==0) break;
            a[cont] = aux;
            cont++;
        }
        
        int sum = 0;
        s[0] = 0;
        for(int i=1; i<cont; i++){
            sum = sum + a[i];
            s[i] = sum;
        }
        
for(int v=0; v<15000; v++){
	dp[cont][v] = 0;
}

for(int j=cont-1; j>=1; j--){
	for(int v1=l; v1>=0; v1--){
		int v2 = s[j-1] - v1;
		if(v1 + a[j] > l and v2 + a[j] > l){
			dp[j][v1] =  0;
			ruta[j][v1] = 'n'; //ninguna
		}else if(v1 + a[j] <= l and v2 + a[j] > l){
			dp[j][v1] = 1 + dp[j+1][v1+a[j]];
			ruta[j][v1] = 'i'; //izquierda
		}else if(v1 + a[j] > l and v2 + a[j] <= l){
			dp[j][v1] = 1 + dp[j+1][v1];
			ruta[j][v1] = 'd'; //derecha
		}else{
			int iz = 1 + dp[j+1][v1+a[j]], der = 1 + dp[j+1][v1];
			if(iz>der){
				ruta[j][v1] = 'i'; //izquierda
			}else{
				ruta[j][v1] = 'd'; //derecha
			}
			dp[j][v1] = max(iz, der);
		}	
	}

}
        
        cout << dp[1][0] << endl;
	construirSolucion(1, 0);
	if(t!=0)
	cout << endl;

    }
    return 0;
}
