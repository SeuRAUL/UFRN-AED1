class no {
public:
	//atributos
	int chave;
	no *esq, *dir;

	no(){
		this->esq = this->dir = NULL;
	}
};