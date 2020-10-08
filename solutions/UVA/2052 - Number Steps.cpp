#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++){
		int x, y;
		cin >> x >> y;
	
		int res = -1;
		if(x == 0 and y == 0){
			res = 0;
		}else if(x == 1 and y == 1){
			res = 1;
		}else{
			int t = x%2==0 ? x*2-2 : x*2-3;
			if(x==y){
				res = t + 2;
			}else if(y == x-2){
				res = t;
			}
			
		}
		
		if(res!=-1){
			cout << res << endl;
		}else{
			cout << "No Number" << endl;
		}
		
	}
	return 0;
}
