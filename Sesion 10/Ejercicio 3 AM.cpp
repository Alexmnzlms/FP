#include <iostream>

using namespace std;

// DEFINICION DE FUNCIONES

int LeeIntMayorIgualQue(int entero){ 
	int numero;
	cin >> numero;
	while(entero >= numero){
		cin >> numero;
	}
	return numero;
}//Devuelve un numero si es mayor que un entero

int LeeIntRango(int min, int max, string mensaje) {
   int a_leer;
   
   do{
      cout << mensaje;
      cin >> a_leer;
   }while (min > a_leer || max < a_leer);
   
   return a_leer;
}//Lee los extremos de un intervalo y acepta el numero si esta en el rango

/* 
FUNCION PRINCIPAL MAIN

Este progrmama lee un entero mayor que otro
*/

int main(){
	
	//VARIABLES
	
   const int TOTAL_A_INTRODUCIR = 3;
   long min, max, dato, suma;
   
   //SALIDA DE TEXTO
   
   cout << "Programa de prueba para la función LeeIntRango"
        << "\nIntroduzca el valor mínimo y el máximo"
        << "\nA continuación introduzca "
        << TOTAL_A_INTRODUCIR << " enteros en el rango anterior\n";
        
    //ENTRADA DE DATOS
    
   cin >> min;
   max = LeeIntMayorIgualQue(min);
   suma = 0;
   
   //COMPUTO
   
   for (int i = 0; i < TOTAL_A_INTRODUCIR; i++){
      dato = LeeIntRango(min, max, "");
      suma = suma + dato;
   }
	
	//sALIDA
	
   cout << "\n\nSuma total: " << suma;
}
