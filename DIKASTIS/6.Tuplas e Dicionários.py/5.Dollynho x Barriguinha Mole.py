def popo_x_bambam(vida_dolly, ataque_dolly, defesa_dolly, adversario, vida_inimigo, ataque_inimigo, defesa_inimigo):
    # Verifica se a vida de Dollynho é menor ou igual a 0
    if vida_dolly <= 0:
        return True
    # Reduz a vida do inimigo com base no ataque do Dollynho e defesa do inimigo
    vida_inimigo -= ataque_dolly - defesa_inimigo

    # Verifica se o inimigo foi derrotado
    if vida_inimigo <= 0:
        print(f"O {adversario} foi derrotado!")
        print(f"STATUS DOLLY")
        print(f"Vida: {vida_dolly}")
        return False
    # Se o inimigo ainda está vivo, reduz a vida de Dollynho com base no ataque do inimigo e defesa do Dollynho
    else: 
        vida_dolly -= ataque_inimigo - defesa_dolly
        if vida_dolly <= 0:
            print("Que tristeza! Dollynho se foi!")
            return True
    # Se ambos ainda têm vida continua a batalha recursivamente
    if (vida_dolly > 0) and (vida_inimigo > 0):
        return popo_x_bambam(vida_dolly, ataque_dolly, defesa_dolly, adversario, vida_inimigo, ataque_inimigo, defesa_inimigo)

# Input's
vida_dolly = int(input())
ataque_dolly = int(input())
defesa_dolly = int(input())

qtd_inimigos = int(input())

dict_inimigos = {}
# Criando o dicionário com informações sobre os inimigos
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
    # Caso Dolly tenha sido derrotado
    if vencedor == True:
        print(f"Infelizmente Dollynho não conseguiu vencer todos os Barriguinhas Moles…")
        print(f"Pelo menos levou {qtd_inimigos_derrotados} baderneiros com ele!")
    else:
        print(f"OBA! Dolly venceu todos os inimigos!")
