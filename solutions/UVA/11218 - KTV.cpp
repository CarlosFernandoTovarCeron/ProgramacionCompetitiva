#include <iostream>
#include <vector>
#include <cstring>

#define inf 10000000000;

using namespace std;

int dp[1 << 12];

vector <vector <int> > matrix;
int scores[85];

int n;
int c(int b){

    bool esta[10];
    bool f = true;
    for(int j=1; j<=9; j++){
        int mask = 1 << j;
        if(!(b&mask)){
            f = false;
            esta[j] = false;
            //cout << 0 << " ";
        }else{
            esta[j] = true;
            //cout << 1 << " ";
        }
    }
    
    
    if(f) return 0;
    
        
    bool fi = false;
    for(int i=0; i<n; i++){
        bool f1 = true;
        for(int j=0; j<3; j++){
            f1 = f1 and !esta[matrix[i][j]];
        }
        
        if(f1){
            fi = true;
            break;
        }
    }
    
    if(!fi){
        return -inf;
    }

    if(dp[b]!=-1) return dp[b];
    
    int maximo = -inf;
    for(int i=0; i<n; i++){
        bool f1 = true;
        for(int j=0; j<3; j++){
            f1 = f1 and !esta[matrix[i][j]];
        }
        
        if(f1){
            int cb = b;
            for(int j=0; j<3; j++){
                int mask = 1 << matrix[i][j];
                cb = cb|mask;
            }
            int nodo = c(cb);
            dp[cb] = nodo;
            maximo = max(scores[i] + nodo, maximo);
        }
    }
    dp[b] = maximo;
    return maximo;
}

int main() {
    int caso = 1;
    while(true){
        cin >> n;
        if(n==0) break;
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            int a, b, c, s;
            cin >> a >> b >> c >> s;
            scores[i] = s;
            vector <int> comb;
            comb.push_back(a);
            comb.push_back(b);
            comb.push_back(c);
            matrix.push_back(comb);
        }
        if(c(0)>=0){
            cout <<"Case " << caso << ": " <<  c(0) << endl;
        }else{
            cout <<"Case " << caso << ": " <<  -1 << endl;

        }
        
        caso++;
        matrix.clear();
    }
	return 0;
}
