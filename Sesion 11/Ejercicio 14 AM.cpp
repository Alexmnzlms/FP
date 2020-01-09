#include <iostream>

using namespace std;

class CoordenadasGPS{
private:
	double latitud;
	double longitud;
	double altura;
	
	bool es_correcto(double valor, string tipo_dato){
		if(tipo_dato == "latitud")
			if(valor >= -90 && valor <= 90)
				return true;
		
		if(tipo_dato == "longitud")
			if(valor >= -180 && valor <= 180)
				return true;
			
		if(tipo_dato == "altura")
			if(valor >= -423 && valor <= 8848)
				return true;	
	}
	
	string EliminaUltimos(string cadena, char borrar){
		while(cadena[cadena.size() - 1] == borrar){
			cadena.pop_back();
		}
	
		return cadena;
	}
	
public:
	CoordenadasGPS()
		:latitud(0),
		 longitud(0),
		 altura(0)
	{
	}
	
	void SetLatitud(double valor_latitud){
		if(es_correcto(valor_latitud, "latitud"))
			latitud = valor_latitud;
	}
	
	void SetLongitud(double valor_longitud){
		if(es_correcto(valor_longitud, "longitud"))
			longitud = valor_longitud;
	}
	
	void SetAltura(double valor_altura){
		if(es_correcto(valor_altura, "altura"))
			altura = valor_altura;
	}
	
	string PrintCoordenadas(){
		string coordenadas;
		coordenadas = 
		EliminaUltimos(to_string(latitud), '0')  
		+ EliminaUltimos(to_string(longitud), '0') 
		+ EliminaUltimos(to_string(altura), '0');
		
		return coordenadas;
	}
};

int main(){
	CoordenadasGPS lugar;
	
	lugar.SetLatitud(181);
	lugar.SetLongitud(65);
	lugar.SetAltura(90);
	
	cout << lugar.PrintCoordenadas();
}
