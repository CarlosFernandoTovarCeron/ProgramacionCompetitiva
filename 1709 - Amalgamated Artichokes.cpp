#include <bits/stdc++.h>

using namespace std;

double getPrice(int p, int a, int b, int c, int d, int k) {
    return p * (sin(a*k + b) + cos(c*k+d) + 2);
}

int main() {

    int p, a, b, c, d, n, k;
    double ret, reference, previous, price;

    while(scanf("%d %d %d %d %d", &p, &a, &b, &c, &d) == 5) {
        scanf("%d", &n);
        ret = 0.0;
        reference = getPrice(p, a, b, c, d, 1);
        previous = reference;
        for(k=2; k<=n; k++) {
            price = getPrice(p, a, b, c, d, k);
            if(price < previous) {
                ret = max(ret, reference - price);
            }else{
                reference = price;
                previous = price;
            }
        }

        printf("%.8lf\n", ret);
    }

    return 0;
}
