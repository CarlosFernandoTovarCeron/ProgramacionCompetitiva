#include <stdio.h>
#define inf 100000

int c[31][301][2], ms[31], dp[31][301], ruta[31][301], t1, t2, n, nodo, minimo, i, aux, m, j, sitio, t;

void solve(int sitio, int t){
	if(sitio!=n-1){
		printf("%d ", ruta[sitio][t]);
		solve(sitio+1, t + ruta[sitio][t]);
	}else{
		printf("%d\n\n", ruta[sitio][t]);
	}
}


int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

    while(true){
        scanf("%d%d", &t1, &t2);
        if(!(t1 || t2)) break;
        scanf("%d", &n);
        for(i=0; i<n; i++){
            scanf("%d", &m);
            ms[i] = m;
            c[i][0][0] = 0;
            c[i][0][1] = 0;
            for(j=1; j<=m; j++){
                scanf("%d", &aux);
                c[i][j][0] = aux;
            }
            for(j=1; j<=m; j++){
                scanf("%d", &aux);
                c[i][j][1] = aux;
            }
        }
        
        
        for(i=0; i<=(t1+t2); i++){
        	dp[n][i] = inf;
		}
		
		dp[n][t1] = 0;

        for(sitio = n-1; sitio>=0; sitio--){
            for(t=0; t<=t1+t2; t++){
            	minimo = inf;
	            for(j=0; j<=ms[sitio]; j++){
	                nodo = c[sitio][ms[sitio]-j][1] + c[sitio][j][0] + dp[sitio+1][t+j];   
	                if(nodo<minimo){
	                    minimo = nodo;
	                    ruta[sitio][t] = j;
	                }
	            }
	            dp[sitio][t] = minimo;
			}
        }
        
		printf("%d\n", dp[0][0]);
		solve(0, 0);

    }
    
	return 0;
}
