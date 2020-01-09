#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class StringDeDouble{
private:
	
	double parte_derecha;
	double parte_izquierda;
	char separador;
	int numero_decimales;
	double numero_completo;
	
	double PotenciaEntera(int numero, int exponente){
	
	int potencia = numero;
	
	for(int i = 0; i < exponente - 1; i++){
		potencia = potencia * numero;
	}
	
	return potencia;
	}
	
	double Redondea(double decimal, int cifra_redondeo){
	
	decimal = decimal * PotenciaEntera(10, cifra_redondeo);
	decimal = round(decimal);
	decimal = decimal / PotenciaEntera(10, cifra_redondeo);
	
	return decimal;
	}
	
	string EliminaUltimos(string cadena, char borrar){
	
	while(cadena[cadena.size() - 1] == borrar){
		cadena.pop_back();
	}

	return cadena;
}

	int NumeroCifras(int numero){
		
		int cifras = 1;
		
		while(numero > 9){
			numero = numero / 10;
			cifras++;
		}
		
		return cifras;
	}
	
public:
	StringDeDouble()
		:StringDeDouble(0,0,0,',')
		{
		}
	
	StringDeDouble(int derecha, int izquierda, int cifra_decimal, char tipo_separador){
		double parte_izquierda_decimal;
		parte_derecha = derecha;
		parte_izquierda = izquierda;
		numero_decimales = cifra_decimal;
		separador = tipo_separador;
		parte_izquierda_decimal = parte_izquierda * (1 / PotenciaEntera(10, NumeroCifras(parte_izquierda)));
		numero_completo = parte_derecha + parte_izquierda_decimal;
		}

	string ObtenerString(){
		string formateado;
		double numero_redondeado;
		double dch, izq;
		numero_redondeado = Redondea(numero_completo, numero_decimales);
		dch = parte_derecha;
		izq = (numero_redondeado - dch) * PotenciaEntera(10, numero_decimales);
		
		formateado = 
		EliminaUltimos(EliminaUltimos(to_string(dch), '0'),'.') + separador
		+ EliminaUltimos(EliminaUltimos(to_string(izq), '0'),'.');
		
		return formateado;
	}
};


int main(){
	int dch, izq, decimales;
	char separa;
	
	cin >> dch;
	cin >> izq;
	cin >> decimales;
	cin >> separa;
	
	StringDeDouble numero_string(dch,izq,decimales,separa);

	cout << numero_string.ObtenerString();
}
