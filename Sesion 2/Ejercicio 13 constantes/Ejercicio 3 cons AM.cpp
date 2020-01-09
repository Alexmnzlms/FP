/*
   Programa para la obtencion de pi a traves del arco-seno
*/

#include <iostream>   
#include <cmath>      
using namespace std;

int main(){ 
	double const ARCOSENO = 0.5;
	double const PI = 6 * asin(ARCOSENO);                          

   cout << "\nPi vale: " << PI;
}					
