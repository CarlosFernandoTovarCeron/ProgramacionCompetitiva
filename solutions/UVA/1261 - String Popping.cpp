#include <iostream>
#include <map>
#include <string>

using namespace std;

map <string, int> m;
map <string, int>::iterator it;

bool c(string & s){
    if(s=="") return true;
    
    it = m.find(s);
    if(it!=m.end()){
        return m[s];
    }
    
    bool f = false;
    char referencia = s[0];
    int i=0, j=0;
    for(int k=0; k<s.length(); k++){
        if(s[k]!=referencia){
            if(j-i+1>=2){
                string cs = s.substr(0, i);
                if(j+1<s.length()){
                    cs+= s.substr(j+1, s.length()-(j+1));
                }
                bool nodo = c(cs);
                m[cs] = nodo;
                f = f or nodo;
            }
            //cout << i << " " << j << endl;
            i = k;
            referencia = s[k];
        }
        j = k;
    }
    //cout << i << " " << j << endl;
    if(j-i+1>=2){
        string cs = s.substr(0, i);
        if(j+1<s.length()){
            cs+= s.substr(j+1, s.length()-(j+1));
        }
        bool nodo = c(cs);
        m[cs] = nodo;
        f = f or nodo;
    }
    
    m[s] = f;
    
    return f;
}

int main() {
    int casos;
    cin >> casos;
    while(casos--){
        string linea;
        cin >> linea;
        cout << c(linea) << endl;

    }
    
	return 0;
}
