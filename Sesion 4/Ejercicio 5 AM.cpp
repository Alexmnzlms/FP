/*
Construya un programa que lea las coordenadas del primer punto (latitud, longitud y
altura), las del segundo e imprima en pantalla la distancia sobre plano y la distancia
real. Supondremos que las coordenadas de los puntos se introducen en grados, por
lo que habrá que pasarlas a radianes para poder aplicar las fórmulas
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	double grados_lon1,grados_lat1,grados_lon2,grados_lat2,lon1,lat1,lon2,lat2,senolat,senolon,variable_a,variable_c,altura_1,altura_2,distancia_plano,distancia_real,distancia_plano_alcuadrado,diferencia_altura,diferencia_altura_alcuadrado;
	const double PI = 6 * asin(0.5);
	const double CONVERSION_RADIANES = PI/180.0;
	const double RADIO_TIERRA = 6372797.560856;
	
	
	cout << "Introduzca la latitud, latitud y altura de la primera ubicacion: ";
	cin >> grados_lat1;
	cin >> grados_lon1;
	cin >> altura_1;
	cout << "Introduzca la latitud, longitud y altura de la segunda ubicacion: ";
	cin >> grados_lat2;
	cin >> grados_lon2;
	cin >> altura_2;
	
	
	lon1 = grados_lon1 * CONVERSION_RADIANES;
	lat1 = grados_lat1 * CONVERSION_RADIANES;
	lon2 = grados_lon2 * CONVERSION_RADIANES;
	lat2 = grados_lat2 * CONVERSION_RADIANES;
	
	
	senolat = sin (0.5 * (lat2 - lat1));
	senolon = sin (0.5 * (lon2 - lon1));
	variable_a = pow(senolat,2.0) + cos(lat1) * cos(lat2) * pow (senolon,2.0);
	
		
	variable_c = 2 * asin(1);
	
	if (1 > sqrt(variable_a)){
		
		variable_c = 2 * asin(sqrt(variable_a));
	}
	
	distancia_plano = RADIO_TIERRA * variable_c;
	distancia_plano_alcuadrado = distancia_plano * distancia_plano;
	diferencia_altura = altura_1 - altura_2;
	diferencia_altura_alcuadrado = diferencia_altura * diferencia_altura;
	distancia_real = sqrt(diferencia_altura_alcuadrado + distancia_plano_alcuadrado);
	cout << fixed << "\nLa distancia en el plano entre ambos puntos es: " << distancia_plano << " y la distancia real: " << distancia_real;
}
	
