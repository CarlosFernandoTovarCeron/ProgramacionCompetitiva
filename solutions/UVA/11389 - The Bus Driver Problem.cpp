#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n, d, r;
    while(true){
        cin >> n >> d >> r;
        if(n==0 and d==0 and r==0) break;
        vector <int> m;
        vector <int> t;
        for(int i=0; i<n; i++){
            int aux; cin >> aux;
            m.push_back(aux);
        }
        for(int i=0; i<n; i++){
            int aux; cin >> aux;
            t.push_back(aux);
        }
        sort(m.begin(), m.end());
        sort(t.begin(), t.end());
        
        int j=n-1; int total = 0;
        for(int i=0; i<n; i++){
            if(m[i]+t[j]>d)
                total+=abs(m[i]+t[j] - d)*r;
            j--;
        }
        cout << total << endl;

    }
	return 0;
}
