#define SIZE 10

//defini��o do TAD 
struct pessoa{
int cpf;
char nome[30];
};

//declara��o da lista sequencial
struct pessoa pilha[SIZE];
int topo = 0;

//fun��es pilha
int push(struct pessoa p);
int pop(struct pessoa *p);
int top(struct pessoa *p);
void imprimePilha( );

int main (){
    push(novaPessoa);
    
    if (pop(&novaPessoa)){
    }
    
 } 

//insere um elemento no topo da pilha
int push(struct pessoa p){
    // ...
}

//remove o elemento do topo da pilha
int pop(struct pessoa *p){
    // ....
}

//consulta o elemento no topo da pilha
int top(struct pessoa *p){
    // ...
}
