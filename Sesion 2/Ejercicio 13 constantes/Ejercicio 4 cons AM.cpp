/*
   Programa para efectuar una conversion de grados a radianes
*/

#include <iostream>   
#include <cmath>      
using namespace std;

int main(){
	double const PI = 6 * asin(0.5);
	double grados_to_radianes;
   double radianes_1, radianes_2;          
   double grados_1, grados_2;   
	
	grados_to_radianes = (PI/180);      
   
   cout << "Introduzca los grados: ";
   cin >> grados_1;
   cin >> grados_2;
   
   
   
   radianes_1 = grados_1 * grados_to_radianes;
   radianes_2 = grados_2 * grados_to_radianes;
   
   cout << "\n" << grados_1 << " grados equivalen a: " << radianes_1 << " radianes"	;
   cout << "\n" << grados_2 << " grados equivalen a: " << radianes_2 << " radianes"	;
}
