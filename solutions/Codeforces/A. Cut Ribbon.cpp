
#include <iostream>
#include <cstring>

using namespace std;

#define inf 100000000
int n, a, b, c;

int dp[4100];

int costo(int size){

	if(size==0) return 0;
	if(size<a and size<b and size<c) return -inf;
	if(dp[size]!=-1) return dp[size];

	int uno=0, dos=0, tres=0;
	uno = 1 + costo(size-a);
	dos = 1 + costo(size-b);
	tres = 1 +  costo(size-c);

	int res = max(uno, max(dos, tres));
	dp[size] = res;
	return res;

}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> a >> b >> c;
	cout << costo(n) << endl;
	return 0;
}
