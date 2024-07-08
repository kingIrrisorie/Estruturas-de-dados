def buscaMenor(arr):
    """
    Função que encontra o índice do menor elemento em um array.
    :parametro arr: Lista de números.
    :retorna: Índice do menor elemento.
    """
    menor = arr[0]  # Assume que o primeiro elemento é o menor
    menor_indice = 0  # Índice do menor elemento

    # Itera pela lista para encontrar o menor elemento
    for i in range(1, len(arr)):
        if arr[i] < menor:
            menor = arr[i]
            menor_indice = i
    
    return menor_indice  # Retorna o índice do menor elemento


def ordenacaoPorSelecao(arr):
    """
    Função que ordena um array usando o método de seleção.
    :parametro arr: Lista de números a serem ordenados.
    :retorna: Nova lista com os elementos ordenados.
    """
    novoArr = []  # Cria uma lista temporária para armazenar os elementos ordenados

    # Itera pelo array original
    for i in range(len(arr)):
        menor = buscaMenor(arr)  # Encontra o índice do menor elemento
        novoArr.append(arr.pop(menor))  # Remove o menor elemento do array original e adiciona ao novo array
    
    return novoArr  # Retorna o novo array ordenado


def imprimirArray(arr):
    """
    Função que imprime os elementos de um array.
    :parametro arr: Lista de números.
    """
    for i in range(len(arr)):
        if i == len(arr) - 1:
            print(arr[i], end="")  # Imprime o último elemento sem vírgula
        else:
            print(arr[i], end=", ")  # Imprime os elementos com vírgulas entre eles
    print()  # Nova linha após imprimir todos os elementos


# Exemplo de uso das funções
array = [5, 3, 6, 2, 10]
array_ordenado = ordenacaoPorSelecao(array)
imprimirArray(array_ordenado)  # Chama a função para imprimir o array ordenado
