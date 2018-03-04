#include <iostream>
#include <vector>

using namespace std;

vector <string> iz, der, op;

int main(int argc, char** argv) {
	
	int casos;
	cin >> casos;
	while(casos--){
		iz.clear(); der.clear(); op.clear();
		
		for(int i = 0; i<3; i++){
			string aux; cin >> aux;
			iz.push_back(aux); cin >> aux;
			der.push_back(aux); cin >> aux;
			op.push_back(aux);
		}
		char cres;
		bool esl;
		for(int c='A'; c<='L'; c++){
			for(int l=0; l<=1; l++){
				bool ligera = l;
				
				bool consistente = true;
				for(int i=0; i<3; i++){
					int suma1 = 0, suma2 = 0;
					for(int j=0; j<iz[i].length(); j++){
						if(iz[i][j]!=c){
							suma1+=1;
						}else{
							suma1+= ligera ? 0 : 2;
						}
					}
					for(int j=0; j<der[i].length(); j++){
						if(der[i][j]!=c){
							suma2+=1;
						}else{
							suma2+= ligera ? 0 : 2;
						}
					}
					
					if(op[i]=="even"){
						consistente = consistente and (suma1==suma2);
					}else if(op[i]=="up"){
						consistente = consistente and (suma1>suma2);
					}else if(op[i]=="down"){
						consistente = consistente and (suma1<suma2);
					}
						
				}
				
				if(consistente){
					cres = c;
					esl = ligera;
				}
								
			}
		}
		
		if(esl){
			printf("%c is the counterfeit coin and it is light.\n", cres);
		}else{
			printf("%c is the counterfeit coin and it is heavy.\n", cres);
		}
		
		
	}
	
	return 0;
}
