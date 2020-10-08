#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string useless, s;
    cin >> useless;
    cin >> useless;
    cin >> useless;
    cin >> s;
    cin >> useless;

    string res = "";
    for(int i=0; i<4*n; i=i+4) {
        bool first, second, last;
        first = s[i] == '*';
        second = s[i+1] == '*';
        last = s[i+2] == '*';
        if(first) {
            res = res + "2";
        }else if(second) {
            res = res + "1";
        }else if(last) {
            res = res + "3";
        }
    }

    cout << res << endl;

    return 0;
}
