
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define INF 100000000

int p[100];
int dp[55][55][55][55];

int c(int j, int k, int mi, int ma){
	if(j==0){
		if(k==0){
			return abs(p[mi] - p[ma]);
		}else{
			return INF;
		}
	}else{

		if(dp[j][k][mi][ma]!=-1) return dp[j][k][mi][ma];

		int nmi = mi;
		int nma = ma;
		if(p[j] < p[mi]) nmi = j;
		if(p[j] > p[ma]) nma = j;

		int res = min(c(j-1, k-1, nmi, nma),
				c(j-1, k, mi, ma));

		dp[j][k][mi][ma] = res;

		return res;
	}
}

int main() {
	p[99] = INF;
	p[98] = -INF;
	memset(dp, -1, sizeof(dp));
	int n, m;
	cin >> n >> m;

	for(int i=1; i<=m; i++){
		int aux; cin >> aux;
		p[i] = aux;
	}

	cout << c(m, n, 99, 98) << endl;

	return 0;
}
