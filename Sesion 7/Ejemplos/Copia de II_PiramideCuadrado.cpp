//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Pirámide y Cuadrado de números

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
   se lea desde teclado el valor inicial y el número de filas a imprimir. 
   En los ejemplos anteriores, el valor inicial era 1 y se imprimían un 
   total de 6 filas.
   
   
   Ejemplo con inicio = 4 y número de filas = 6:

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
      Algoritmo (Imprimir pirámide de números):
      
         Calcular la última fila a imprimir, que también
         será el último valor de todas las filas -ultimo-

         Recorrer todos los enteros -i- entre inicio y ultimo
            Recorrer todos los enteros -j- entre i y ultimo
               Imprimir j
   */
         
   /*
      Compruebe que funciona correctamente cuando numero_filas es un 
      valor extremo como 1 o 0.
   */   
   
   cout << "Pirámide y Cuadrado de números\n\n";
   
   cout << "Introduzca el valor inicial\n";
   cin >> inicio;
   
   do{
      cout << "\nIntroduzca el número de filas\n";
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
      Algoritmo (Imprimir cuadrado de números):
      
         Calcular la última fila a imprimir -fila_ultima-

         Recorrer tadas las filas -i- entre inicio y fila_ultima
            Calcular el índice último de la fila actual -ultimo_de_fila- 
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
