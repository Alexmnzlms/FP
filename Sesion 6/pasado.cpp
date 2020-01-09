#include <iostream>
#include <cmath>
using namespace std;

int main(){
   int dos_i_mas_uno = 1, tope, contador = 1, signo = 1;
   double pi, serie, base_potencial;
   const double BASE_POTENCIAL_CONSTANTE = 1 / sqrt (3);
   do {
      cout << "\nIntroduce el tope de la serie: ";
      cin >> tope;
   } while (tope < 1 || tope > 100000);

   base_potencial = BASE_POTENCIAL_CONSTANTE;
   serie = base_potencial;
   while (contador <= tope){
      base_potencial = base_potencial * BASE_POTENCIAL_CONSTANTE * BASE_POTENCIAL_CONSTANTE;
      dos_i_mas_uno = dos_i_mas_uno + 2;
      signo = signo * -1;
      serie = serie + (signo * base_potencial / dos_i_mas_uno);
      contador++;
   }
   pi = serie * 6;

   cout.precision(15);
   cout << "\n\nEl número aproximado pi es: " << pi <<"\n\n";
}
