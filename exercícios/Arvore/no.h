class no {
public:
	//atributos
	int chave;
	no *esq, *dir;

	no(){
		this->esq = this->dir = NULL;
	}

	//metodos
	bool Busca(no *inicio, int valor) {

		if (inicio == NULL){
	        return true;
		}

		if (valor == inicio->chave) {
			return false;
		}

		if (valor < inicio->chave){
			return(Busca(inicio->esq, valor));
		}else{
			if(valor > inicio->chave) {
				return(Busca(inicio->dir, valor));
			}
		}
	}

	// função para inserir um nó na arvore binária de busca
	/*bool insere (no ** pos, int valor) {
		if (*pos == NULL){
			*pos = cria_no(valor);
			return true;
		}

		if (valor < (*pos)->chave){
			insere(&((*pos)->esq), valor);
			return true;
		}else {
			if(valor>(*pos)->chave) {
				insere( &((*pos)->dir), valor);
				return true;
			}else{
				return false;
			}
		}
	}*/
};