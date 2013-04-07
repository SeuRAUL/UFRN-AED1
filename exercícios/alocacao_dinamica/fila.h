const int SIZE_FILA (30);

class fila {
public:
	//atributos
	char informacao;
	int f;
	int r;
	int F[SIZE_FILA];

	fila(){
		f = -1;
		r = -1;
	}

	//metodos
	bool enqueue(char informacao){
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
	bool dequeue(char *informacao){
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
	bool front(char *informacao){
		if (f != -1){
			*informacao = F[f];
			return true;
		}
		else
			return false;
	}
};