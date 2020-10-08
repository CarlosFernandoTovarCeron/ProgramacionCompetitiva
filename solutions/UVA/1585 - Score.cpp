#include <iostream>
#include <string>

using namespace std;

int main() {

    int t;
    cin >> t;

    for(int c=0; c<t; c++) {
        string s;
        cin >> s;

        int acu = 0;
        int cont = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == 'O') {
                cont = cont + 1;
            }else{
                cont = 0;
            }
            acu = acu + cont;
        }

        cout << acu << endl;
    }

	return 0;
}
