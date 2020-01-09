/*
   Programa para la obtencion de pi a traves del arco-seno
*/

#include <iostream>   
#include <cmath>      
using namespace std;

int main(){               
   double arcoseno;         
   double pi;              
   
   arcoseno=0.5;

   pi= 6*asin(arcoseno); 
   
   cout << "\nPi vale: " << pi;
}					
