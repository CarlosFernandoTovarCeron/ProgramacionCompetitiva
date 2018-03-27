#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//1 1 3 3 2

bool letra[25];
int pesos[25];
int aux, k, l;
int dp[1 << 25];

int c(int b){
    bool prendidos = true;
    for(int i=0; i<k; i++){
        int mask=1<<i;
        if(!(b&mask)){
            prendidos = false;
            break;
        }
    }
    
    if(prendidos){
        return true;
    }
    
    if(dp[b]!=-1){
        return dp[b];
    }
    
    bool f = false;
    for(int i=0; i<k; i++){
        int mask = 1 << i;
        if(!(b&mask)){
            int iz = -1, der = -1;
            for(int j=i+1; j<k; j++){
                int mask2 = 1 << j;
                if(!(b&mask2)){
                    der = j;
                    bool r = b&mask;
                    break;
                }
            }
            for(int j=i-1; j>=0; j--){
                int mask2 = 1 << j;
                if(!(b&mask2)){
                    iz = j;
                    break;
                }
            }
            
            
            int pesoaux = pesos[i];

            if(iz!=-1){
                if(letra[iz]==letra[i]){
                    pesoaux+=pesos[iz];            
                }
            }
            
            if(der!=-1){
                if(letra[der]==letra[i]){
                    pesoaux+=pesos[der];
                }
            }
            
            //cout << "i " << i  << " iz " << iz << " der " << der << " peso " << pesoaux <<  endl;  

            if(pesoaux>=2){
                int cb = b;
                int mask = 1 << iz;
                if(iz!=-1){
                    if(letra[iz]==letra[i])
                        cb = cb|mask;
                }
                mask = 1 << der;
                if(der!=-1){
                    if(letra[der]==letra[i]){
                        cb = cb|mask;
                    }
                }
                mask = 1 << i;
                cb = cb|mask;
                dp[cb] = c(cb); 
                f = f or dp[cb];
            }

        }
    }
    
    dp[b] = f;
    
    return f;
    
}

//   aaa1aaa1aaaa

int main() {
    int casos;
    cin >> casos;
    while(casos--){
        memset(dp, -1, sizeof(dp));
        string linea;
        cin >> linea;
        if(linea[linea.length()-1]=='a'){
            linea+="b";
        }else{
            linea+="a";
        }
        aux = 0; k = 0; l = linea[0] == 'a';
        for(int i=0; i<linea.length(); i++){
            if(l){
                if(linea[i]!='a'){
                    pesos[k] = aux;
                    letra[k] = l;
                    aux = 0;
                    l = linea[i] == 'a';
                    k++;

                }
                aux++;
            }else{
                if(linea[i]=='a'){
                    pesos[k] = aux;
                    letra[k] = l;
                    aux = 0;
                    l = linea[i] == 'a';
                    k++;
                }
                aux++;
            }
            
        }
        
        cout << c(0) << endl;
        

    }
	return 0;
}
