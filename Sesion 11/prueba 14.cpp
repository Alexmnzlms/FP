#include <iostream>

using namespace std;


int main(){
	
	string tipo_dato;
	
	double valor;
	
	while(true){
		
		cin >> valor;
		
		cin >> tipo_dato;
		
		if(tipo_dato == "latitud"){
			if(valor >= -90 && valor <= 90){
				cout << "si";
			}
		}
		else{
			if(tipo_dato == "longitud"){
				if(valor >= -180 && valor <= 180){
					cout << "si";
				}
			}
			else{
				if(tipo_dato == "altura"){
					if(valor >= -423 && valor <= 8848){
						cout << "si";
					}
				}
			}
		}
	}
}
