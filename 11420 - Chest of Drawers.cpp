#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll dp[2][70][70];
ll n, s;

ll c(int cabeza, int m, int seg){
    if(m<=0){
        if(seg==s)
            return 1;
        else
            return 0;
    }else{

    	if(dp[cabeza][m][seg]!=-1){
    		return dp[cabeza][m][seg];
    	}

    	ll actualL, actualU;
    	if(cabeza==1){
    		//cabeza locked
    		actualL = c(1, m-1, seg+1);
    		actualU = c(0, m-1, seg);

    	}else{
    		//cabeza unlocked
    		actualL = c(1, m-1, seg);
    		actualU = c(0, m-1, seg);
    	}
    	dp[cabeza][m][seg] = actualL + actualU;
    	return dp[cabeza][m][seg];
    }
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

    cin.tie(NULL);
   	ios_base::sync_with_stdio(false);
    while(true){
       	memset(dp, -1, sizeof(dp));
    	cin >> n >> s;
        if(n<0){
            break;
        }

        cout << c(1, n, 0) << endl;
    }
	return 0;
}
