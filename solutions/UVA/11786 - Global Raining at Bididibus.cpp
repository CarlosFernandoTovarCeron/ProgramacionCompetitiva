#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    map<int, vector<int> >::iterator it;
    int n, current, minimum;
    double area1, area2;
    char symbol;
    int numbers[10005];
    map<int, vector<int> > equals;
    string symbols;

    cin >> n;
    
    for(int t=0; t<n; t++) {
        cin >> symbols;
        current = 0;
        minimum = 10005;
        for(int j=0; j<symbols.size(); j++) {
            symbol = symbols[j];
            if(symbol == '/') {
                current = current + 1;
            }
            else if(symbol == '\\') {
                current = current - 1;
            }

            minimum = min(minimum, current);
            numbers[j+1] = current;
        }
        for(int j=1; j<=symbols.size(); j++) {
            numbers[j] = numbers[j] - minimum;
        }

        if(symbols[0] == '/') {
            numbers[0] = numbers[1] - 1;
        }else if(symbols[0] == '\\') {
            numbers[0] = numbers[1] + 1;
        }else{
            numbers[0] = numbers[1];
        }


        for(int i=0; i<=symbols.size(); i++) {
            int number = numbers[i];
            auto iter = equals.find(number);

            if (iter == equals.end() ) {
                equals[number] = vector<int>();
            }
                
            equals[number].push_back(i);
        }

        area2 = 0;
        for(int i=0; i<=symbols.size(); i++) {
            if (numbers[i] != numbers[i+1])
                area2 = area2 + max(numbers[i], numbers[i+1]) - 0.5;
            else
                area2 = area2 + numbers[i];
        }


        for ( it = equals.begin(); it != equals.end(); it++ ) {
            int key = it->first;
            for(int k=0; k<equals[key].size()-1; k++) {
                int i = equals[key][k];
                int j = equals[key][k+1];
    
                int* maximum = max_element(numbers+i, numbers+j);
                if(*maximum <= key) {
                    for(int l=i; l<=j; l++) {
                        numbers[l] = key;
                    }
                }

            }
        }

        area1 = 0;
        for(int i=0; i<=symbols.size(); i++) {
            if (numbers[i] != numbers[i+1])
                area1 = area1 + max(numbers[i], numbers[i+1]) - 0.5;
            else
                area1 = area1 + numbers[i];
        }
    
        int res = area1-area2;
    
        cout << res << endl;
        equals.clear();
    
    }
    return 0;
}
