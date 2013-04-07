#include <iostream>
#include "pilha.h"

using namespace std;

// PILHA {
	// Inserir na pilha
	bool pilha::push(int informacao) {
		if (topo < SIZE) {
			p[topo] = informacao;
			topo++;
			return true;
		}
		else
			return false;
	};

	// Remover da pilha
	bool pilha::pop(int *informacao){
		if(topo > 0){
			topo--;
			*informacao = p[topo];
			return true;
		}
		else
			return false;
	};

	// Consultar pilha
	bool pilha::top(int *informacao){
		if (topo > 0){
			*informacao = p[topo-1];
			return true;
		}
		else
			return false;
	}
// }--PILHA


int main(int argc, char const *argv[])
{
	pilha p1;
	int top; // recebe por referencia o pop e top

	cout << endl;
	cout << "----------------------" << endl;
	cout << "Testes de PILHA" << endl;
	cout << " > SIZE 10 <" << endl;
	cout << "----------------------" << endl;
	cout << endl;

// PILHA {
	cout << "PILHA:\n\n";

	// teste top 1
	cout << "Buscar topo de PILHA ainda vazia: " << endl;
	if (p1.pop(&top))
		cout << "Topo -> "<< top <<"\n";
	else
		cout << "Pilha vazia\n";

	cout << "\n\n";

	cout << "Inserir 15 elementos na PILHA -> 1 a 15\n\n";
	// teste push
	for (int i = 0; i < 15; ++i){
		if(p1.push(i+1))
			cout << "Inserido! :) " << i+1 << endl;
		else
			cout << "Não Inserido :( " << i+1 << endl;
	}
	cout  << "\n\n";

	cout << "Remover 5 elementos da PILHA\n\n";
	// teste pop
	for (int i = 0; i < 5; ++i){
		if (p1.pop(&top))
			cout << "Removido :) -> "<< top << endl;
		else
			cout << "Falha de remoção :(\n";
	}
	cout  << "\n\n";

	cout << "Buscar topo de PILHA não vazia: " << endl;
	// teste top 2
	if (p1.pop(&top))
		cout << "Topo -> "<< top << endl;
	else
		cout << "Pilha vazia :(\n";
	cout  << "\n\n";
// } --PILHA
	return 0;
}