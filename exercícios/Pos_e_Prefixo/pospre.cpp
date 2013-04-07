#include <string>
#include <iostream>
//#include <string>
#include "pilha.h"
using namespace std;

	pilha Operadores;
	char Operador;

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

string inverte(string str){
	int i=0;
	while (str[i] != '\0'){
		Operadores.push(str[i]);
		i++;
	}
	i=0;
	while(Operadores.pop(&Operador)){
		str[i] = Operador;
		i++;
	}
	return str;
}

int main(int argc, char const *argv[]){


	int escolha;
	int i = 0;
	
	string infixa;
	cout << "Notação infixa a converter:" << endl;
	getline (cin, infixa);

	cout << "Converter para:\n1 - Prefixa\n2 - Posfixa: ";
	cin >> escolha;

	if (escolha == 1){
		int str2_cont = 0;
		string str2 = infixa = inverte(infixa);

		i=0;
		while(infixa[i] != '\0'){
			inicio1:
			if (!testeOperador(infixa[i])){
				if (infixa[i] != ' '){
					str2[str2_cont] = infixa[i];
					str2_cont++;
				}
			}
			else {


				if (infixa[i] == '('){
					i++;
					while (Operadores.pop(&Operador)){
						if(Operador != ')'){
							str2[str2_cont] = Operador;
							str2_cont++;
						}
						else
							goto inicio1;
					}
				}
				if (Operadores.top(&Operador)){  // verifica se há operador na pilha para comparar

					if (Operador == ')' || (procedencia(Operador) <= procedencia(infixa[i]) )){ // testa a procedencia do operador de topo e compara com o que apareceu
						Operadores.push(infixa[i]);
					}
					else {
						Operadores.pop(&Operador);
						str2[str2_cont] = Operador;
						str2_cont++;
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
			str2[str2_cont] = Operador;
			str2_cont++;
		}
		str2[str2_cont] = '\0';

		


		str2 = inverte(str2);
		cout << str2 << endl;
		

		// ---> Final escolha 1

	}
	else if (escolha == 2) {
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
	}
	cout << "\n";
	return 0;
}