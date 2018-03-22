#include <iostream>
#include <stdio.h>

#define inf 1000000000;
using namespace std;

struct pareja{
    int libros;
    int dis;
    bool operator<(const pareja& obj){
        if(libros<obj.libros){
            return true;
        }else if(libros==obj.libros){
            if(dis<obj.dis){
                return true;
            }else{
                return false;
            }
        }
    }
};

int suma[1005];
pareja dp[1005];
int l, c, n;
pareja costo(int j){
    if(j==n+1){
        pareja ret;
        ret.libros = 0;
        ret.dis = 0;
        return ret;
    }
    
    if(dp[j].libros!=-1){
        return dp[j];
    }
    
    pareja minimo;
    minimo.libros = inf;
    for(int k=j; k<=n; k++){
        int lecturas = suma[k] - suma[j-1];
        if(lecturas>l) break;
        int tlibre = l-lecturas;
        int disaux;
        if(tlibre==0){
            disaux = 0;
        }else if(tlibre>=1 and tlibre<=10){
            disaux = -c;
        }else{
            disaux = (tlibre-10)*(tlibre-10);
        }
        
        pareja nodo = costo(k+1);
        dp[k+1] = nodo;
        nodo.libros = nodo.libros + 1;
        nodo.dis = nodo.dis + disaux;
        if(nodo < minimo){
            minimo = nodo;
        }else if(nodo.libros == minimo.libros){
            if(nodo.dis<minimo.dis){
                minimo = nodo;
            }
        }
    }
    dp[j] = minimo;
    return minimo;
}

int main(int argc, char** argv) {
	freopen("inlibros.txt", "r", stdin);
	freopen("outlibros.txt", "w", stdout);
    int casos = 1;
    while(true){
        cin >> n;
        if(n==0){
            break;
        }
        for(int i=0; i<1005; i++){
            pareja aux;
            aux.libros=-1;
            dp[i] = aux;
        }
       
        cin >> l >> c;
        int s = 0;
        suma[0] = 0;
        for(int i=1; i<=n; i++){
            int aux;
            cin >> aux;
            s+=aux;
            suma[i] = s;
        }
        pareja res = costo(1);
        if(casos!=1){
        	cout << endl;
		}
        cout << "Case " << casos << ":" << endl;
        cout << "Minimum number of lectures: " << res.libros << endl;
        cout << "Total dissatisfaction index: " << res.dis << endl;
        //cout << res.libros << " " << res.dis << endl;
        casos++;
        
    }

    return 0;
}
