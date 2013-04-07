#include <iostream>
//#include "no.h"
#include "fila.h"
using namespace std;

no *raiz = new no;

void inserir(int valor){
	no *alocar = new no;
	alocar->chave = valor;

	if (raiz == NULL){
		raiz = alocar;
		cout << valor << " inserido na raíz da árvore!\n";
	}
	else{
		no *ponteiro;
		no *ponteiroAnterior;
		ponteiro = raiz;
		ponteiroAnterior = NULL;

		while(ponteiro) {
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
			cout << valor << " inserido a esquerda na árvore!\n";
		}
		else{
			if(ponteiroAnterior->chave < valor){
				ponteiroAnterior->dir = alocar;
				cout << valor << " inserido a direita na árvore!\n";
			}
			else{
				cout << valor << " já está na árvore!\n";
			}
		}
	}
}

void emNivel(no *raiz){
	fila F;
	no *f = raiz->dir;
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

int main(int argc, char const *argv[])
{
	cout << "Inserindo {4, 6, 5, 7, 2, 3, 6, 1} na ABB\n" << endl;

	int x[] = {4, 6, 5, 7, 2, 3, 6, 1};

	for (int i = 0; i < 8; i++){
		inserir(x[i]);
	}

	cout << "\nPercurso em nível:" << endl;

	emNivel(&(*raiz));
	
	cout << "\nDONE!" << endl;


	return 0;
}