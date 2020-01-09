//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Pir�mide y Cuadrado de n�meros

/*
   Cree un programa que ofrezca en pantalla la siguiente salida:
   1 2 3 4 5 6
   2 3 4 5 6
   3 4 5 6
   4 5 6
   5 6
   6

   Cree un programa que ofrezca en pantalla la siguiente salida:
   1 2 3 4 5 6
   2 3 4 5 6 7
   3 4 5 6 7 8
   4 5 6 7 8 9
   5 6 7 8 9 10
   6 7 8 9 10 11

   Modifique los dos ejercicios anteriores para que 
   se lea desde teclado el valor inicial y el n�mero de filas a imprimir. 
   En los ejemplos anteriores, el valor inicial era 1 y se imprim�an un 
   total de 6 filas.
   
   
   Ejemplo con inicio = 4 y n�mero de filas = 6:

   4 5 6 7 8 9
   5 6 7 8 9
   6 7 8 9
   7 8 9
   8 9
   9
   
   4 5 6 7 8 9
   5 6 7 8 9 10
   6 7 8 9 10 11
   7 8 9 10 11 12
   8 9 10 11 12 13
   9 10 11 12 13 14
*/

#include <iostream>
using namespace std;

int main(){
   int inicio, i, j, ultimo, ultimo_de_fila, fila_ultima;
   int numero_filas;

   /*
      Algoritmo (Imprimir pir�mide de n�meros):
      
         Calcular la �ltima fila a imprimir, que tambi�n
         ser� el �ltimo valor de todas las filas -ultimo-

         Recorrer todos los enteros -i- entre inicio y ultimo
            Recorrer todos los enteros -j- entre i y ultimo
               Imprimir j
   */
         
   /*
      Compruebe que funciona correctamente cuando numero_filas es un 
      valor extremo como 1 o 0.
   */   
   
   cout << "Pir�mide y Cuadrado de n�meros\n\n";
   
   cout << "Introduzca el valor inicial\n";
   cin >> inicio;
   
   do{
      cout << "\nIntroduzca el n�mero de filas\n";
      cin >> numero_filas;
   }while (numero_filas < 0);
   
   cout << "\n\n";
      
   ultimo = inicio + numero_filas - 1;

   for (i = inicio ; i <= ultimo ; i++){
      for (j = i ; j <= ultimo ; j++)
         cout << j << " ";

      cout << "\n";
   }

   cout << "\n\n";

   /*
      Algoritmo (Imprimir cuadrado de n�meros):
      
         Calcular la �ltima fila a imprimir -fila_ultima-

         Recorrer tadas las filas -i- entre inicio y fila_ultima
            Calcular el �ndice �ltimo de la fila actual -ultimo_de_fila- 
            Recorrer todos los enteros -j- entre i y ultimo_de_fila
               Imprimir j
   */
   
   fila_ultima = inicio + numero_filas - 1;

   for (i = inicio ; i <= fila_ultima ; i++){
      ultimo_de_fila = i + numero_filas - 1;

      for (j = i ; j <= ultimo_de_fila ; j++)
         cout << j << " ";

      cout << "\n";
   }
}
