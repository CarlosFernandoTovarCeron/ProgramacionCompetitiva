#include <stdio.h>

int l[25];
int n, perimetro;
int dp[(1<<20) + 1];


int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int casos;
    scanf("%d", &casos);
    while(casos--){
        
        scanf("%d", &n);

        perimetro = 0;
        for(int i=0; i<n; i++){
            int aux;
            scanf("%d", &aux);
            l[i] = aux;
            perimetro += aux;
        }
        
        if(perimetro%4==0){
            dp[(1<<n) - 1] = true;
            int perimetrosobrecuatro = perimetro/4;
            for(int b=(1<<n) - 2; b>=0; b--){
                int suma = 0;
                for(int i=0; i<n; i++){
                    int mask = 1 << i;
                    if(b&mask){
                        suma+=l[i];
                    }
                }

                bool res = false;
                for(int i=0; i<n; i++){
                    if(res==true) break;
                    int mask = 1 << i;
                    if(!(b&mask)){
                        int cb = b;
                        cb = cb|mask;
                        if(suma<perimetrosobrecuatro){
                            if(suma+l[i]==perimetrosobrecuatro or suma+l[i]<perimetrosobrecuatro){
                                res = res or dp[cb];
                            }
                        }else if(suma==perimetro/4){
                            if(suma+l[i]==2*perimetrosobrecuatro or suma+l[i]<2*perimetrosobrecuatro){
                                res = res or dp[cb];
                            }
                        }else if(suma<(2*perimetro)/4){
                            if(suma+l[i]==2*perimetrosobrecuatro or suma+l[i]<2*perimetrosobrecuatro){
                                res = res or dp[cb];
                            }

                        }else if(suma==2*perimetrosobrecuatro){
                            if(suma+l[i]==3*perimetrosobrecuatro or suma+l[i]<3*perimetrosobrecuatro){
                                res = res or dp[cb];
                            }
                        }else if(suma<3*perimetrosobrecuatro){
                            if(suma+l[i]==3*perimetrosobrecuatro or suma+l[i]<3*perimetrosobrecuatro){
                                res = res or dp[cb];
                            }
                        }else if(suma==3*perimetrosobrecuatro){
                            if(suma+l[i]==4*perimetrosobrecuatro or suma+l[i]<4*perimetrosobrecuatro){
                                res = res or dp[cb];;
                            }
                        }else if(suma<(4*perimetro)/4){
                            if(suma+l[i]==4*perimetrosobrecuatro or suma+l[i]<4*perimetrosobrecuatro){
                                res = res or dp[cb];
                            }
                        }
                    }
                }

                dp[b] = res;
            }
        
            bool res = dp[0];
            if(res){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }else{
                printf("no\n");
        }

        
    }
    return 0;
}
