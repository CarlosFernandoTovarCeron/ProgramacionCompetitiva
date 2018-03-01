#include <iostream>
using namespace std;


int main() {
    int cantidad[7];
    while(true){
        bool todoscero = true;
        for(int i=1; i<=6; i++){
            int aux;
            cin >> aux;
            cantidad[i] = aux;
            if(aux!=0){
                todoscero = false;
            }
        }
        if(todoscero) break;
        
        int total = cantidad[6] + cantidad[5] + cantidad[4];
        int unoporuno = cantidad[5]*11;
        cantidad[1]-=unoporuno;
        int dospordos = cantidad[4]*5;
        cantidad[2]-=dospordos;
        if(cantidad[2]<0){
            cantidad[1]-= abs(cantidad[2])*4;
        }
        
        int pdetres = (cantidad[3] - cantidad[3]%4)/4;
        total+=pdetres;
        
        if(cantidad[3]%4!=0){
            total++;
            

            
            switch(cantidad[3]%4){
                case 1:
                    dospordos = 5;
                    unoporuno = 7;
                break;
                case 2:
                    dospordos = 3;
                    unoporuno = 6;
                break;
                case 3:
                    dospordos = 1;
                    unoporuno = 5;
                break;
            }

            cantidad[1]-=unoporuno;
            cantidad[2]-=dospordos;
            
        }
        
        if(cantidad[2]>0){
            int sumar = (cantidad[2] - cantidad[2]%9)/9;
            total+=sumar;

            if(cantidad[2]%9!=0){
                total++;
                unoporuno = 36 - (cantidad[2]%9)*4;
                cantidad[1]-=unoporuno;
            }

        }
        
        if(cantidad[1]>0){
            int sumar = (cantidad[1] - cantidad[1]%36)/36;
            total+=sumar;

            if(cantidad[1]%36!=0){
                total++;

            }
        }
        
        cout << total << endl;
        
    }
    
	return 0;
}
