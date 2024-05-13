# Formando as def's
def organizar_malas(lista_pesos_malas):
    lista_pesos_malas = list(map(int, lista_pesos_malas))
    lista_pesos_malas.sort()
    lista_pesos_malas[0], lista_pesos_malas[-1] = lista_pesos_malas[-1], lista_pesos_malas[0]
    lista_pesos_malas[1], lista_pesos_malas[-2] = lista_pesos_malas[-2], lista_pesos_malas[1]
    return lista_pesos_malas

def parametros(qtd_blocos_carvao, peso, num_de_passageiros):
    velocidade = (qtd_blocos_carvao + 200) // 2
    carga = (peso + 4000) // 1000
    total_pessoas = num_de_passageiros + 40
    return velocidade, carga, total_pessoas

def turno(lista_funcionarios, horario, roteiro):
    hora, minutos = map(int, horario.split(':'))
    horario = hora + minutos / 60
    if 7 < horario < 21 and roteiro == "Roteiro 1":
        convocados = lista_funcionarios[0], lista_funcionarios[1]
    elif  7 < horario < 21 and roteiro == "Roteiro 2":
        convocados = lista_funcionarios[0], lista_funcionarios[-1]
    elif 21 <= horario <= 7  and roteiro == "Roteiro 1":
        convocados = lista_funcionarios[2]
    else:
        convocados = [] 
    return convocados
# Def Principal
def protocolo_de_inicio():
    lista_pesos_malas = input().split(", ")
    lista_correta = ", ".join(map(str, organizar_malas(lista_pesos_malas)))
    print(f"A nova organização das malas é a seguinte: {lista_correta}")
    input_parametros = input().split(", ")
    qtd_blocos_carvao = int(input_parametros[0])
    peso = int(input_parametros[1])
    num_de_passageiros = int(input_parametros[2])
    parametros_certos = parametros(qtd_blocos_carvao, peso, num_de_passageiros)
    print(f"A velocidade que o trem partirá é de: {parametros_certos[0]}Km/H") 
    print(f"A carga do Trem em Toneladas é: {parametros_certos[1]} Ton.") 
    print(f"A quantidade de passageiros é de {parametros_certos[2]}")
    lista_funcionarios = input().split(", ")
    horario = input()
    roteiro = input()
    
    funcionarios_convocados = turno(lista_funcionarios, horario, roteiro)
    if funcionarios_convocados:
        print(f"Os funcionários convocados são: {', '.join(funcionarios_convocados)}")
    else:
        print("Nenhum funcionário convocado para esse turno.")

protocolo_de_inicio()
