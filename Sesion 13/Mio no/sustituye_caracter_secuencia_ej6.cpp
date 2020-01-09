#include <iostream>
#include <cctype>
using namespace std;


struct FrecuenciaCaracter{
   char caracter;
   int  frecuencia;
};


class SecuenciaCaracteres{
private:
   static const int TAMANIO = 2e6;  // <- Para que compile con este tamaño debe consultar el guión de prácticas
   char vector_privado[TAMANIO];
   int total_utilizados;

   void IntercambiaComponentesDirectamente(int pos_izda, int pos_dcha){
      char intercambia;

      intercambia = vector_privado[pos_izda];
      vector_privado[pos_izda] = vector_privado[pos_dcha];
      vector_privado[pos_dcha] = intercambia;
   }
public:

   ///////////////////////////////////////////////////////////////////////
   // Métodos vistos en los apuntes:
   ///////////////////////////////////////////////////////////////////////

   SecuenciaCaracteres()
      :total_utilizados(0) {
   }

   int TotalUtilizados(){
      return total_utilizados;
   }

   int Capacidad(){
      return TAMANIO;
   }

   void EliminaTodos(){
      total_utilizados = 0;
   }

   void Aniade(char nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }

   void Modifica(int posicion, char nuevo){
      if (posicion >= 0 && posicion < total_utilizados)
         vector_privado[posicion] = nuevo;
   }

   char Elemento(int indice){
      return vector_privado[indice];
   }

   string ToString(){
      string cadena;

      cadena.reserve(total_utilizados);

      for (int i=0; i < total_utilizados; i++)
         cadena.push_back(vector_privado[i]);

      return cadena;
   }

   void Elimina (int posicion){
      if (posicion >= 0 && posicion < total_utilizados){
         int tope = total_utilizados-1;

         for (int i = posicion ; i < tope ; i++)
            vector_privado[i] = vector_privado[i+1];

         total_utilizados--;
      }
	}


   // Inserta un valor en la posición especificada
   void Inserta(int pos_insercion, char valor_nuevo){
      if (total_utilizados < TAMANIO  &&  pos_insercion >= 0
         &&  pos_insercion <= total_utilizados){

         for (int i = total_utilizados ; i > pos_insercion ; i--)
            vector_privado[i] = vector_privado[i-1];

         vector_privado[pos_insercion] = valor_nuevo;
         total_utilizados++;
      }
   }


   int PrimeraOcurrenciaEntre(int pos_izda, int pos_dcha, char buscado){
      int i = pos_izda;
      bool encontrado = false;

      while (i <= pos_dcha  &&  !encontrado)
         if (vector_privado[i] == buscado)
            encontrado = true;
         else
            i++;

      if (encontrado)
         return i;
      else
         return -1;
   }

   int PrimeraOcurrencia (char buscado){
      return PrimeraOcurrenciaEntre(0, total_utilizados - 1, buscado);
   }


   FrecuenciaCaracter Moda(){   // versión con vector local
      /*
      Algoritmo (Moda de una secuencia de caracteres):

         Almacenaremos en un vector local los caracteres ya procesados

         Recorrer todos los caracteres de la secuencia original
            Buscar el carácter en el vector local de procesados
            Si no está (no ha sido procesado aún),
               lo añadimos y actualizamos, en su caso, la moda
      */

      const int NUMERO_CARACTERES_ASCII = 256;
      char procesados[NUMERO_CARACTERES_ASCII];
      FrecuenciaCaracter moda;
      char caracter_actual;
      int conteo_frecuencia;
      int utilizados_procesados;
      bool encontrado;


      utilizados_procesados = 0;
      moda.frecuencia = 0;

      for (int i = 0 ; i < total_utilizados ; i++){
         caracter_actual = vector_privado[i];
         encontrado = false;

         for (int j = 0; j < utilizados_procesados && !encontrado; j++){
            if (caracter_actual == procesados[j])
               encontrado = true;
         }

         if (! encontrado){
            procesados[utilizados_procesados] = caracter_actual;
            utilizados_procesados++;
            conteo_frecuencia = 1;

            for (int k = i + 1 ; k < total_utilizados ; k++)
               if (caracter_actual == vector_privado[k])
                  conteo_frecuencia++;

            if (conteo_frecuencia > moda.frecuencia) {
               moda.frecuencia = conteo_frecuencia;
               moda.caracter   = caracter_actual;
            }
         }
      }

      return moda;

      /*
      IMPORTANTE:
         Observe que el proceso de buscar un carácter dentro de procesados
         es análogo al proceso de buscar dentro de la clase SecuenciaCaracteres
         En el tema V veremos cómo no repetir este código y reutilizar
         esa funcionalidad ya definida dentro de la clase.
      */
   }



