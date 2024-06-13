#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da fila
struct fila {
    int *dados;     // Array para armazenar os elementos da fila
    int inicio;     // Índice do primeiro elemento na fila
    int fim;        // Índice do próximo local vazio na fila
    int tamanho;    // Número atual de elementos na fila
    int capacidade; // Capacidade máxima da fila
};

// Funções da fila
struct fila* criarFila(int capacidade);
void destruirFila(struct fila *minhaFila);
void enfileirar(struct fila *minhaFila, int dado);
int desenfileirar(struct fila *minhaFila);
void mostrarFila(struct fila *minhaFila);

int main() {
    // Criando uma fila com capacidade para 5 elementos
    struct fila *fila = criarFila(5);

    // Enfileirando alguns elementos
    enfileirar(fila, 10);
    enfileirar(fila, 20);
    enfileirar(fila, 30);
    enfileirar(fila, 40);
    enfileirar(fila, 50);
    // Imprimindo a fila
    mostrarFila(fila);


    // Desenfileirando elementos
    printf("Elemento desenfileirado: %d\n", desenfileirar(fila));
    mostrarFila(fila); // Mostrando a fila depois de desenfileirar
    printf("Elemento desenfileirado: %d\n", desenfileirar(fila));
    mostrarFila(fila);
    printf("Elemento desenfileirado: %d\n", desenfileirar(fila));
    mostrarFila(fila);
    printf("Elemento desenfileirado: %d\n", desenfileirar(fila));
    mostrarFila(fila);
    printf("Elemento desenfileirado: %d\n", desenfileirar(fila));
    mostrarFila(fila);

    // Enfileirando mais um elemento
    enfileirar(fila, 40);

    // Imprimindo a fila
    mostrarFila(fila);
    // Liberando a memória alocada para a fila
    destruirFila(fila);

    return 0;
}

// Função para criar uma nova fila com a capacidade especificada
struct fila* criarFila(int capacidade) {
    // Alocando memória para a estrutura da fila
    struct fila* novaFila = (struct fila*)malloc(sizeof(struct fila));
    if (novaFila == NULL) {
        printf("Erro ao criar a fila\n");
        return NULL;
    }

    // Inicializando os atributos da fila
    novaFila->dados = (int *)malloc(capacidade * sizeof(int));
    if (novaFila->dados == NULL) {
        printf("Erro ao alocar espaço para a fila\n");
        free(novaFila);
        return NULL;
    }
    novaFila->inicio = 0;
    novaFila->fim = 0;
    novaFila->tamanho = 0;
    novaFila->capacidade = capacidade;

    return novaFila;
}

// Função para destruir a fila e liberar a memória alocada
void destruirFila(struct fila *minhaFila) {
    if (minhaFila != NULL) {
        free(minhaFila->dados);
        free(minhaFila);
    }
}

// Função para adicionar um elemento ao final da fila
void enfileirar(struct fila *minhaFila, int dado) {
    // Verifica se a fila já está cheia
    if (minhaFila->tamanho == minhaFila->capacidade) {
        printf("A fila está cheia\n");
        return; // Se a fila estiver cheia, não é possível adicionar mais elementos
    }

    // Adiciona o novo elemento na posição 'fim' da fila
    minhaFila->dados[minhaFila->fim] = dado;

    // atualiza o índice 'fim' para a próxima posição vazia na fila
    // Se 'fim' estiver no último índice da fila, volta para o início da fila
    // caso contrário, avança para a próxima posição vazia
    if (minhaFila->fim == minhaFila->capacidade - 1) {
        minhaFila->fim = 0;
    } else {
        minhaFila->fim++;
    }

    // Incrementa o tamanho da fila para refletir o novo elemento adicionado
    minhaFila->tamanho++;
}

// Função para remover e retornar o elemento do início da fila
int desenfileirar(struct fila *minhaFila) {
    // Verifica se a fila está vazia
    if (minhaFila->tamanho == 0) {
        printf("A fila está vazia\n");
        return -1; // Retorna -1 para indicar que não há elementos para desenfileirar
    }

    // Salva o elemento do início da fila para retorná-lo posteriormente
    int dado = minhaFila->dados[minhaFila->inicio];
    
    // Atualiza o índice 'inicio' para apontar para o próximo elemento na fila
    if (minhaFila->inicio == minhaFila->capacidade - 1) {
        minhaFila->inicio = 0; // Se 'inicio' está no último índice, volta para o início
    } else {
        minhaFila->inicio++;   // Caso contrário, avança para o próximo índice
    }

    // Decrementa o tamanho da fila para refletir a remoção do elemento
    minhaFila->tamanho--;

    // Retorna o elemento removido do início da fila
    return dado;
}

// Função para imprimir os elementos da fila
void mostrarFila(struct fila *minhaFila) {
    // Verificando se a fila está vazia
    if (minhaFila->tamanho == 0) {
        printf("A fila está vazia\n");
        return;
    }

    // Mostrar os elementos da fila
    printf("Fila: ");
    int i;
    for (i = 0; i < minhaFila->tamanho; i++) {
        int index = (minhaFila->inicio + i) % minhaFila->capacidade;
        printf("%d ", minhaFila->dados[index]);
    }
    printf("\n");
}
