
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <map>

//double dp[105];

using namespace std;

double up;
int ns[25];
int m;
double prices[25];
map <int, double> mymap;
 
double c(int comprados){
    
    if(comprados<=0){
        return 0.0;
    }
    int minimo = 100000000;
    for(int j=0; j<m; j++){
        double nodo = prices[j] + c(comprados-ns[j]);
        if(nodo < minimo){
            minimo = nodo;
        }
    }
    
    return minimo;
    

}

int main(int argc, char** argv) {
    
    cout << fixed;
    cout << setprecision(2) << endl;
    
    int casos = 1;
    while(cin >> up){
        cin >> m;

        for(int i=0; i<m; i++){
            int n;
            cin >> n;

            double p;
            cin >> p;

            ns[i] = n;
            prices[i] = p;
        }

        string linea;
        getline(cin, linea); // lee nada
        getline(cin, linea);

        stringstream ss(linea);
        cout << "Case " << casos << ": " << endl;
        int k;
        while(ss >> k){
            cout << "Buy " << k << " for $" << c(k)  << endl;
        }
        casos++;
    
    }
    


    return 0;
}

