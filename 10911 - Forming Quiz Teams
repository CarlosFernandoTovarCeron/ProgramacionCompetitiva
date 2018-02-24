//con memo, intentar con bitmask

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int x[20];
int y[20];

int t, casos=1;
map <string, double> mymap;

double e(double x1, double y1, double x2, double y2){
	return hypot(x1-x2,y1-y2);
}

double c(string estado){
	int cero = -1;
	for(int i=0; i<t*2; i++){
		if(estado[i] == '0'){
			cero = i;
			break;
		}
	}

	if(cero==-1){
		return 0.0;
	}else{
		map <string, double>::iterator it;
		it = mymap.find(estado);
		if(it!=mymap.end()){
			return mymap[estado];
		}

		double minimo = 1000000000.0;
		for(int i=0; i<t*2; i++){
			if(i!=cero and estado[i]=='0'){
				string copia = estado;
				copia[cero] = '1';
				copia[i] = '1';
				
				double distancia = e(x[cero], y[cero], x[i], y[i]);
				double nodo = c(copia);
				mymap[copia] = nodo;
				nodo+=distancia;
				if(nodo < minimo){
					minimo = nodo;
				}
			}
		}
		mymap[estado] = minimo;
		return minimo;
	}

}

int main(){

//	freopen("inquiz", "r", stdin);
//	freopen("outquiz", "w", stdout);
	while(true){
		cin >> t;
		if(t==0) break;
		string first = "";
		for(int i=0; i<2*t; i++){
			string nada;
			cin >> nada;
			double auxx, auxy;
			cin >> auxx >> auxy;
			x[i] = auxx;
			y[i] = auxy;
			first = first + "0";
		}
		cout << setprecision(2);
		cout << fixed;
		cout << "Case " << casos << ": " << c(first) << endl;
		casos++;
		mymap.clear();
	}
	
}




/*

Sin carrear la respuesta, sin memo

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int x[20];
int y[20];

int t, casos=1;

double e(double x1, double y1, double x2, double y2){
	return hypot(x1-x2,y1-y2);
}

double c(string estado){
	int cero = -1;
	for(int i=0; i<t*2; i++){
		if(estado[i] == '0'){
			cero = i;
			break;
		}
	}

	if(cero==-1){
		return 0.0;
	}else{
		double minimo = 1000000000.0;
		for(int i=0; i<t*2; i++){
			if(i!=cero and estado[i]=='0'){
				string copia = estado;
				copia[cero] = '1';
				copia[i] = '1';
				double nodo = e(x[cero], y[cero], x[i], y[i]) + c(copia);
				if(nodo < minimo){
					minimo = nodo;
				}
			}
		}
		return minimo;
	}

}

int main(){

	freopen("inquiz", "r", stdin);
	freopen("outquiz", "w", stdout);
	while(true){
		cin >> t;
		if(t==0) break;
		string first = "";
		for(int i=0; i<2*t; i++){
			string nada;
			cin >> nada;
			double auxx, auxy;
			cin >> auxx >> auxy;
			x[i] = auxx;
			y[i] = auxy;
			first = first + "0";
		}
		cout << setprecision(2);
		cout << fixed;
		cout << "Case " << casos << ": " << c(first) << endl;
		casos++;
	}
	
}

*/

/*

Carreando la respuesta, sin memo

#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int x[20];
int y[20];

int t, casos=1;

double e(double x1, double y1, double x2, double y2){
	return hypot(x1-x2,y1-y2);
}

double c(string estado, double total){
	int cero = -1;
	for(int i=0; i<t*2; i++){
		if(estado[i] == '0'){
			cero = i;
			break;
		}
	}

	if(cero==-1){
		return total;
	}else{
		double minimo = 1000000000.0;
		for(int i=0; i<t*2; i++){
			if(i!=cero and estado[i]=='0'){
				string copia = estado;
				copia[cero] = '1';
				copia[i] = '1';
				double nodo = c(copia, total + e(x[cero], y[cero], x[i], y[i]));
				if(nodo < minimo){
					minimo = nodo;
				}
			}
		}
		return minimo;
	}

}

int main(){

	freopen("inquiz", "r", stdin);
	freopen("outquiz", "w", stdout);
	while(true){
		cin >> t;
		if(t==0) break;
		string first = "";
		for(int i=0; i<2*t; i++){
			string nada;
			cin >> nada;
			double auxx, auxy;
			cin >> auxx >> auxy;
			x[i] = auxx;
			y[i] = auxy;
			first = first + "0";
		}
		cout << setprecision(2);
		cout << fixed;
		cout << "Case " << casos << ": " << c(first, 0.0) << endl;
		casos++;
	}
	
}*/
