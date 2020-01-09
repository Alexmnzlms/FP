#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	const int PORCENT_ERROR_FIJO = 5;
	const int PORCENT_ERROR_MOVIL = 7;
	double velocidad_captada, velocidad_imputada = 0,velocidad_maxima = 0;
	char tipo_radar;
	string matricula,matricula_maxima, terminador = "#";
	double app_pocent_error_fijo = (100 - PORCENT_ERROR_FIJO)/ 100.0;
	double app_pocent_error_movil = (100 - PORCENT_ERROR_MOVIL)/ 100.0;
	bool radar_fijo, vel_alta, es_mas_alta; 
	
	while(matricula != terminador ){
	cout << "\nIntroduzca la matricula:\t";
	cin >> matricula;
	if(matricula != terminador){
		cout << "Introduzca la velocidad capatda:\t";
		cin >> velocidad_captada;
		cout << "Introduzca el tipo de radar: fijo (F) o movil (M)\t";
		cin >> tipo_radar;
		cout << '\n';
		
		radar_fijo = (tipo_radar == 'F');
		vel_alta = (velocidad_captada > 100.0);
	
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
		
		es_mas_alta = (velocidad_imputada >= velocidad_maxima);
		
		if(es_mas_alta){
			velocidad_maxima = velocidad_imputada;
			matricula_maxima = matricula;
		}
		
		cout << velocidad_imputada << '\n';
		}
		else{
			cout << '\n' << matricula_maxima << '\t' << velocidad_maxima;
		}
	}
}
