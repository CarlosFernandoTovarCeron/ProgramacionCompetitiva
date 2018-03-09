#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;
#define INF 1000000000

vector <vector <int> > combos;
map <string, int> dp;
map <string, int>::iterator it;

int p[10];
int c[10];
int n;

int costo(string estado){
    bool todosceros = true;
    for(int i=0; i<n; i++){
        if(estado[i]!='0'){
            todosceros = false;
            break;
        }
    }
    
    if(todosceros) return 0;
    
    it = dp.find(estado);
    if(it!=dp.end()){
        return dp[estado];
    }
    
    int minimo = INF;
    for(int i=0; i<n; i++){
        string copiaestado = estado;
        if(copiaestado[i]!='0'){
            copiaestado[i] = (char) (((copiaestado[i] - '0') - 1) + '0');
            int nodo = p[i] + costo(copiaestado);
            dp[copiaestado] = nodo - p[i];
            minimo = min(nodo, minimo);
        }
    }
    
    for(int i=0; i<combos.size(); i++){
        bool puedocombo = true;
        for(int j=0; j<n; j++){
            if(combos[i][j] > (estado[j] - '0')){
                puedocombo = false;
                break;
            }
        }
        
        if(puedocombo){
            string copiaestado = estado;
            for(int j=0; j<n; j++){
                copiaestado[j] = (char) (((copiaestado[j] - '0') - combos[i][j]) + '0');
            }
            int nodo = c[i] + costo(copiaestado);
            dp[copiaestado] = nodo - c[i];
            minimo = min(nodo, minimo);
        }
        
    }
    
    dp[estado] = minimo;
    
    return minimo;
}

int main() {
   // char letra = '1';
   // char res = (char) (((letra - '0') - 1) + '0');
   // cout << res << endl;
   // return 0;
    while(cin >> n){
        for(int i=0; i<n; i++){
            int precio;
            cin >> precio;
            p[i]= precio;
        }
        int ccombos;
        cin >> ccombos;
        for(int i=0; i<ccombos; i++){
            vector <int> combo;
            for(int j=0; j<n; j++){
                int aux;
                cin >> aux;
                combo.push_back(aux);
            }
            
            combos.push_back(combo);
            
            int preciocombo;
            cin >> preciocombo;
            c[i] = preciocombo;
            
        }
        
        int consultas;
        cin >> consultas;
        for(int i=0; i<consultas; i++){
            string consulta = "";
            for(int j=0; j<n; j++){
                char car;
                cin >> car;
                consulta += car;
            }
            cout << costo(consulta) << endl;
        }
        dp.clear();
        combos.clear();
    }
    return 0;
}
