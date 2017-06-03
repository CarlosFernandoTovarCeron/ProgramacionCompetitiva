#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    
    int b;
    while(cin >> b){
        vector <int> libros;
        for(int i=0; i<b; i++){
            int aux; cin >> aux;
            libros.push_back(aux);
        } int p; cin >> p;
        sort(libros.begin(), libros.end());
        
        int i=0, j = b-1, l, r, mindif = 1000000000;
        while(i<j){
            if(libros[i]+libros[j]==p){
                if(abs(libros[i]-libros[j])<mindif){
                    mindif = abs(libros[i]-libros[j]);
                    l = libros[i]; r = libros[j];
                }
                j--; i++;
            }else if(libros[i]+libros[j] > p){
                j--;
            }else{
                i++;
            }
        }
        
        printf("Peter should buy books whose prices are %d and %d.\n\n", l , r);
    }
    
	return 0;
}
