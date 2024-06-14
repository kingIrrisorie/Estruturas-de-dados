from collections import deque

# Definindo a classe Fila
class Fila:
    # Inicializa a fila com um tamanho máximo opcional
    def __init__(self, numeroMaximoDeItensNaFila=None):
        # Cria uma deque (fila) com um tamanho máximo, se especificado
        self.fila = deque(maxlen=numeroMaximoDeItensNaFila)
    
    # Adiciona um item na fila (push)
    def enfileirar(self, numero):
        if self.estaCheia():
            print("Fila está cheia")  # Mensagem indicando que não é possível adicionar mais itens
        else:
            self.fila.append(numero)  # Adiciona o item no final da fila

    # Remove um item da fila (pop)
    def desenfileirar(self):
        if self.estaVazia():
            print("A fila já está vazia")  # Mensagem indicando que não há itens para remover
        else:
            return self.fila.popleft()  # Remove e retorna o item do início da fila
    
    def estaVazia(self):
        # Retorna True se a fila estiver vazia, caso contrário, False
        return len(self.fila) == 0


    def estaCheia(self):
        # Verifica se um tamanho máximo foi definido para a fila
        if self.fila.maxlen is not None:
            # Verifica se o tamanho atual da fila é igual ao tamanho máximo permitido
            if len(self.fila) == self.fila.maxlen:
                return True  # A fila está cheia
        return False  # A fila não está cheia ou não tem um tamanho máximo definido

    def tamanho(self):
        # Retorna a quantidade de itens na fila
        return len(self.fila)

    def mostrarFila(self):
        if self.estaVazia():
            print("Fila está vazia")
        else:
            # Imprime todos os itens na fila em formato de lista
            print("[", end="")
            for i, item in enumerate(self.fila):
                if i == len(self.fila) - 1:
                    print(f"{item}", end="")  # Para o último item, não coloca uma vírgula
                else:
                    print(f"{item}, ", end="")  # Para os demais itens, coloca uma vírgula e um espaço
            print("]")  # Fecha a lista visualmente

fila = Fila(3)  # Cria uma fila com tamanho máximo de 3 itens
# Outra forma
# fila = Fila(numeroMaximoDeItensNaFila=3)

fila.enfileirar(1)  # Adiciona o número 1
fila.enfileirar(2)  # Adiciona o número 2
fila.enfileirar(3)  # Adiciona o número 3
fila.enfileirar(4)  # Tenta adicionar o número 4 na fila, mas a fila está cheia

fila.mostrarFila()  # Deve exibir [1, 2, 3]

# Remove alguns itens da fila
fila.desenfileirar()  # Remove o primeiro item (1)
fila.desenfileirar()  # Remove o próximo item (2)
fila.desenfileirar()  # Remove o próximo item (3)
fila.desenfileirar()  # Tenta remover um item, mas a fila está vazia

fila.enfileirar(1)  # Adiciona o número 1 na fila novamente

fila.mostrarFila()  # Deve exibir [1]
