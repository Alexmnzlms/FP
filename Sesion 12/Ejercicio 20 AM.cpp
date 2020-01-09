/* Se ha añadido a la clase SecuenciaCaracteres un metdodo que elminina 
   de forma ineficiente todas las ocurrencias de un caracter que 
   encuentre dentro del objeto.*/

#include <iostream>
#include <string>

using namespace std;

class SecuenciaCaracteres{
private:
	static const int TAMANIO = 2e6;
	char vector[TAMANIO];
	int utilizado;
	
public:
	SecuenciaCaracteres()
	:utilizado(0)
	{
	}
	
	int TotalUtilizados(){
      return utilizado;
   }
   
   int Capacidad(){
      return TAMANIO;
   }
   
   void EliminaTodos(){
      utilizado = 0;
   }
   
   void Aniade(char nuevo){
      if (utilizado < TAMANIO){
         vector[utilizado] = nuevo;
         utilizado++;
      }
   }
   
   void Modifica(int posicion, char nuevo){
      if (posicion >= 0 && posicion < utilizado)
         vector[posicion] = nuevo;
   }

   char Elemento(int indice){
      return vector[indice];
   }
	
   void Elimina (int posicion){
   if (posicion >= 0 && posicion < utilizado){
      int tope = utilizado-1;

      for (int i = posicion ; i < tope ; i++)
         vector[i] = vector[i+1];

      utilizado--;
   	}
	}
	
	void EliminaOcurrencias( char borrar){
		int pos = 0;
		while(pos < utilizado){
			if(vector[pos] == borrar){
				Elimina(pos);
			}
			else{
				pos++;
			}
		}
	}
	
	void SetCaracter(int posicion, char caracter){
		vector[posicion] = caracter;
	}
	
	void SetUtil(int util){
		utilizado = util;
	}
	
	string PrintVector(){
		string cadena = "";
		for(int i = 0; i < utilizado; i++){
			cadena.push_back(vector[i]);
		}
		
		return cadena;
	}


};

int main(){
	const char TERMINADOR = '#';
	SecuenciaCaracteres letras;
	char caracter, borrar;
	int contador = 0;
	
	cout << "Introduzca ahora la cadena (finalize con #):\n";
	caracter = cin.get();
	while(caracter != TERMINADOR){
		letras.SetCaracter(contador, caracter);
		contador++;
		caracter = cin.get();
	}	
	letras.SetUtil(contador);
	
	cout << "\nIntroduzca el caracter a borrar: ";
	cin >> borrar;
	
	letras.EliminaOcurrencias(borrar);
	
	cout << letras.PrintVector();
}
