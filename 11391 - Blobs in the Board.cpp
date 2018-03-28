#include <cstring>
#include <stdio.h>

#define clearBit(S, j) (S &= ~(1 << j))
using namespace std;

int r, c, n, dp[1<<17];

struct punto{
    int x, y;
};

int posWithPoint(punto p){
    int val;
    val = (p.x-1)*c + p.y;
    return val;
}

punto pointWithPos(int k){
    punto p;
    p.x = k%c!=0 ? ((k-k%c)/c) + 1 : k/c;
    p.y = k - (p.x-1)*c;
    return p;
}

int costo(int b){
	int mov;
	int cont = 0;
    for(int k=1; k<=r*c; k++){
        int mask = 1 << k;
        if(b&mask){
            cont++;
        }
    }
    
    mov = n - cont;
    
    if(mov==n-1){
        return 1;
    }else{
       if(dp[b]!=-1) return dp[b];
       
        int total = 0;
        for(int k=1; k<=r*c; k++){
            int mask = 1 << k;
            if(mask&b){ // hay un globo
                punto p = pointWithPos(k);
                int x = p.x; 
                int y = p.y;
                for(int i=x-2; i<=x-2+4; i=i+2){
                    for(int j=y-2; j<=y-2+4; j=j+2){
                        if((i!=x or j!=y) and i>=1 and i<=r and j>=1 and j<=c){
                            punto paux; 
                            paux.x = i; 
                            paux.y = j;
                            int mask2 = 1 << posWithPoint(paux);

                            punto entre; 
                            entre.x = (x+i)/2;
                            entre.y = (y+j)/2;
                            int mask3 = 1 << posWithPoint(entre);
                            
                            if(!(b&mask2) and (b&mask3)){//casilla libre llegada, centro lleno
                                int cb = b;
                                cb = cb|mask2; // diagonal
                                cb = clearBit(cb, posWithPoint(entre)); // between clear
                                cb = clearBit(cb, k); // k clear
                                int nodo = costo(cb);
                                total += nodo;
                                dp[cb] = nodo;
                            }
                        }
                    }
                }
            }
        }
        dp[b] = total; 
        return total;
        
    }
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

    int casos;
    scanf("%d", &casos);
    for(int i=1; i<=casos; i++){
        memset(dp, -1, sizeof(dp));
        scanf("%d%d%d", &r, &c, &n);
        int b = 0;
        for(int k=1; k<=n; k++){
            int x, y;
            scanf("%d%d", &x, &y);
            punto paux;
            paux.x = x;
            paux.y = y;
            int val = posWithPoint(paux);
            int mask = 1 << val;
            b = b|mask;
        }
        int res = costo(b);
        printf("Case %d: %d\n", i, res);
    }
	return 0;
}

