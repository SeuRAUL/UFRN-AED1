#include <iostream>
#include "lista.h"
using namespace std;

listaEncadeada inicio = new listaEncadeada;

void buscaOrdenada(int informacao, listaEncadeada anterior, listaEncadeada ponteiro){
	listaEncadeada ptr = *inicio.prox;
	anterior = inicio;
	ponteiro = NULL;
	while(ptr != NULL){
		if (*ptr.informacao != informacao){
			anterior = ptr;
			ptr = *ptr.prox;
		}
		else{
			if (*ptr == informacao)
				ponteiro = ptr;
			else
				ptr = NULL;
		}
	}
}

void imprimeLista(listaEncadeada *l){
	while(l.prox != NULL){
		l = l.prox;
		cout << "Informação: " << l.Informacao << endl;
	}
}