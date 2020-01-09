/*
	Programa que leea la velocidad capatada por un radar y le aplique un porcentaje de error
	
*/

#include <iostream>

using namespace std;

int main(){

	const int PORCENT_ERROR_FIJO = 5;
	const int PORCENT_ERROR_MOVIL = 7;
	double velocidad_captada, velocidad_imputada = 0;
	char tipo_radar;
	double app_pocent_error_fijo = (100 - PORCENT_ERROR_FIJO)/ 100.0;
	double app_pocent_error_movil = (100 - PORCENT_ERROR_MOVIL)/ 100.0;
	
	cout << "Introduzca la velocidad capatda:\t";
	cin >> velocidad_captada;
	cout << "Introduzca el tipo de radar: fijo (F) o movil (M)\t";
	cin >> tipo_radar;
	
	bool radar_fijo = tipo_radar == 'F';
	bool vel_alta = velocidad_captada > 100.0;

	if(radar_fijo){
		if(vel_alta){
			velocidad_imputada = velocidad_captada * 	app_pocent_error_fijo;
		}
		else{
			velocidad_imputada = velocidad_captada - PORCENT_ERROR_FIJO;
		}
	}
	else{
		if(vel_alta){
			velocidad_imputada =velocidad_captada * 	app_pocent_error_movil;
		}
		else{
			velocidad_imputada = velocidad_captada - PORCENT_ERROR_MOVIL;
		}		
	}
	
	cout << velocidad_imputada;
}
