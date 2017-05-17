#include <cstring>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <vector>
#include <stdio.h>
#define INF 1000000000.0

using namespace std;

int k, n;
int l[105];
vector < pair <int, pair <int, double> > > pe;
double dp[105][100005];

double c(int i, int j){

    if(i<0)
        return 0;
        
    if(j<0)
        return INF;
        
    if(dp[i][j]>=0.0)
        return dp[i][j];
        
    double min = INF;
    int pos = distance(pe.begin(), lower_bound(pe.begin(),pe.end(), make_pair(l[i], make_pair(0, 0.0))));
    while(true){
        if(pos>=n){
            break;
        }
        if(pe[pos].first!=l[i]){
            break;
        }

        if(pe[pos].second.first<=j){
            double parte = pe[pos].second.second + c(i-1, pe[pos].second.first-1);
            if(parte<min)
                min = parte;
        }
        pos++;
    }
    
    dp[i][j] = min;
    return min;
}

int main() {
    while(true){
        scanf("%d %d", &k, &n);
        if(k==0 and n==0)
            break;
        memset(l, -1, sizeof(l));
        memset(dp, -1.0, sizeof(dp));
        pe.clear();
    
        for(int i=0; i<k; i++){
            int aux; scanf("%d", &aux);
            l[i] = aux;
        }
        for(int i=0; i<n; i++){
            int aux; scanf("%d", &aux);
            double precio; scanf("%lf", &precio);
            //e[i] = aux;
            //p[i] = precio;
            pe.push_back(make_pair(aux, make_pair(i, precio)));
        }
        sort(pe.begin(), pe.end());
        
        double res = c(k-1, n-1);
        if(res>100000000){
            printf("Impossible\n");
        }else{
            printf("%.2f\n", res);
        }
            
    }
	return 0;
}
