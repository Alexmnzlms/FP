/* Se ha construido una clase TablaTemperaturas
   para gestionar una gran cantidad de temperaturas de 10 ciudades diferentes
   en un tiempo de 24 horas.
   La clase proporciona los metodos para poder calcular la mayor de las menores
   temperaturas registradas */

#include <iostream>
#include <string>

using namespace std;

const int NUMERO_CIUDADES = 10, NUMERO_HORAS = 24;
	

struct Registro{
   double temperatura;
   int ciudad, hora;
};

class TablaTemperaturas{
private:
	

	double tabla[NUMERO_CIUDADES][NUMERO_HORAS];
	
	
public:

	double Valor(int ciudad, int hora){
		return tabla[ciudad][hora];
	}
	
	void Modifica(double temperatura, int ciudad, int hora){
		tabla[ciudad][hora] = temperatura;
	}
	
	int Minimo(int ciudad){
		int indice_min = 0, i;
		double minimo;
		minimo = tabla[ciudad][0];
		for(i = 0; i < NUMERO_HORAS; i++){
			if(tabla[ciudad][i] < minimo){
				minimo = tabla[ciudad][i];
				indice_min = i;
			}
		}
		return indice_min;
	}
	
   Registro Maximominimos(){
      double minimos[NUMERO_CIUDADES];
      double maximo;
      int indice_max = 0, i;
      Registro datos_maximo;

      for (i = 0 ; i < NUMERO_CIUDADES ; i++){
         minimos[i] = tabla[i][Minimo(i)];
      }
      maximo = minimos[0];

      for (i = 1 ; i < NUMERO_CIUDADES ; i++){
         if (minimos[i] > maximo){
            maximo = minimos[i];
            indice_max = i;
         }
      }

      datos_maximo.temperatura = maximo;
      datos_maximo.ciudad = indice_max;
      datos_maximo.hora = Minimo(indice_max);

      return datos_maximo;
   }
   
};

int main(){
 	TablaTemperaturas tabla_temperaturas;
   int fila, columna, ciudad, hora;
   double temperatura;
   Registro datos;

   for (fila = 0 ; fila < NUMERO_CIUDADES ; fila++){
      for (columna = 0 ; columna < NUMERO_HORAS ; columna++){
         cin >> temperatura;
         tabla_temperaturas.Modifica(temperatura, fila, columna);
      }
   }

   datos = tabla_temperaturas.Maximominimos();

   temperatura = datos.temperatura;
   hora = datos.hora;
   ciudad = datos.ciudad;

   cout << "\nTemperatura = " << temperatura << "\nCiudad = " << ciudad << "\nHora = " << hora << "\n\n";


}
