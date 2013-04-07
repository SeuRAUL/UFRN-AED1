#include "no.h"

const int SIZE_FILA (100);

class fila {
public:
	//atributos
	no informacao;
	int f;
	int r;
	no F[SIZE_FILA];

	fila(){
		f = -1;
		r = -1;
	}

	//metodos
	bool enqueue(no informacao){
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
	}
	bool dequeue(no *informacao){
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
	}
	bool front(no *informacao){
		if (f != -1){
			*informacao = F[f];
			return true;
		}
		else
			return false;
	}
};