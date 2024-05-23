def sequential_search(arr, target):
    
    # Itera sobre todos os elementos do array
    for i in range(len(arr)):
        # Verifica se o elemento atual é igual ao alvo
        if arr[i] == target:
            # Retorna o índice do elemento alvo se encontrado
            return i
    # Se o alvo não for encontrado, retorna -1
    return -1

# Exemplo de utilização da função
arr = [5, 3, 8, 6, 2]
target = 8
result = sequential_search(arr, target)
if result != -1:
    print(f'O elemento {target} foi encontrado no índice {result}.')
else:
    print(f'O elemento {target} não foi encontrado.')
