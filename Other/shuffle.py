# import random

# def shuffle(ary): # adding ary as an argument
 
#     a = len(ary) # what is the length of the array
 
#     b = a - 1   # b is the array minus one
                            
#     for d in range(b,0,-1): # Iterate over the array
 
#         e = random.randint(0,d) # Lets generate a random number
 
#         if e == d: # continue if the last number is the same as the random number thrown
#             ary[d],ary[e]=ary[e],ary[d]
#             return ary

#int* permutation(int size){ // Cria uma permutação baseada no algoritmo de Fischer-Yates
#    int* perm = (int*)malloc((size-1) * sizeof(int));
#    // Algoritmo de Fischer-Yates
#    for(int i = size - 2; i > 0; i--){
#        int j = rand() % (i+1);   // Gera um índice aleatório 'j' entre 0 e 'i' 
#        int temp = perm[i];
#        perm[i] = perm[j];
#        perm[j] = temp;
#        // Esse 'for' faz o embaralhamento do array trocando
#    }
#    return perm;
#}



# text1 = """Pre order : 5 3 2 4 7 6 8
# In order  : 2 3 4 5 6 7 8
# Post order: 2 4 3 6 8 7 5
# """

# text2 = """Pre order : 5 3 2 4 7 6 8
# In order  : 2 3 4 5 6 7 8
# Post order: 2 4 3 6 8 7 5"""

# if text1 == text2:
#     print("Os textos são idênticos")
# else:
#     print("Os textos são diferentes")


# while True:
#     print(f"FLAVINHO GOSTOSO")

def popo_x_bambam(vida_dolly, ataque_dolly, defesa_dolly, adversario, vida_inimigo, ataque_inimigo, defesa_inimigo):
    
    if vida_dolly <= 0:
        return True
    vida_inimigo -= ataque_dolly - defesa_inimigo
    if vida_inimigo <= 0:
        print(f"O {adversario} foi derrotado!")
        print(f"STATUS DOLLY")
        print(f"Vida: {vida_dolly}")
        return False
    else:
        vida_dolly -= ataque_inimigo - defesa_dolly
        if vida_dolly <= 0:
            return True
    if (vida_dolly > 0) and (vida_inimigo > 0):
        return popo_x_bambam(vida_dolly, ataque_dolly, defesa_dolly, adversario, vida_inimigo, ataque_inimigo, defesa_inimigo)


vida_dolly = int(input())
ataque_dolly = int(input())
defesa_dolly = int(input())

qtd_inimigos = int(input())

dict_inimigos = {}

for i in range(qtd_inimigos):
    
    nome_inimigo = input()
    vida_inimigo = int(input())
    ataque_inimigo = int(input())
    defesa_inimigo = int(input())
    dict_inimigos[nome_inimigo] = [vida_inimigo, ataque_inimigo, defesa_inimigo]

if qtd_inimigos == 0:
    print(f"Oba! Sem intercorrências pelo caminho! Podemos ir para o carnaval em paz!")
else:
    print(f"Oh não! Eles querem acabar com o meu Dollynho!")

    qtd_inimigos_derrotados = 0
    for adversario in dict_inimigos.keys():
        vida_inimigo = dict_inimigos[adversario][0]
        ataque_inimigo = dict_inimigos[adversario][1]
        defesa_inimigo = dict_inimigos[adversario][2]
        vencedor = popo_x_bambam(vida_dolly, ataque_dolly, defesa_dolly, adversario, vida_inimigo, ataque_inimigo, defesa_inimigo)
        if vencedor == False:
            qtd_inimigos_derrotados += 1
    if vencedor == True:
        print("Que tristeza! Dollynho se foi!")
        print(f"Infelizmente Dollynho não conseguiu vencer todos os Barriguinhas Moles…")
        print(f"Pelo menos levou {qtd_inimigos_derrotados} baderneiros com ele!")
    else:
        print(f"OBA! Dolly venceu todos os inimigos!")
