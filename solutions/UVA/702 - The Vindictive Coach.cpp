#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

typedef long long ll;

ll dp[30][30][3];

ll c(int menores, int mayores, bool m){
	
	if(menores == 0 and mayores == 0) return 1;
	
	if(dp[menores][mayores][(int)m]!=-1){
		return dp[menores][mayores][(int) m];
	}
		
	if(m == false){
		ll total = 0;
		for(int e=1; e<=menores; e++){
			total += c(e-1, menores-e+mayores, true);
		}
		dp[menores][mayores][(int) m] = total;
		return total;
	}else{
		ll total = 0;
		for(int e=1; e<=mayores; e++){
			total += c(menores+e-1, mayores - e, false);
		}
		dp[menores][mayores][(int) m] = total;
		return total;
	}
}

int main(int argc, char** argv) {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, g;
	memset(dp, -1, sizeof(dp));
	while(cin >> n >> g){
		if(g==1){
		    bool f = true;
			for(int e=2; e<=n; e++){
				ll res = c(e-2, n-e, false);
				if(res!=0){
					cout << res << endl;
					f = false;
					break;
				}
			}
			if(f) cout << 1 << endl;
		}else{
			cout << c(g-1, n-g, false) << endl;
		}
	}
	
	
	return 0;
}
