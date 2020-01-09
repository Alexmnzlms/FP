#include <iostream>

using namespace std;

class Dinero{
private:
   int euros;
   int centimos;

   bool CifraAIngresarCorrecta(int euros_a_ingresar, int centimos_a_ingresar){
      if (euros_a_ingresar >= 0 && centimos_a_ingresar > 0)
         return true;
      else
         return false;
   }
   void PasarCentimosAEuros(){
      euros = euros + (centimos / 100);
      centimos = centimos % 100;
   }
public:
   Dinero()
      :euros(0),
       centimos(0)
   {
   }
   void Ingresar(int euros_a_ingresar, int centimos_a_ingresar){
      if( CifraAIngresarCorrecta(euros_a_ingresar, centimos_a_ingresar) ){
         euros = euros + euros_a_ingresar;
         centimos = centimos + centimos_a_ingresar;
         PasarCentimosAEuros();
      }
   }
   void Sumale(Dinero otra_cuenta){
      Ingresar(otra_cuenta.Euros(),otra_cuenta.Centimos());
   }
   int Euros(){
      return euros;
   }
   int Centimos(){
      return centimos;
   }
};

int main(){
   Dinero cuenta_uno, cuenta_dos;
   int euros, centimos;

   cout << "Introuzca los euros de la cuenta 1:";
   cin >> euros;
   cout << "Introuzca los centimos de la cuenta 1:";
   cin >> centimos;

   cuenta_uno.Ingresar(euros,centimos);

   cout << "Introuzca los euros de la cuenta 2:";
   cin >> euros;
   cout << "Introuzca los centimos de la cuenta 2:";
   cin >> centimos;
   cuenta_dos.Ingresar(euros, centimos);

   Dinero cuenta_suma(cuenta_uno);

   cuenta_suma.Sumale(cuenta_dos);

   cout << "\nLa suma de las cuentas es \n\n" << cuenta_suma.Euros() << "\t" << cuenta_suma.Centimos();
}
