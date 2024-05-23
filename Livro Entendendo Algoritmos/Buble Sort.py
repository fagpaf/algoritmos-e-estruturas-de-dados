def bubble_sort(arr):

    n = len(arr)
    
    # Percorre o array n vezes
    for i in range(n):
        # Flag para indicar se houve troca durante esta iteração
        swapped = False
        
        # Percorre o array até o penúltimo elemento
        for j in range(n - 1 - i):
            # Compara o elemento atual com o próximo elemento
            if arr[j] > arr[j + 1]:
                # Troca os elementos se estiverem fora de ordem
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                # Define a flag como True para indicar que houve troca
                swapped = True
        
        # Se não houve troca durante esta iteração, o array está ordenado
        if not swapped:
            break

# Exemplo de utilização da função
arr = [64, 34, 25, 12, 22, 11, 90]
bubble_sort(arr)
print("Array ordenado:")
print(arr)
