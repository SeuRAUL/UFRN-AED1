#include <iostream>
#include "fila.h"

using namespace std;

// FILA {
	// Inserir na fila
	bool fila::enqueue(int informacao){
		int indexProv = (r+1)%SIZE_FILA;	   // avança retaguarda circularmente
		if (indexProv != f){
			r = indexProv;
			F[r] = informacao;
			if (f == -1)
				f = 0;
			return true;
		}
		else
			return false;
	};

	// remover da fila
	bool fila::dequeue(int *informacao){
		if (f != -1){
			*informacao = F[f];
			if (f == r)
				f = r = -1;
			else
				f = (f+1)%SIZE_FILA;
			return true;
		}
		else
			return false;
	};

	// Consultar fila
	bool fila::front(int *informacao){
		if (f != -1){
			*informacao = F[f];
			return true;
		}
		else
			return false;
	};
// }--FILA

int main(int argc, char const *argv[])
{
	fila f1;
	int top; // recebe por referencia o pop e top

	cout << endl;
	cout << "----------------------" << endl;
	cout << "Testes de FILA" << endl;
	cout << " > SIZE 10 <" << endl;
	cout << "----------------------" << endl;
	cout << endl;


// FILA {
	cout << "FILA:\n\n";

	cout << "Buscar inicio de FILA ainda vazia: " << endl;
	// teste frente 1
	if (f1.front(&top))
		cout << "Inicio -> " << top << endl;
	else
		cout << "Fila vazia :(" << endl;
	cout << "\n\n";

	cout << "Inserir 15 elementos na FILA -> 1 a 15\n\n";
	// teste enqueue
	for (int i = 0; i < 15; ++i){
		if (f1.enqueue(i+1))
			cout << "Enfileirou :) -> " << i+1 << endl;
		else
			cout << "Não enfileirou :( -> " << i+1 << endl;
	}
	cout << "\n\n";

	cout << "Remover 5 elementos da FILA\n\n";
	// teste dequeue
	for (int i = 0; i < 5; ++i){
		if (f1.dequeue(&top))
			cout << "Removeu! :) " << top << endl;
		else
			cout << "Fila vazia :(\n";
	}
	cout << "\n\n";

	cout << "Buscar frente de FILA não vazia: " << endl;
	// teste frente 2
	if (f1.front(&top))
		cout << "Frente -> " << top << endl;
	else
		cout << "Fila vazia :(" << endl;
	cout << "\n\n";
// }--FILA
	return 0;
}