/*
   Programa para efectuar una conversion de grados a radianes
*/

#include <iostream>   
#include <cmath>      
using namespace std;

int main(){               
   double radianes_1, radianes_2;          
   double grados_1, grados_2;         
   double pi;

   cout << "Introduzca los grados: ";
   cin >> grados_1;
   cin >> grados_2;
   
   pi=6*asin(0.5);
   
   radianes_1 = grados_1 * (pi/180);
   radianes_2 = grados_2 * (pi/180);
   
   cout << "\n" << grados_1 << " grados equivalen a: " << radianes_1 << " radianes"	;
   cout << "\n" << grados_2 << " grados equivalen a: " << radianes_2 << " radianes"	;
}
