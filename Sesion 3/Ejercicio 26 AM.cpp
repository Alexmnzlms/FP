///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//////////                                                            /////////
//////////	        Programa que comprueba diferentes                 /////////
//////////	   valores para ver si si son verdaderos o falsos  		 /////////
//////////                                                            /////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a_min = 'a';
	char letra;
	int edad, adivine, anio;
	bool es_minuscula, es_pop_inac, es_adivinado, es_bisiesto;

	
	cout << "Introduzca letra, edad, adivine, anio:\t";
	cin >> letra;
	cin >> edad;
	cin >> adivine;
	cin >> anio;
	
	es_minuscula = letra >= a_min;
	es_pop_inac = edad < 18 || edad > 65;
	es_adivinado = adivine >= 0 && adivine <= 100;
	es_bisiesto = (anio % 400) == 0;
	
	cout << es_minuscula <<'\t' << es_pop_inac << '\t' << es_adivinado << '\t' << es_bisiesto ;
}

