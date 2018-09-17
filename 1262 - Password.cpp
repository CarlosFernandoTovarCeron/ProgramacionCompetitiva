#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

string arreglo1[6];
string arreglo2[6];
map <string, bool> mymap;
map <string, bool> visitados;

void f(string current, int j){
    if(j==5){
        mymap[current] = true;
        return;
    }
    
    map <string, bool>::iterator it;
    it = visitados.find(current);
    if(it!=visitados.end()){
        return;
    }
    
    visitados[current] = true;
    
    for(int i=0; i<6; i++){
        for(int k=0; k<6; k++){
            if(arreglo1[i][j] == arreglo2[k][j]){
                string aux = current + arreglo1[i][j] ;
                f(aux, j+1);
            }
        }
    }
    
}

int main() {

    int casos;
    cin >> casos;
    
    while(casos--){
        int p;
        cin >> p;
        
        for(int i=0; i<6; i++){
            string aux;
            cin >> aux;
            arreglo1[i] = aux;
        }
        for(int i=0; i<6; i++){
            string aux;
            cin >> aux;
            arreglo2[i] = aux;
        }
        
        f("", 0);
        
        if(mymap.size()<p){
            cout << "NO" << endl;
        }else{
            int k=1;
            for(map <string, bool>::iterator it = mymap.begin(); it!=mymap.end(); ++it){
                
                if(k==p){
                    cout << it->first << endl;
                    break;
                }
                k++;
            }
        }
        
        mymap.clear();
        visitados.clear();
    }
        
        
	return 0;
}
