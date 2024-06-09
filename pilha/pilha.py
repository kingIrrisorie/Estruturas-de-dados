# Criando uma pilha usando uma lista em Python. 
# As listas em Python têm métodos que nos permitem simular o comportamento de uma pilha.

# Inicializamos uma lista vazia para representar a pilha
pilha = []

# Operação de empilhar (push): Adiciona um elemento ao topo da pilha.  
pilha.append(1)  # Pilha: [1]
pilha.append(2)  # Pilha: [1, 2]
pilha.append(3)  # Pilha: [1, 2, 3]

# Mostrando a pilha
# Resultado: [1, 2, 3]
print("Essa é a pilha:", pilha)

# Operação de desempilhar (pop): Remove e retorna o elemento do topo da pilha.
# Usamos o método pop() da lista para isso.
elemento_removido = pilha.pop()  # elemento_removido = 3, Pilha agora é [1, 2]
print("Esse é o elemento removido:", elemento_removido)
# Mostrando a pilha
# Resultado: [1, 2]
print("Essa é a pilha:", pilha)

# Operação de olhar o topo da pilha: Apenas verifica o elemento do topo sem removê-lo.
# Para isso, acessamos o último elemento da lista.
# Usamos -1 para acessar o último elemento da lista.
topo_da_pilha = pilha[-1]  # topo_da_pilha = 2
print("Esse é o topo da pilha:", topo_da_pilha)

# Verificar se a pilha está vazia: Podemos checar se o comprimento da lista é zero.
esta_vazia = len(pilha) == 0  # esta_vazia = False (pois a pilha tem elementos)


# Empilhando mais elementos
pilha.append(4)  # Pilha: [1, 2, 4]
pilha.append(5)  # Pilha: [1, 2, 4, 5]

print(pilha)

# Desempilhando mais elementos
elemento_removido = pilha.pop()  # elemento_removido = 5, Pilha agora é [1, 2, 4]
elemento_removido = pilha.pop()  # elemento_removido = 4, Pilha agora é [1, 2]
print(pilha)

# Verificando o topo novamente
topo_da_pilha = pilha[-1]  # topo_da_pilha = 2

# Verificando se a pilha está vazia novamente
esta_vazia = len(pilha) == 0  # esta_vazia = False

# Desempilhando todos os elementos restantes
elemento_removido = pilha.pop()  # elemento_removido = 2, Pilha agora é [1]
elemento_removido = pilha.pop()  # elemento_removido = 1, Pilha agora é []

# Verificando se a pilha está vazia depois de desempilhar tudo
esta_vazia = len(pilha) == 0  # esta_vazia = True
