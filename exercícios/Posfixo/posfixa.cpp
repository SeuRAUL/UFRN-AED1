#include <iostream>
#include <string>
#include "pilha.h"
using namespace std;

bool testeOperador(char x){
	if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '%' || x == '(' || x == ')')
		return true;
	return false;
}

int procedencia (char a){
	if (a == '(' || a == ')')
		return 1;
	else if (a == '^')
		return 2;
	else if(a == '*' || a == '/' || a == '%')
		return 3;
	else
		return 4;
}

int main(int argc, char const *argv[]){

	pilha Operadores;
	char Operador;
	
	string infixa;
	cout << "Notação infixa a converter:" << endl;
	getline (cin, infixa);

	int i = 0;
	while(infixa[i] != '\0'){
		inicio:
		if (!testeOperador(infixa[i])){
			if (infixa[i] != ' ')
				cout << infixa[i];
		}
		else {
			if (infixa[i] != '(')
				cout << ' ';


			if (infixa[i] == ')'){
				i++;
				while (Operadores.pop(&Operador)){
					if(Operador != '('){
						cout << Operador;
					}
					else
						goto inicio;
				}
			}
			if (Operadores.top(&Operador)){  // verifica se há operador na pilha para comparar

				if (Operador == '(' || (procedencia(Operador) > procedencia(infixa[i]) )){ // testa a procedencia do operador de topo e compara com o que apareceu
					Operadores.push(infixa[i]);
				}
				else {
					Operadores.pop(&Operador);
					cout << Operador << ' ';
					Operadores.push(infixa[i]);
				}
			}
			else{
				Operadores.push(infixa[i]);
			}
		}
		i++;
	}

	while( Operadores.top(&Operador) ){
		Operadores.pop(&Operador);
		cout << ' ' << Operador;
	}
	
	cout << "\n";
	return 0;
}