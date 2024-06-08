#include <stdio.h>
#include <stdlib.h>

// Definindo o tamanho máximo da pilha
#define tamanhoMaximo 100

/* Criando a pilha como uma lista
   com tamanho 100 (tamanhoMaximo) */
int pilha[tamanhoMaximo];

/* Variável para acompanhar o topo da pilha, 
iniciada com -1 para indicar que a pilha está vazia*/
int top = -1;

// Funcao para verificar se a pilha está vazia
int estaVazia();

// Funcao para verificar se a pilha está cheia
int estaCheia();

// Funcao para adicionar um elementa a pilha (push)
void adicionarElemento(int);

// Funcao para remover um elemento da pilha (pop)
int removerElemento();

// Funcao para olhar o topo da pilha (peek)
int verTopoDaPilha();

// Funcao Principal (main), a que será executada primeiro
int main()
{
    // Adicionando elementos à pilha
    adicionarElemento(1); // pilha: [1]
    adicionarElemento(2); // pilha: [1, 2]
    adicionarElemento(3); // pilha: [1, 2, 3]

    // Iterando sobre os elementos da pilha para imprimir sua representação
    // Resultado: [1, 2, 3]
    printf("[");
    for (int i = 0; i <= top; i++)
    {
        if (i == top)
            printf("%d]\n", pilha[i]);
        else
            printf("%d, ", pilha[i]);
    }

    printf("Elemento removido: %d\n", removerElemento());  // Deve imprimir 3, Pilha agora: [1, 2]

    printf("Topo da pilha: %d\n", verTopoDaPilha());  // Deve imprimir 2

    printf("A pilha está vazia? %s\n", estaVazia() ? "Sim" : "Não");  // Deve imprimir "Não"

    removerElemento();  // Remove 2, Pilha: [1]
    removerElemento();  // Remove 1, Pilha: []

    printf("A pilha está vazia? %s\n", estaVazia() ? "Sim" : "Não");  // Deve imprimir "Sim"

    return 0;
}

int estaVazia()
{
    return top == -1;
}

int estaCheia()
{
    return top == tamanhoMaximo -1;
}

void adicionarElemento(int elemento)
{
    // Verificar se a pilha está cheia antes de adicionar um elemento
    if (estaCheia())
    {
        printf("A pilha está cheia. Não é possível adicionar mais elementos.\n");
        return;
    }

    // Incrementar o índice do topo da pilha (top) antes de adicionar o elemento
    // Isso garante que o novo elemento seja adicionado no próximo espaço disponível na pilha
    // Se a pilha estiver vazia, top será -1. Portanto, top + 1 será o índice 0.
    // Se a pilha tiver elementos, top + 1 será o próximo espaço disponível após o último elemento.
    top++;  // Incrementa o índice do topo da pilha
    pilha[top] = elemento;  // Adiciona o elemento ao topo da pilha
}

int removerElemento()
{
    // Verificar se a pilha está vazia antes de remover um elemento
    if (estaVazia())
    {
        printf("A pilha está vazia. Não é possível remover elementos.\n");
        return -1;  // Retorna um valor indicando erro, já que a pilha está vazia
    }

    // Retornar e remover o elemento do topo da pilha
    // O operador '--top' primeiro usa o valor de 'top' e depois o decrementa,
    // portanto, 'pilha[top--]' retorna o elemento do topo da pilha e, em seguida,
    // decrementa o índice do topo para apontar para o próximo elemento da pilha.
    return pilha[top--];
}


int verTopoDaPilha()
{
    if (estaVazia())
    {
        printf("A pilha está vazia.\n");
        return -1;
    }
    return pilha[top];
}
