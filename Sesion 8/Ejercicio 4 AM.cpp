/*
	Programa que replica el sistema D'Hondt
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int const MAX = 10;
	int votos[MAX];
	int escanios[MAX];
	int num_partidos, num_escanios, max_division, division, partido_con_escano, contador;
	
	cout << "Introduzca NUMERO DE ESCANOS, NUMERO DE PARTIDOS, VOTOS DE CADA PARTIDO EN ORDEN:\t";
	cin >> num_escanios;
	cin >> num_partidos;
	for(int contador = 0; contador < num_partidos; contador++){
		cin >> votos[contador];
		escanios[contador] = 1;
	}
	for(num_escanios; num_escanios > 0; num_escanios--){
		max_division = 0;
		for(contador = 0; contador < num_partidos; contador++){
			division = votos[contador]/escanios[contador];
			if(division > max_division){
				max_division = division;
				partido_con_escano = contador;
			}
		}
		escanios[partido_con_escano] = escanios[partido_con_escano]+ 1;
	}
	
	for(contador = 0; contador < num_partidos; contador++){
		cout << escanios[contador] - 1 << '\t';	
	}
}
