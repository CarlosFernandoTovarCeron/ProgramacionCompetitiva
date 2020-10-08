#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    int cont = 0;
    while(t--) {
        double l, w, d, kg;
        cin >> l >> w >> d >> kg;
        if((l <= 56 && w <= 45 && d <= 25 || l + d + w <= 125) && kg <= 7) {
            cont++;
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
    cout << cont << endl;
	return 0;
}

