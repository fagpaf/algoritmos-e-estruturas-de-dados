# def sequential_search(arr, data):
    
#     # Itera sobre todos os elementos do array
#     for i in range(len(arr)):
#         # Verifica se o elemento atual é igual ao alvo
#         if arr[i] == data:
#             # Retorna o índice do elemento alvo se encontrado
#             return i
#     # Se o alvo não for encontrado, retorna -1
#     return -1

# try:
#     with open('input.txt', 'r') as file:
#         data = file.read()
#     arr = [5, 3, 8, 6, 2]
#     print(data)
#     result = sequential_search(arr, data)
#     if result != -1:
#         print(f'O elemento {data} foi encontrado no índice {result}.')
#     else:
#         print(f'O elemento {data} não foi encontrado.')
# except FileNotFoundError:
#     print("Arquivo 'input.txt' não encontrado.")

def sequential_search(arr, data):
    # Itera sobre todos os elementos do array
    for i in range(len(arr)):
        # Verifica se o elemento atual é igual ao alvo
        if arr[i] == data:
            # Retorna o índice do elemento alvo se encontrado
            return i
    # Se o alvo não for encontrado, retorna -1
    return -1

try:
    with open('input.txt', 'r') as file:
        data = file.read().strip()  # Remove espaços em branco e nova linha
        data = int(data)  # Converte a string lida para um inteiro

    arr = [5, 3, 8, 6, 2]
    print(f"Procurando o elemento: {data}")

    result = sequential_search(arr, data)
    if result != -1:
        print(f'O elemento {data} foi encontrado no índice {result}.')
    else:
        print(f'O elemento {data} não foi encontrado.')
except FileNotFoundError:
    print("Arquivo 'input.txt' não encontrado.")
except ValueError:
    print("O conteúdo do arquivo não é um número válido.")
