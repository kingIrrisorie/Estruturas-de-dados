#include <stdio.h>
#include <limits.h>

// Função que encontra o índice do menor elemento no array
int buscaMenor( int array[], int tamanho );

// Função que ordena o array usando o método de seleção
void ordenacaoPorSelecao( int array[], int tamanho );

// Função que imprime os elementos do array
void imprimirArray( int array[], int tamanho );

int main()
{
    // Declaração e inicialização do array
    int array[] = {5, 3, 6, 2, 10};
    // Calcula o tamanho do array
    int tamanho = sizeof(array) / sizeof(array[0]);
    // Imprimi o array original. Saída esperada [5, 3, 6, 2, 10]
    imprimirArray(array, tamanho);
    // Chama a função de ordenação
    ordenacaoPorSelecao(array, tamanho);
    // Chama a função para imprimir o array ordenado. Saída esperada [2, 3, 5, 6, 10]
    imprimirArray(array, tamanho);

    return 0;
}

// Função que encontra o índice do menor elemento no array
int buscaMenor( int array[], int tamanho )
{
    // Assume que o primeiro elemento é o menor
    int menor = array[0];
    int menorIndice = 0;

    // Itera pelo array para encontrar o menor elemento
    for (int i = 1; i < tamanho; i++)
    {
        // Se encontrar um elemento menor, atualiza menor e menorIndice
        if ( array[i] < menor )
        {
            menor = array[i];
            menorIndice = i;
        }
    }

    // Retorna o índice do menor elemento
    return menorIndice;
}

// Função que ordena o array usando o método de seleção
void ordenacaoPorSelecao( int array[], int tamanho )
{
    // Cria um array temporário para armazenar os elementos ordenados
    int novoArray[tamanho];

    // Itera pelo array original
    for (int i = 0; i < tamanho; i++)
    {
        // Encontra o índice do menor elemento no array original
        int menorIndice = buscaMenor(array, tamanho);
        // Copia o menor elemento para o array temporário
        novoArray[i] = array[menorIndice];
        // Marca o menor elemento como "usado" no array original
        array[menorIndice] = INT_MAX;
    }
    
    // Copia os elementos ordenados de volta para o array original
    for (int i = 0; i < tamanho; i++)
    {
        array[i] = novoArray[i];
    }
}

// Função que imprime os elementos do array
void imprimirArray( int array[], int tamanho )
{
    // Itera pelo array e imprime cada elemento
    for (int i = 0; i < tamanho; i++)
    {
        // Verifica se é o último elemento para não adicionar vírgula no final
        if (i == (tamanho - 1))
            printf("%d", array[i]);
        else
            printf("%d, ", array[i]);
    }
    // Imprime uma nova linha ao final
    printf("\n");
}
