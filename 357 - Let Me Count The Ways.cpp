#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;
typedef  long long ll;

#define MAX 5
#define INF -1

ll deno[MAX] = {50, 25, 10, 5, 1};
ll dp[6][31000];

ll ways(ll type, ll m){
	if(m==0){
		return 1;
	}else if(m<0){
		return 0;
	}else if(type==MAX){
		return 0;
	}

	  if(dp[type][m]!=-1) return dp[type][m];

	  dp[type][m]=ways(type+1,m) + ways(type, m-deno[type]);

	  return dp[type][m];
}

int main() {

	memset(dp, INF, sizeof(dp));

	ll m;
	while(cin >> m){
		ll res = ways(0, m);
        if(res!=1) cout<<"There are "<<res<<" ways to produce "<<m<<" cents change."<<endl;
        else cout<<"There is only 1 way to produce "<<m<<" cents change."<<endl;
	}

	return 0;
}
