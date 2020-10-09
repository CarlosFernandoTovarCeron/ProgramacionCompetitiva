#include <iostream>
#include <cstdio>
#include <string>
#include <utility> 
#include <vector> 
#include <algorithm>

using namespace std;

int p[15][15];
int n, m;

vector< pair<int, int> > move(vector< pair<int, int> > coords, int i, int j) {
    int i_inc = i - coords[0].first;
    int j_inc = j - coords[0].second;
    vector< pair<int, int> > res;
    for(int k=0; k<coords.size(); k++) {
        pair<int, int> p;
        p.first =  coords[k].first + i_inc;
        p.second = coords[k].second + j_inc;
        if(!(p.first>=0 && p.first<n && p.second>=0 && p.second<n)) {
            return vector< pair<int, int> >();
        }else{
            res.push_back(p);
        }
    }
    return res;
}

int main() {
    while(true) {
        cin >> n >> m;

        if(n==0 && m==0) {
            break;
        }

        vector< pair<int, int> > coords_a;
        vector< pair<int, int> > coords_b;

        for(int i=0; i<n; i++) {
            string l;
            cin >> l;
            for(int j=0; j<n; j++) {
                if(l[j] == '*') {
                    pair<int,int> p;
                    p.first = i;
                    p.second = j;
                    coords_a.push_back(p);
                }
            }
        }

        for(int i=0; i<m; i++) {
            string l;
            cin >> l;
            for(int j=0; j<m; j++) {
                if(l[j] == '*') {
                    pair<int,int> p;
                    p.first = i;
                    p.second = j;
                    coords_b.push_back(p);
                }
            }
        }

        sort(coords_a.begin(), coords_a.end());

        bool res = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                vector< pair<int, int> > first = move(coords_b, i, j);
                if(!first.size()){
                    continue;
                }
                for(int k=0; k<n; k++) {
                    for(int l=0; l<n; l++) {
                        vector< pair<int, int> > second = move(coords_b, k, l);
                        if(!second.size()){
                            continue;
                        }
                        vector< pair<int, int> > firstsecond = first;
                        firstsecond.insert(firstsecond.end(), second.begin(), second.end());
                        sort(firstsecond.begin(), firstsecond.end());
                        if(firstsecond == coords_a) {
                            res = true;
                        }
                    }
                }
            }
        }

        cout << res << endl;

    }

    return 0;
}
