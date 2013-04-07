const int SIZE_FILA (10);

class fila {
public:
	//atributos
	int informacao;
	int f;
	int r;
	int F[SIZE_FILA];

	fila(){
		f = -1;
		r = -1;
	}

	//metodos
	bool enqueue(int informacao);
	bool dequeue(int *informacao);
	bool front(int *informacao);
};