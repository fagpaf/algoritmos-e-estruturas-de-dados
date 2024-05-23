arr = [89, 45, 68, 90, 29, 34, 17]

# Loop sobre o array a partir do segundo elemento
for i in range(1, len(arr)):
    
    # Armazena o valor do elemento atual
    v = arr[i]
    
    # Inicializa um índice para o elemento anterior
    j = i - 1 

    # Enquanto o índice anterior for válido e o elemento for maior que o valor atual
    while j >= 0 and arr[j] > v:
        
        # Desloca o elemento para a direita
        arr[j+1] = arr[j]
        
        # Decrementa o índice para verificar o próximo elemento à esquerda
        j -= 1
        
        # Insere o valor atual na posição correta
        arr[j+1] = v

# Imprime o array ordenado
print(arr)
