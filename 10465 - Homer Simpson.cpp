#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define INF -1000000000

using namespace std;

int h[10001];
int n, m;

int cost(int t){
    if(t<0){
        return INF;
    }else if(t==0){
        return 0;   
    }else{
        if(h[t]!=-1)
            return h[t];
            
        int iz = t>=n? cost(t-n) + 1 : INF;
        int der = t>=m? cost(t-m) + 1 : INF;
        int res = max(iz, der);
        h[t] = res;
        return res;
    }
}


int main() {
    
    int t;
    while(cin >> n >> m >> t){
        memset(h, -1, sizeof(h));
        int d=0, res;
        res = cost(t);
        while(res<0){
            t--;
            d++;
            memset(h, -1, sizeof(h));
            res = cost(t);
        }
        
        cout << res;
        if(d!=0){
            cout << " " << d;
        }cout << endl;

    }
    
	return 0;
}
