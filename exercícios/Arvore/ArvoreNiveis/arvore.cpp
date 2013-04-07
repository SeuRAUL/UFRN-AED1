#include <iostream>
#include <cstdlib>
#include "fila.h"
using namespace std;

no *raiz = new no;

bool inserir(int valor){
	no *alocar = new no;
	alocar->chave = valor;

	if (raiz == NULL){
		raiz = alocar;
		cout << valor << " inserido na raíz da árvore!\n";
	}
	else{
		no *ponteiro = new no;
		no *ponteiroAnterior = new no;
		ponteiro = raiz;
		ponteiroAnterior = NULL;

		while(ponteiro != NULL) {
			ponteiroAnterior = ponteiro;

			if (ponteiro->chave > valor){
				ponteiro = ponteiro->esq;
			}
			else if(ponteiro->chave < valor){
				ponteiro = ponteiro->dir;
			}
			else if (ponteiro->chave == valor){
				break;
			}
		}

		if (ponteiroAnterior->chave > valor){
			ponteiroAnterior->esq = alocar;
			cout << valor << " inserido na árvore!\n";
			return true;
		}
		else{
			if(ponteiroAnterior->chave < valor){
				ponteiroAnterior->dir = alocar;
				cout << valor << " inserido na árvore!\n";
				return true;
			}
			else{
				cout << valor << " já está na árvore!\n";
				return false;
			}
		}
	}
}

void emNivel(){
	fila F;
	no *f = new no;
	f->chave = (raiz->dir)->chave;
	f->dir = (raiz->dir)->dir;
	f->esq = (raiz->dir)->esq;
	if(raiz != NULL){
		F.enqueue(*f);
		while(F.front(f)){
			F.dequeue(f);
			cout << f->chave << endl;
			if(f->esq != NULL){
				F.enqueue(*f->esq);
			}
			if (f->dir != NULL){
				F.enqueue(*f->dir);
			}
		}
	}
}

void preOrdem(no *g){
	cout << g->chave << endl;
	if(g->esq != NULL){
		preOrdem(g->esq);
	}
	if(g->dir != NULL){
		preOrdem(g->dir);
	}
}

void inOrdem(no *g){
	
	if(g->esq != NULL){
		inOrdem(g->esq);
	}
	cout << g->chave << endl;
	if(g->dir != NULL){
		inOrdem(g->dir);
	}
}

void posOrdem(no *g){
	if(g->esq != NULL){
		posOrdem(g->esq);
	}
	if(g->dir != NULL){
		posOrdem(g->dir);
	}
	cout << g->chave << endl;
}

int main(int argc, char const *argv[])
{
	int i=0;
	srand(time(NULL));
	while(i<7){
		if( inserir( rand()%10) )
			i++;
	}

	cout << "\nPercurso em nível:" << endl;

	emNivel();


	cout << "\nPré-Ordem:\n";
	no *g = new no;
	g = raiz->dir;
	preOrdem(&(*g));

	cout << "\nPós-Ordem:\n";
	posOrdem(&(*g));

	cout << "\nIn-Ordem:\n";
	inOrdem(&(*g));
	
	cout << "\nDONE!" << endl;


	return 0;
}