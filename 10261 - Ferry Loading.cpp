#include <iostream>

#define inf 1000000000
using namespace std;

int l;
int cont = 1;
int a[205];
int s[205];

int c(int j, int v1){
    
    if(j==cont) return 0;

    int v2 = s[j-1] - v1;
     
    if(v1 + a[j] > l and v2 + a[j] > l){
        return 0;
    }else if(v1 + a[j] <= l and v2 + a[j] > l){
        return 1 + c(j+1, v1+a[j]);
    }else if(v1 + a[j] > l and v2 + a[j] <= l){
        return 1 + c(j+1, v1);
    }else{
        return max(1 + c(j+1, v1+a[j]), 1 + c(j+1, v1));
    }

}

int main(int argc, char** argv) {
    int t;
    cin >> t;
    while(t--){

        cin >> l;
        l = l*100;

        int aux = -1;
        while(true){
            cin >> aux;
            if(aux==0) break;
            a[cont] = aux;
            cont++;
        }
        
        int sum = 0;
        s[0] = 0;
        for(int i=1; i<cont; i++){
            sum = sum + a[i];
            s[i] = sum;
        }
        cout << c(1, 0) << endl;

    }
    return 0;
}