   ///////////////////////////////////////////////////////////////////////
   // Métodos nuevos:
   ///////////////////////////////////////////////////////////////////////


   void InsertaSecuencia(int pos_insercion, SecuenciaCaracteres a_insertar){
      int longitud_a_insertar = a_insertar.TotalUtilizados();

      if (longitud_a_insertar + total_utilizados < TAMANIO){
         for (int i = 0; i < longitud_a_insertar; i++){
            Inserta(pos_insercion, a_insertar.Elemento(i));    // Inserta aumenta automáticamente total_tulizados
            pos_insercion++;
         }
      }
   }


   // Precondición: Hay espacio suficiente para realizar las sustituciones.
   // Si no hay espacio suficiente, reemplaza lo que haya podido
   // Si se quiere comprobar la precondición, bastaría realizar
   // la misma comprobación inicial que se hace en la versión óptima
   // es decir, ver si total de caracteres a insertar menos los que
   // se eliminan, caben en el vector privado
   void Replace(char a_eliminar, SecuenciaCaracteres sustituta){
      SecuenciaCaracteres copia;
      int utilizados_sustituta = sustituta.TotalUtilizados();
      int i = 0;

      while( i < total_utilizados && copia.TotalUtilizados() < TAMANIO){
         if (vector_privado[i] == a_eliminar){
            copia.InsertaSecuencia(copia.TotalUtilizados(), sustituta);

         }
         else{
            copia.Aniade(vector_privado[i]);
         }
         i++;
      }

      total_utilizados = copia.TotalUtilizados();

      for (int i = 0; i < copia.TotalUtilizados(); i++)
         vector_privado[i] = copia.Elemento(i);
   }


   int NumeroOcurrencias (char buscado, int izda, int dcha){
      int numero_ocurrencias = 0;

      for (int i = izda; i <= dcha; i++)
         if (vector_privado[i] == buscado)
            numero_ocurrencias++;

      return numero_ocurrencias;
   }

   FrecuenciaCaracter Moda_vs2(){      // versión con SecuenciaCaracteres local


      char caracter_actual;
      SecuenciaCaracteres procesados;
      int  conteo_parcial;
      FrecuenciaCaracter moda;

      moda.frecuencia = 0;

      for (int i = 0 ; i < total_utilizados ; i++){
         caracter_actual = vector_privado[i];

         if (-1 == procesados.PrimeraOcurrencia(caracter_actual)){
            procesados.Aniade(caracter_actual);

            conteo_parcial =
               NumeroOcurrencias(vector_privado[i],
                                 i,
                                 total_utilizados - 1);

            if (conteo_parcial > moda.frecuencia) {
               moda.frecuencia = conteo_parcial;
               moda.caracter   = caracter_actual;
            }
         }
      }

      return moda;
   }

};


class LectorSecuenciaCaracteres{
private:
   char terminador;
public:
   LectorSecuenciaCaracteres(char caracter_terminador)
      :terminador(caracter_terminador)
   {
   }
   SecuenciaCaracteres Lee(){
      SecuenciaCaracteres a_leer;
      int total_introducidos;  // Esta variable es para contar los introducidos
                               // y que no nos pasemos de la capacidad de la secuencia.
      int capacidad_secuencia;
      char caracter;

      total_introducidos = 0;
      capacidad_secuencia = a_leer.Capacidad();
      caracter = cin.get();

      while (caracter == '\n')
   		caracter = cin.get();

		while (caracter != terminador && total_introducidos < capacidad_secuencia){
			a_leer.Aniade(caracter);
			total_introducidos++;
			caracter = cin.get();
		}

		return a_leer;
	}
};


int main(){
   const char TERMINADOR_CARACTERES = '#';
   SecuenciaCaracteres secuencia, a_insertar;
   LectorSecuenciaCaracteres lector_secuencias(TERMINADOR_CARACTERES);
   char a_sustituir;

   secuencia  = lector_secuencias.Lee();
   a_insertar = lector_secuencias.Lee();

   a_sustituir = cin.get();

   secuencia.Replace(a_sustituir, a_insertar);

   cout << "\nSecuencia nueva: " << secuencia.ToString();

   //Juan Cubero# Carlos#4
}
