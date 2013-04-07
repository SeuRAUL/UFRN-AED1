#include <iostream>
#include "pilha.h"
#include "fila.h"

using namespace std;

pilha digitos;
fila caracteres;

bool ehDigito(char x){
	if ( x >= 'A' && x <= 'z' )
		return false;
	return true;
}

string alocacao(string str){
	int i=0;
	char resgate;
	string str2 = str;
	while (str[i] != '\0'){
		if (ehDigito(str[i])){
			digitos.push(str[i]);
		}
		else{
			caracteres.enqueue(str[i]);
		}
		i++;
	}

	i=0;
	while(caracteres.dequeue(&resgate)){
		str2[i] = resgate;
		i++;
	}
	while(digitos.pop(&resgate)){
		str2[i] = resgate;
		i++;
	}
	return str2;
}

int main(int argc, char const *argv[])
{
	string xxx;

	cout << "Lista de caracteres: ";
	cin >> xxx;

	xxx = alocacao(xxx);

	cout << xxx << endl;

	return 0;
}