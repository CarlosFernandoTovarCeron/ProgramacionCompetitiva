//============================================================================
// Name        : Mark.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll p;
ll dp[75][75];


ll c(ll n, ll t){
	if(n==0 and t==0)
		return 1;

	if((n==0 and t!=0) or t<0)
		return 0;

	if(dp[n][t]!=-1){
		return dp[n][t];
	}

	ll restar = 0;
	ll total = 0;
	while(true){
		if((n-1)*p>t-p-restar){
			break;
		}else{
			total += c(n-1, t-p-restar);
		}
		restar++;
	}

	dp[n][t] = total;
	return total;
}

int main() {
	ll casos;
	cin >> casos;

	while(casos--){
		memset(dp, -1, sizeof(dp));
		ll n, t;
		cin >> n >> t >> p;
		cout << c(n, t) << endl;

	}

	return 0;
}
