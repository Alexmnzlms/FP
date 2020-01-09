#include <iostream>

using namespace std;

class Instante{
private:
	int horas;
	int minutos;
	int segundos;
	
	static int const SEGUNDOS_HORA = 3600;
	static int const SEGUNDOS_MINUTO = 60;

	int ConversionSegundos(){
		int segundos_totales;
		
		segundos_totales = horas * SEGUNDOS_HORA + minutos * SEGUNDOS_MINUTO + segundos;
		
		return segundos_totales;
	}
	
	int ConversionMinutos(){
		int minutos_totales;
		
		minutos_totales = horas * SEGUNDOS_HORA + minutos + segundos / SEGUNDOS_MINUTO;
		
		return minutos_totales;
	}
	
	void AjusteTiempo(){
		while(segundos >= 60){
			minutos++;
			segundos = segundos - 60;
		}
		while(minutos >= 60){
			horas++;
			minutos = minutos - 60;
		}
	}
	
public:
	Instante(int hora, int minuto, int segundo)
	:horas(hora),
	 minutos(minuto),
	 segundos(segundo)
	 {
	 }
	
	string PrintInstante(){
		AjusteTiempo();
		string instante;
		instante =
		to_string(horas) + " h "
		+ to_string(minutos) + " ' "
		+ to_string(segundos)+ " ''";
		
		return instante;
	}
	
	string MinutosPasados(){
		string 
	}
	
	void SetSegundos(double tiempo){
		double hora, minuto, segundo;
		int contador;
		hora = tiempo / SEGUNDOS_HORA;
		while(hora >= 1){
			hora--;
			contador++;
		}
		horas = contador;
		contador = 0;
		minuto = hora * SEGUNDOS_MINUTO;
		while(minuto >= 1){
			minuto--;
			contador++;
		}
		minutos = contador;
		contador = 1;
		segundo = minuto * SEGUNDOS_MINUTO;
		while(segundo >= 1){
			segundo--;
			contador++;
		}
		segundos = contador;
	}
	
	int Horas(){
		return horas;
	}
	
	int Minutos(){
	return minutos;
	}	
		
	int Segundos(){
		return segundos;
	}
};
int LeeIntRango(int min, int max, string mensaje) {
   int a_leer;
   cout << mensaje;
   cin >> a_leer;
   while (min > a_leer || max < a_leer){
      cout << mensaje;
      cin >> a_leer;
   }
   
   return a_leer;
}

Instante RestaInstantes(Instante instante_inicial, Instante instante_final){
	int horas_diferencia, minutos_diferencia, segundos_diferencia;
	horas_diferencia = instante_final.Horas() - instante_inicial.Horas();
	minutos_diferencia = instante_final.Minutos() - instante_inicial.Minutos();
	segundos_diferencia = instante_final.Segundos() - instante_inicial.Segundos();
	Instante instante_diferencia(horas_diferencia, minutos_diferencia, segundos_diferencia);
	return instante_diferencia;
}


int main(){
	int hora_i, hora_f;
 	int minuto_i, minuto_f;
	int segundo_i, segundo_f;

	hora_i = LeeIntRango(0,23,"Introduzca horas iniciales: ");
	minuto_i = LeeIntRango(0,59,"Introduzca minutos iniciales: ");
	segundo_i = LeeIntRango(0,59,"Introduzca segundos iniciales: ");

	hora_f = LeeIntRango(0,23,"Introduzca horas finales: ");
	minuto_f = LeeIntRango(0,59,"Introduzca minutos finales: ");
	segundo_f = LeeIntRango(0,59,"Introduzca segundos finales: ");
	
	Instante inicial(hora_i, minuto_i, segundo_i);
	Instante final(hora_f, minuto_f, segundo_f);
	
	cout << RestaInstantes(inicial, final).PrintInstante();
}
