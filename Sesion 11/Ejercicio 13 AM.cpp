#include <iostream>
#include <random> // -> generaci�n de n�meros pseudoaleatorios
#include <chrono> // -> para la semilla

using namespace std;

class GeneradorAleatorioEnteros{
private:
	mt19937 generador_mersenne; // Mersenne twister
	uniform_int_distribution<int> distribucion_uniforme;
	
	long long Nanosec(){
		return chrono::high_resolution_clock::now().
			time_since_epoch().count();
	}
public:
	GeneradorAleatorioEnteros()
		:GeneradorAleatorioEnteros(0, 1){
}
	GeneradorAleatorioEnteros(int min, int max){
		const int A_DESCARTAR = 70000;
		// ACM TOMS Volume 32 Issue 1, March 2006
		auto semilla = Nanosec();
		generador_mersenne.seed(semilla);
		generador_mersenne.discard(A_DESCARTAR);
		distribucion_uniforme =	
		uniform_int_distribution<int> (min, max);
	}
	int Siguiente(){
		return distribucion_uniforme(generador_mersenne);
	}
};

int main(){	
	for(int i = 0; i < 100; i++){
		GeneradorAleatorioEnteros numeros_totales(0 , 4);
		for(int j = 0; j <= numeros_totales.Siguiente(); j++){
			GeneradorAleatorioEnteros num_0_1_a_generar;
			cout << num_0_1_a_generar.Siguiente();
		}
		cout << '\n';
	}
}

