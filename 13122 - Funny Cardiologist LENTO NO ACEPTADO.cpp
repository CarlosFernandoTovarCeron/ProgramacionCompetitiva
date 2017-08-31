#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <time.h>

using namespace std;

double x[258];
double y[258];

double dp[258][258][258];

#define INF 100000000.0

double distanceCalculate(double x1, double y1, double x2, double y2){
	double x = x1 - x2;
	double y = y1 - y2;
	double dist;
	dist = pow(x, 2) + pow(y, 2);
	dist = sqrt(dist);
	return dist;
}

void reiniciar(){
	for(int i=0; i<258; i++){
		std::fill(dp[i][0], dp[i][0] + 258 * 258, -1.0);
	}
}

double c(int a, int b, int m){
    if(a==0 and m!=0)
        return INF;

    if(m==0)
        return distanceCalculate(x[0], y[0], x[b], y[b]);

    if(dp[a][b][m]!=-1.0){
    	return dp[a][b][m];
    }

    double iz = c(a-1, a, m-1) + distanceCalculate(x[a], y[a], x[b], y[b]);
    double der = c(a-1, b, m);

    dp[a][b][m] =  min(iz, der);

    return min(iz, der);

}

int main() {
    clock_t tStart = clock();
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout << fixed;
    cout << setprecision(3);
    int n, k;
    while(cin >> n >> k){
    	reiniciar();
        for(int i=0; i<n; i++){
            double aux;
            cin >> aux;
            x[i] = aux;
            cin >> aux;
            y[i] = aux;
        }
        cout << c(n-2,n-1, n-k-2) << endl;
    }

    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

	return 0;
}
