#include <stdio.h>

// Declaração da função de busca binária. Ela recebe um ponteiro para o array,
// o tamanho do array e o item que está sendo procurado.
int buscaBinaria(int *mylist, int len, int item);

int main()
{
    // Definimos um array de inteiros ordenado de forma crescente.
    int myList[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    
    // Calculamos o tamanho do array dividindo o tamanho total em bytes pelo tamanho de um elemento.
    int len = sizeof(myList) / sizeof(myList[0]);

    // Chamamos a função de busca binária, passando o array, seu tamanho e o item que queremos encontrar.
    int indexReturned = buscaBinaria(myList, len, 8);

    // Imprimimos o índice do item encontrado. Se o item não for encontrado, a função retorna -1.
    printf("%d\n", indexReturned);
    
    return 0;
}

// Implementação da função de busca binária.
int buscaBinaria(int *mylist, int len, int item)
{
    // Definimos os limites inferior (baixo) e superior (alto) do intervalo de busca.
    int baixo = 0;
    int alto = len - 1;

    // Continuamos a busca enquanto o limite inferior for menor ou igual ao limite superior.
    while (baixo <= alto)
    {
        // Calculamos o índice do meio do intervalo atual.
        int meio = (baixo + alto) / 2;

        // Pegamos o valor do elemento no meio do intervalo.
        int chute = mylist[meio];

        // Se o elemento no meio for o item procurado, retornamos seu índice.
        if (chute == item)
            return meio;

        // Se o elemento no meio for maior que o item procurado, ajustamos o limite superior.
        if (chute > item)
            alto = meio - 1;
        // Caso contrário, ajustamos o limite inferior.
        else
            baixo = meio + 1;
    }

    // Se não encontrarmos o item, retornamos -1.
    return -1;
}
