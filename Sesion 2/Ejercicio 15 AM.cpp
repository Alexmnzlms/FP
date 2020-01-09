/*
	Programa que lee dos latitudes y dos longitudes y aplica una formula
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){	
	double const PI = 6 * asin(0.5);
	double grados_lat1, grados_lon1, grados_lat2, grados_lon2; 
	double latitud_1, longitud_1, latitud_2, longitud_2, variable_a; 
	double grados_to_radianes, seno_lat_cuadrado, seno_lon_cuadrado;
	
	grados_to_radianes = (PI/180);
	
	cout << "Introduzca latitud y longitud: ";
	cin >> grados_lat1;
	cin >> grados_lon1;
	
	cout << "Introduzca latitud y longitud: ";
	cin >> grados_lat2;
	cin >> grados_lon2;
	
	latitud_1 = grados_lat1 * grados_to_radianes;
	latitud_2 = grados_lat2 * grados_to_radianes;
	longitud_1 = grados_lon1 * grados_to_radianes;
	longitud_2 = grados_lon2 * grados_to_radianes;
	
	seno_lat_cuadrado = pow( sin( 1/2.0 * (latitud_2 - latitud_1) ) , 2 ) ;
	seno_lon_cuadrado = pow( sin( 1/2.0 * (longitud_2 - longitud_1) ) , 2 );
	
	variable_a = seno_lat_cuadrado + cos(latitud_1) * cos(latitud_2) * seno_lon_cuadrado;
	
	cout << '\n' << "La a vale: " << variable_a;
}
