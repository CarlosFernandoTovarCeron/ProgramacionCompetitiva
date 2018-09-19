#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

char letras[4] = {'A', 'C', 'G', 'T'};

int n, m;

map <string, bool> mp;

void t(string palabra, int pos, int hechas){
	//cout << pos << " " << hechas << endl;
	if(hechas==m or pos==n){
		mp[palabra] = true;
		return;
	}

	for(int i=0; i<4; i++){
		string aux(palabra);
		aux[pos] = letras[i];
		t(aux, pos+1, hechas+1);
	}
	
	t(palabra, pos+1, hechas);

}


int main(){

//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int casos;
	cin >> casos;

	while(casos--){
		cin >> n >> m;
		string dna;
		cin >> dna;
		t(dna, 0, 0);

		map <string, bool>::iterator it;
		cout << mp.size() << endl;
		for(it=mp.begin(); it!=mp.end(); ++it){
			cout << it->first << endl;
		}

		mp.clear();
	}

}
