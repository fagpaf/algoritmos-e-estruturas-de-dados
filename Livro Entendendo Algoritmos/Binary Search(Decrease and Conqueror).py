def pesquisa_binaria(lista, alvo):
    
    baixo = 0
    alto = len(lista) - 1
    while baixo <= alto:
        meio = (baixo + alto) // 2
        chute = lista[meio]
        if chute == alvo:
            return chute
        elif chute > alvo:
            alto = meio - 1
        else:
            baixo = meio + 1
    return None

minha_lista = [1, 2, 3, 4, 5]
for j in minha_lista:
    alvo = j + 2
    
    print(pesquisa_binaria(minha_lista, alvo))
