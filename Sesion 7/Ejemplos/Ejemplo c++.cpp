//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Gaussiana

/*   
Recupere la soluci�n del ejercicio 10 (funci�n gaussiana)
de la relaci�n de problemas I.
Se pide crear un men� principal para que el usuario pueda elegir
las siguientes opciones:

   Introducir Par�metros de la funci�n (esperanza y desviaci�n)
   Salir del programa
   
Si el usuario elige la opci�n de salir, el programa terminar�; si elige
la opci�n de introducir los par�metros, el programa leer� los
dos par�metros (esperanza y desviaci�n).

La media puede ser un valor cualquiera, p
ero la desviaci�n ha de ser un n�mero positivo.

A continuaci�n, el programa presentar� un men� con las siguientes opciones:

   Introducir rango de valores de abscisas
   Volver al men� anterior (el men� principal)

Si el usuario elige volver al men� anterior, el programa debe presentar el
primer men� (el de la introducci�n de los par�metros) Si el usuario elige
introducir los valores de abscisas, el programa le pedir� un valor minimo ,
un valor maximo (ha de ser mayor que minimo) y un incremento y mostrar�
el valor de la funci�n gaussiana en todos los valores de abscisa (x)
entre minimo y maximo a saltos de incremento , es decir,

   minimo, minimo + incremento , minimo + 2*incremento , ���,
   
hasta llegar, como mucho, a maximo .
Despu�s de mostrar los valores de la funci�n, el programa volver� al
men� de introducci�n del rango de valores de abscisas.
*/


#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

int main(){
   /*
      Como norma general no usaremos nombres de variables como x, y, etc.
      Hacemos una excepci�n en este programa ya que son nombres
      omnipresentes en Matem�ticas.
   */
   
   /*
   (P)ar�metros  -> [cin esperanza y desviaci�n] -> (R)ango -> [cin min, max, incremento] -> Resultados ->|
   (S)alir       <--------------------------------- (V)olver <--------------------------------------------|   
   */
   /*
   do{
     Mostrar Men� Ppal (Par�metros o Salir)
     Leer opcion_menu_ppal
     
     if opcion_ppal no es Salir
        Lectura de esperanza y desviaci�n
        
        do{
           Mostrar Men� (Rango o Volver)
           Leer opcion_menu_secundario
           
           if opcion_menu_secundario no es Volver
              Lectura de min, max e incremento
              Mostrar resultados
        }while (opcion_menu_secundario != 'V')
   }while (opcion_ppal != 'S')
   */       
   
   const double PI = 6 * asin(0.5);

   const char OPCION_INTRO_PARAMETROS  = 'P',
              OPCION_SALIR             = 'S',
              OPCION_INTRO_RANGO       = 'R',
              OPCION_VOLVER            = 'V';
   char opcion_menu_ppal, opcion_menu_secundario;
   bool eligio_salir_ppal, eligio_salir_secundario;
   bool es_correcta_opcion_ppal, es_correcta_opcion_secundario;
   double esperanza, desviacion, x, min_x, max_x, incremento;
   double y;                                
   double valor_tipificado, exponente;
   
   cout << "Gaussiana";
   
   do{
      cout << "\n\n---------------------\n" 
           << "Men� Principal\n\n"
           << "Par�metros\n"
           << "Salir\n";
      
      do{
         cout << "\nIntroduzca la opci�n (" << OPCION_INTRO_PARAMETROS 
              << "/" << OPCION_SALIR << ") ";
         cin >> opcion_menu_ppal;
         opcion_menu_ppal = toupper(opcion_menu_ppal);
         eligio_salir_ppal = opcion_menu_ppal == OPCION_SALIR;
         es_correcta_opcion_ppal = eligio_salir_ppal ||
                                   opcion_menu_ppal == OPCION_INTRO_PARAMETROS;
      }while (! es_correcta_opcion_ppal);
      
      if (! eligio_salir_ppal){
         cout << "\nIntroduzca el valor del par�metro 'esperanza': ";
         cin >> esperanza;
      
         do{
            cout << "\nIntroduzca el valor del par�metro 'desviacion'. "
                 << "Debe ser un n�mero positivo: ";
            cin >> desviacion;
         }while (desviacion < 0);
         
         do{
            cout << "\n\n" 
              << "Men� Secundario\n\n"
              << "Rango\n"
              << "Volver\n";
              
            do{
               cout << "\nIntroduzca la opci�n (" << OPCION_INTRO_RANGO 
                    << "/" << OPCION_VOLVER << ") ";
               cin >> opcion_menu_secundario;
               opcion_menu_secundario = toupper(opcion_menu_secundario);
               eligio_salir_secundario = opcion_menu_secundario == OPCION_VOLVER;
               es_correcta_opcion_secundario  = eligio_salir_secundario ||
                                         opcion_menu_secundario == OPCION_INTRO_RANGO;
            }while (! es_correcta_opcion_secundario);                                               
            
            if (! eligio_salir_secundario){
               cout << "\nIntroduzca el valor m�nimo de la abscisa: ";
               cin >> min_x;
               
               do{
                  cout << "\nIntroduzca el valor m�ximo de la abscisa. "
                       << "Debe ser un n�mero positivo: ";
                  cin >> max_x;
               }while (max_x < min_x);
            
               do{
                  cout << "\nIntroduzca el valor del incremento. "
                       << "Debe ser un n�mero positivo: ";
                  cin >> incremento;
               }while (incremento < 0);
            
            
               for(x = min_x; x <= max_x; x = x + incremento) {
                  valor_tipificado = (x - esperanza) / desviacion;
                  exponente = -0.5 * valor_tipificado * valor_tipificado;
                  y = exp(exponente) / ( desviacion * sqrt(2*PI) );
                  
                  y = Gaussiana(x, esperanza, desviacion);
                  
                  cout << "\nf(" << x << ")= " << y;
               }
            }
         }while (! eligio_salir_secundario);
      }
   }while (! eligio_salir_ppal);
}
