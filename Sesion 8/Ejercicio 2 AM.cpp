/*
	Programa que comprueba si una fecha introducida es correcta
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	const int MAX_FECHAS = 100;
   int num_fechas_pedidas = 0;
   int dia;
   int mes;
   int anio;
   int dias_en_mes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
   string son_fechas_validas[MAX_FECHAS];
   bool salir;
   bool fecha_valida = false;
   bool es_bisiesto;

   cout << "Introduce el dia: ";
   cin >> dia;
   salir = dia < 0;


   while (!salir){
      cout << "Introduce el mes: ";
      cin >> mes;
      cout << "Introduce el año: ";
      cin >> anio;

      mes--;

      es_bisiesto = (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;

      if (mes >= 0 && mes <= 11){
         if ( mes == 1 && es_bisiesto ){
            dias_en_mes[1]++;
         }
         if (dia >= 1 && dia <= dias_en_mes[mes]){
            fecha_valida = true;
         }
         else{
            fecha_valida = false;
         }
      }
      else{
         fecha_valida = false;
      }

      if (fecha_valida)
         son_fechas_validas[num_fechas_pedidas] = "SI";
      else
         son_fechas_validas[num_fechas_pedidas] = "NO";

      num_fechas_pedidas++;

      cout << "Introduce el dia: ";
      cin >> dia;
      salir = dia < 0;
   }

   for (int i  = 0; i < num_fechas_pedidas; i++) {
      cout << son_fechas_validas[i] << " ";
   }
}
