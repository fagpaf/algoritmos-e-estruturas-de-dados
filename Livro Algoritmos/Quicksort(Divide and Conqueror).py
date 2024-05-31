arr = [7, 1, 3, 1, 4, 10, 8]

def HoareParticion(Array, inicio, fim):
    
    # Define o pivô como o primeiro elemento do array
    pivo = Array[inicio]
    i = inicio
    j = fim + 1
    
    # Enquanto i não ultrapassar j, o loop continua
    while not(i >= j):
        
        i+=1
        # Encontra o próximo elemento maior ou igual ao pivô a partir da esquerda
        while not (Array[i] >= pivo or i >= fim):
            i += 1
        
        # Encontra o próximo elemento menor ou igual ao pivô a partir da direita        
        j -= 1 # No do while essa linha não é necessária
        
        while not (Array[j] <= pivo):
            j -= 1
        
        # Troca os elementos se i ainda não ultrapassou j
        Array[i], Array[j] = Array[j], Array[i]

    # Troca o pivô com o último elemento menor ou igual ao pivô
    Array[i], Array[j] = Array[j], Array[i]
    
    # Coloca o pivô na posição correta
    Array[inicio], Array[j] = Array[j], Array[inicio]
    
    # Retorna o índice do pivô
    return j

def quicksort(Array, inicio, fim):
    # Verifica se ainda há elementos para ordenar
    if inicio < fim:
        
        # Realiza a partição do array
        s = HoareParticion(Array, inicio, fim)
        
        # Chama recursivamente a função para ordenar as partições à esquerda e à direita do pivô
        quicksort(Array, inicio, s-1)
        quicksort(Array, s+1, fim)

quicksort(arr, 0, len(arr)-1)
print(arr)

