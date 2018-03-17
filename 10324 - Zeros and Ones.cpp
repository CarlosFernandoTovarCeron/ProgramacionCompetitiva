#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string linea;
    int casos = 1;
    while(getline(cin, linea)){
        cout << "Case " << casos << ":"<< endl;
        
        int suma[linea.length()];
        int aux = 0;
        for(int i=0; i<linea.length(); i++){
            aux += linea[i] - '0';
            suma[i] = aux;
        }
        
        int n;
        cin >> n;
        
        
        for(int i=0; i<n; i++){
            int a, b;
            cin >> a >> b;
            
            if(a>b){
                swap(a, b);
            }
            int sumaintervalo = suma[b] - suma[a] + (linea[a] - '0');
            if(b-a+1 == sumaintervalo or sumaintervalo == 0){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
            
        }
        
        casos++;
        getline(cin, linea);
        
    }
    
    
    
	return 0;
}
