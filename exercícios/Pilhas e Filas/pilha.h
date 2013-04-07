const int SIZE (10);

class pilha {
public:
	//atributos
	int informacao;
	int topo;
	int p[SIZE];

	pilha(){
		topo = 0;
	}

	//metodos
	bool push(int informacao){
		if (topo < SIZE) {
			p[topo] = informacao;
			topo++;
			return true;
		}
		else
			return false;
	}

	bool pop(int *informacao){
		if(topo > 0){
			topo--;
			*informacao = p[topo];
			return true;
		}
		else
			return false;
	}

	bool top(int *informacao){
		if (topo > 0){
			*informacao = p[topo-1];
			return true;
		}
		else
			return false;
	}
};