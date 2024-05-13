arr = [5, 2, 1, 7, 0]

def merge(Array, inicio, fim):
    # Criando uma lista temporária para armazenar os valores mesclados
    temp = [0] * len(Array)
   
    # Encontrando o ponto médio
    meio = (inicio + fim) // 2
   
    # Inicializando os índices para as duas metades do array
    i1 = inicio
    i2 = meio + 1 
   
    # Loop para mesclar as duas metades do array
    for j in range(inicio, fim + 1):
      
        # Caso a primeira metade seja totalmente utilizada
        if i1 == meio + 1:
            temp[j] = Array[i2]
            i2 += 1
      
        # Caso a segunda metade seja totalmente utilizada
        elif i2 > fim:
            temp[j] = Array[i1]
            i1 += 1
      
        # Caso o elemento da primeira metade seja menor ou igual ao elemento da segunda metade
        elif Array[i1] <= Array[i2]:
            temp[j] = Array[i1]
            i1 += 1
      
        # Caso o elemento da segunda metade seja menor que o elemento da primeira metade
        else:
            temp[j] = Array[i2]
            i2 += 1

    # Copiando os elementos mesclados de volta para o array original
    for cursor in range(inicio, fim + 1):
       Array[cursor] = temp[cursor]

def mergesort(Array, inicio, fim):
    # Verifica se há mais de um elemento no subarray
    if inicio < fim:
        # Calcula o ponto médio do subarray
        meio = (inicio + fim) // 2
       
        # Chamada recursiva para ordenar a primeira metade do subarray
        mergesort(Array, inicio, meio)
       
        # Chamada recursiva para ordenar a segunda metade do subarray
        #mergesort(Array, meio + 1, fim)
       
        # Mescla as duas metades ordenadas
        merge(Array, inicio, fim)

mergesort(arr, 0, len(arr) - 1)
print("Array ordenado:", arr)
