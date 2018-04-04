#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

#define inf 1000000000;

using namespace std;
int n, m;
int costo[205];
int dominados[205];
int papa[205];
bool visitado[205];
map <string, int> id;
map <int, vector <int> > hijos;
vector <int> raices;


void expandir(int nodo){
    if(!visitado[nodo]){
        visitado[nodo] = true;
        if(papa[nodo]==-1){
            raices.push_back(nodo);
        }else{
            expandir(papa[nodo]);
        }
        
        for(int i=0; i<hijos[nodo].size(); i++){
            expandir(hijos[nodo][i]);
        }
    }
}

int c(int i, int j, int macu){
    cout << i << " " << j << " " << macu << endl;
    if(j==raices.size()){
        if(macu>=m){
            return 0;
        }else{
            return inf;
        }
    }else{
        int comprar = costo[i] + c(raices[j+1], j+1, macu+1+dominados[i]);
        int nocomprar = 0;
        for(int k=0; k<hijos[i].size(); k++){
            nocomprar+= c(hijos[i][k], j, macu);
        }
        return min(comprar, nocomprar);
    }
    
}

int calcularDominados(int nodo){
    int res = 0;
    for(int i=0; i<hijos[nodo].size(); i++){
        res+= 1 + calcularDominados(hijos[nodo][i]);
    }
    dominados[nodo] = res;
    return res;
}

int main() {
    

    while(cin >> n >> m){
        string linea;
        getline(cin, linea);
        
        for(int i=0; i<n; i++){
            hijos[i] = vector <int>();
            visitado[i] = false;
            papa[i] = -1;
        }
        int j = 0; //id
        for(int i=0; i<n; i++){
            getline(cin, linea);
            stringstream ss;
            ss << linea;
            
            string papaTexto;
            ss >> papaTexto;
            
            int idpapa; //id del elemento i
            
            map <string, int>::iterator it;
            it = id.find(papaTexto);
            if(it==id.end()){
                id[papaTexto] = j;
                idpapa = j;
                j++;
            }else{
                idpapa = id[papaTexto];
            }
            
            int valor;
            ss >> valor;
            costo[idpapa] = valor;
            
            string nodo;
            while(ss >> nodo){
                map <string, int>::iterator it;
                it = id.find(nodo);
                if(it==id.end()){
                    id[nodo] = j;
                    j++;
                }
                int idNodo = id[nodo];
                papa[idNodo] = idpapa;
                hijos[idpapa].push_back(idNodo);
            }
        }
        
        
        for(int i=0; i<n; i++){
            if(visitado[i]==false){
                expandir(i);
            }
        }
        
        for(int i=0; i<raices.size(); i++){
            calcularDominados(raices[i]);
        }
        raices.push_back(50); //CAMBIAR 
        //cout << raices[0] << endl;
        //cout << hijos[1].size() << endl;
        cout << hijos[1][0] << endl;
        cout << c(raices[0], 0, 0);
        
        /*  
        cout << id["I"] << endl; 
        cout << hijos[8].size() << endl;
        cout << dominados[8] << endl;
        
        

      
        cout << "conjuntos " << raices.size() << endl << endl;
        
        cout << "Id Aland: " << id["Aland"] << endl;
        cout << "papa Aland:" << papa[id["Aland"]] << endl;
        cout << "Hijos Aland " << hijos[id["Aland"]].size() << endl << endl;
        
        cout << "Id Boland: " << id["Boland"] << endl;
        cout << "papa Boland:" << papa[id["Boland"]] << endl << endl;
        cout << "Hijos Boland " << hijos[id["Boland"]].size() << endl; 

        
        cout << "Id Coland: " << id["Coland"] << endl;
        cout << "papa Coland:" << papa[id["Coland"]] << endl;
        cout << "Hijos Coland " << hijos[id["Coland"]].size() << endl; 
    */
    }
    
	return 0;
}
