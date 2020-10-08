
#include <iostream>

using namespace std;

bool dp[105][64005];
char ruta[105][64005];

int a[105];

bool nodesborda(int n){
	if(n>=-32000 and n<=32000) return true; else return false;
}

void printsol(int i, int j){

	if(i==0){
		cout << a[i];
	}else{
		if(ruta[i][j] == '*'){
			printsol(i-1, (j-32000) / a[i] + 32000);
			cout << "*" << a[i];
		}else if(ruta[i][j] == '/'){
			printsol(i-1, (j-32000) * a[i] + 32000);
			cout << "/" << a[i];
		}else if(ruta[i][j] == '+'){
			printsol(i-1, (j-32000) - a[i] + 32000);
			cout << "+" << a[i];
		}else if(ruta[i][j] == '-'){
			printsol(i-1, (j-32000) + a[i] + 32000);
			cout << "-" << a[i];
		}
	}


}

int main() {

	int casos;
	cin >> casos;

	while(casos--){
		int n; cin >> n;

		for(int i=0, aux; i<n; i++){
			cin >> aux;
			a[i] = aux;
		}

		int s;
		cin >> s;
		s+=32000;

		for(int j=0; j<=64000; j++){
			dp[0][j] = a[0] == (j - 32000); //MOD
		}

		for(int i=1; i<n; i++){
			for(int j=1; j<=64000; j++){

				bool multiplicar = nodesborda((j-32000)*a[i]) ? dp[i-1][(j-32000)*a[i] + 32000] : false;
				bool sumar       = nodesborda((j-32000)+a[i]) ? dp[i-1][(j-32000)+a[i] + 32000] : false;
				bool restar      = nodesborda((j-32000)-a[i]) ? dp[i-1][(j-32000)-a[i] + 32000] : false;
				bool dividir = a[i]==0  ? false : (j-32000)%a[i] != 0 ? false : nodesborda((j-32000)/a[i]) ? dp[i-1][(j-32000)/a[i] + 32000] : false;
				dp[i][j] = multiplicar or sumar or restar or dividir;

				if(multiplicar)
					ruta[i][j] = '/';
				else if(dividir)
					ruta[i][j] = '*';
				else if(sumar)
					ruta[i][j] = '-';
				else if(restar)
					ruta[i][j] = '+';
				else
					ruta[i][j] = '?';
			}
		}

		if(dp[n-1][s]){
			printsol(n-1, s);
			cout << "=" << s-32000;
		}else{
			cout << "NO EXPRESSION";
		}
		cout << endl;

	}

	return 0;
}
