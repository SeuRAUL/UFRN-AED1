#define SIZE 10

//definição do TAD 
struct pessoa{
int cpf;
char nome[30];
};

//declaração da fila sequencial
struct pessoa fila[SIZE];
int f = -1; //controla a frente da fila
int r = -1; //controla a retaguarda da fila

//funções fila
int enqueue(struct pessoa p);
int dequeue(struct pessoa *p);
int front(struct pessoa *p);

int main (){
    
    enqueue(novaPessoa);
    if (dequeue(&novaPessoa)){
    }                          
} 

//insere um elemento na retaguarda da fila
int enqueue(struct pessoa p){
    // ....
}

//remove o elemento da frente da fila
int dequeue(struct pessoa *p){
    // ...
}
//consulta o elemento no topo da pilha
int front(struct pessoa *p){
    //....
}   
