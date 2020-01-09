#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class SecuenciaDoubles{
private:
	static const int NUMERO_DATOS = 24;
	double vector_doubles[NUMERO_DATOS];
	int total_utilizados;

public:
	SecuenciaDoubles()
	:total_utilizados(0)
	{
	}
	
	void Modifica(int pos, double dato){
		vector_doubles[pos] = dato;
	}
	
	void SetUtilizados(int numero){
		total_utilizados = numero;
	}
	
	int Minimo(){
		int indice_min = 0, i;
		double min;
		min = vector_doubles[0];
		for(i = 0; i < total_utilizados; i++){
			if(vector_doubles[i] < min){
				min = vector_doubles[i];
				indice_min = i;
			}
		}
		return indice_min;
	}
	
	double Valor( int pos){
		return vector_doubles[pos];
	}
	
};

struct Registro{
	int ciudad, hora;
};

class TablaTemperaturas{
private:
	static const int NUMERO_CIUDADES = 50;
	SecuenciaDoubles vector_objetos[NUMERO_CIUDADES];
	int total_utilizados;
	
public:
	TablaTemperaturas()
	:total_utilizados(0)
	{
	}

	SecuenciaDoubles Dato(int numero){
		return vector_objetos[numero];
	}
	
	void Aniade(int pos, SecuenciaDoubles datos){
		vector_objetos[pos] = datos;
		total_utilizados++;
	}
	
   Registro Maxminimos(){
      Registro datos;
      int i;
      int minimo[total_utilizados];
      int indice_max;
      double maximo;
      
      for(i = 0; i < total_utilizados; i++){
			minimo[i] = vector_objetos[i].Valor(vector_objetos[i].Minimo());
		}
		
		maximo = minimo[0];
		indice_max = 0;
		for(int j = 0; j < i; j++){
			if(maximo < minimo[j]){
				maximo = minimo[j];
				indice_max = j;
			}
		}
		
		datos.ciudad = indice_max;
		datos. hora = vector_objetos[indice_max].Minimo();
		
		return datos;
   }
   
};

int main(){
	const int TERMINADOR = -1;
	int horas;
	double temperatura;
	TablaTemperaturas tabla;
	SecuenciaDoubles temperaturas;
	int contador = 0;
	int contador_temp = 0;
	Registro maximos;
	
	cin >> horas;
	while (horas != TERMINADOR){
		temperaturas
		.SetUtilizados(horas);
		for(int i = 0; i < horas; i++){
 			cin >> temperatura;
			temperaturas.Modifica(contador_temp, temperatura);
			contador_temp++;
		}
		tabla.Aniade(contador, temperaturas);
		contador_temp = 0;
		contador++;
		cin >> horas;
	}
	maximos = tabla.Maxminimos();
	
	cout << "Ciudad: " << maximos.ciudad << "\n";
	cout << "Hora: " << maximos.hora << "\n";
	cout << "Temperatura: " << tabla.Dato(maximos.ciudad).Valor(maximos.hora)<< "\n";
	
}
