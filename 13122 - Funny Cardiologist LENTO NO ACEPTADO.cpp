#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <utility>
#include <vector>

using namespace std;

double x[258];
double y[258];

double dp[300][300];

#define INF 1000000000.0

double distanceCalculate(double x1, double y1, double x2, double y2){
	double x = x1 - x2;
	double y = y1 - y2;
	double dist;
	dist = pow(x, 2) + pow(y, 2);
	dist = sqrt(dist);
	return dist;
}

struct segmento{
	int posf;
	double x1;
	double y1;
	double x2;
	double y2;
};

int n;
vector < vector <segmento> > segmentos;

double c(int j, int faltan){
	if(j==n-1 and faltan==0)
		return 0.0;
		
	if(j==n-1 and faltan!=0){
		return INF;
	}
	
	if(dp[j][faltan] != -1.0) return dp[j][faltan];
	
	double minimo = INF;
	for(int k=0; k<segmentos[j].size(); k++){
		minimo = min(distanceCalculate(segmentos[j][k].x1, segmentos[j][k].y1, segmentos[j][k].x2, segmentos[j][k].y2)
			 +c(segmentos[j][k].posf, faltan-1), minimo);
	}
	
	dp[j][faltan] = minimo;
	
	return minimo;
}

int main() {
	
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout << fixed;
cout << setprecision(3);
    
    int k;
    while(cin >> n >> k){
	std::fill(dp[0] + 0, dp[257] + 257, -1.0);

for(int i=0; i<n; i++){
            double aux;
            cin >> aux;
            x[i] = aux;
            cin >> aux;
            y[i] = aux;
        }
        
        
        for(int i=0; i<n-1; i++){
        	vector <segmento> col;
        	for(int j=i+1; j<n; j++){
        		segmento aux; aux.posf = j;
        		aux.x1 = x[i]; aux.x2 = x[j];
        		aux.y1 = y[i]; aux.y2 = y[j];
        		col.push_back(aux);
        	}
        	segmentos.push_back(col);
        }
        
        cout << c(0, n-k-1) << endl;
        
    }

	return 0;
}
