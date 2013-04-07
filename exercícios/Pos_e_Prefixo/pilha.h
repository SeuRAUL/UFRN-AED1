const int SIZE (50);

class pilha {
public:
	//atributos
	char informacao;
	int topo;
	int p[SIZE];

	pilha(){
		topo = 0;
	}

	//metodos
	bool push(char informacao){
		if (topo < SIZE) {
			p[topo] = informacao;
			topo++;
			return true;
		}
		else
			return false;
	}

	bool pop(char *informacao){
		if(topo > 0){
			topo--;
			*informacao = p[topo];
			return true;
		}
		else
			return false;
	}

	bool top(char *informacao){
		if (topo > 0){
			*informacao = p[topo-1];
			return true;
		}
		else
			return false;
	}
};