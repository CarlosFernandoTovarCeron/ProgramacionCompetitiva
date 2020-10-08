#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for(int c=0; c<t; c++) {
        int n;
        scanf("%d", &n);
        int ret = -150005;
        int current_max = -150005;
        for(int i=0; i<n; i++) {
            int v;
            scanf("%d", &v);
            ret = max(ret, current_max - v);
            current_max = max(current_max, v);
        }
        printf("%d\n", ret);
    }
    return 0;
}

