#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

#define INF 1000000000

int S;
int Q;
vector <string> q;
vector <string> s;

int dp[105][1005];

int c(int i, int j){
	if(j==-1) return 0;
	
	if(s[i]==q[j]) return INF;
	
	if(dp[i][j]!=-1){
		return dp[i][j];
	}

	int minimum = INF;
	for(int iaux=0; iaux<S; iaux++){
		int sum = i!=iaux;
		minimum = min(minimum, c(iaux, j-1) + sum);
	}
	
	dp[i][j] = minimum;
	
	return minimum;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n;
	cin >> n;	

	for(int i=0; i<n; i++){
		memset(dp, -1, sizeof(dp));
		cin >> S;
		string inutil = "";
		getline(cin, inutil);
		for(int j=0; j<S; j++){
			string search = "";
			getline(cin, search);
			s.push_back(search);
		}
		
		cin >> Q;
		getline(cin, inutil);
		for(int j=0; j<Q; j++){
			string query;
			getline(cin, query);
			q.push_back(query);
		}

		
		int minimum = INF;
		for(int j=0; j<S; j++){
			minimum = min(minimum, c(j, Q-1));
		}
		
		s.clear();
		q.clear();
		cout << "Case #" << i+1 << ": ";
		cout << minimum << endl;
	}
}
