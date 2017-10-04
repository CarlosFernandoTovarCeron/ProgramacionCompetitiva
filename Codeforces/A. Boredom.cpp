
#include <iostream>
#include <cstring>

typedef long long ll;

using namespace std;

ll numbers[100007];
ll dp[100007];

ll c(ll j){
	if(j==0) return 0;

	if(dp[j]!=-1) return dp[j];
	ll res = max(c(j-1), c(j-2) + j*numbers[j]);
	dp[j] = res;
	return res;
}

int main() {
	ll n;
	cin >> n;
	memset(numbers, 0, sizeof(numbers));
	memset(dp, -1, sizeof(dp));

	ll maximo = -1;
	for(ll i=1; i<=n; i++){
		ll aux; cin >> aux;
		maximo = max(aux, maximo);
		numbers[aux]++;
	}

	cout << c(maximo) << endl;
	return 0;
}
