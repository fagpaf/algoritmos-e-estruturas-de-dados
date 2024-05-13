def verificao_de_estoque(dict_ingredientes, dict_receitas, dict_estoque, dict_pedidos, caixa):
    result = caixa
    custo_reposicao = 0 
    # Iterando sobre os pedidos e suas quantidades
    for pedidos in dict_pedidos.keys():
        ingredientes_pedido = dict_receitas[pedidos]

        # Verificando o estoque para cada ingrediente do pedido
        for ingrediente in ingredientes_pedido:
          if dict_estoque[ingrediente] < 1: # Se o estoque do ingrediente for menor que 1
            custo_reposicao += reposicao_do_estoque(dict_ingredientes, dict_receitas, dict_estoque[ingrediente], dict_pedidos, caixa)
    caixa -= custo_reposicao
    return result

def reposicao_do_estoque(dict_ingredientes, dict_receitas, dict_estoque, dict_pedidos, caixa):
    
    result = verificao_de_estoque(dict_ingredientes, dict_receitas, dict_estoque, dict_pedidos, caixa)
    # Calcula o custo total da reposição 
    ingrediente_reposicao = dict_estoque
    caixa -= 4 * dict_ingredientes[ingrediente_reposicao]
    
    # Adiciona 4 unidades a todos os ingredientes que precisam ser repostos
    dict_estoque[ingrediente_reposicao] += 4
    
    return result

def preparacao_do_pedido(dict_estoque, dict_pedidos, dict_receitas):
    result = True
    for pedidos in dict_pedidos.keys(): # O mesmo da def verificacao_de_estoque
        ingredientes_pedido = dict_receitas[pedidos]

    # Subtrai 1 unidade de cada ingrediente utilizado no pedido do estoque
    for ingredientes_receita in ingredientes_pedido:
        if dict_estoque[ingredientes_receita] > 0:
            dict_estoque[ingredientes_receita] -= 1
    return result


def financas(dict_pedidos, dict_precos, caixa):
    lucro = 0
    lucro = float(lucro)

    # Calcula o total de vendas com base nos preços das receitas e as quantidades pedidas
    total_de_vendas = 0
    for pedido_cliente, quantidade in dict_pedidos.items():
        preco = dict_precos.get(pedido_cliente, 0)
        total_item = quantidade * preco # Calcula o total dos pedidos
        total_de_vendas += total_item
        
    # Calcula o lucro somando o total de vendas ao valor inicial do caixa
    lucro += (total_de_vendas + caixa)
    return lucro


caixa = 30
dict_receitas = {
    "bobo de camarao": ("camarao", "macaxeira", "leite de coco", "dende", "tomate", "cebola"),
    "tapioca de carne de sol": ("massa de tapioca", "carne de sol", "queijo coalho", "tomate", "cebola"),
    "carne de sol com macaxeira": ("carne de sol", "macaxeira", "manteiga"),
    "camarao na moranga": ("moranga", "camarao", "cebola", "alho", "tomate", "pimentao", "creme de leite", "azeite", "coentro")
}
dict_ingredientes = {
    "coentro": 1.00,
    "alho": 1.50,
    "cebola": 2.00,
    "pimentao": 2.00,
    "macaxeira": 3.00,
    "tomate": 3.00,
    "creme de leite": 4.00,
    "leite de coco": 5.00,
    "manteiga": 5.50,
    "moranga": 10.00,
    "massa de tapioca": 10.00,
    "dende": 15.00,
    "azeite": 15.00,
    "queijo coalho": 15.00,
    "camarao": 30.00,
    "carne de sol": 30.00,
}
# Criando o estoque do restaurante
dict_estoque = {}
for ingrediente in dict_ingredientes:
    dict_estoque[ingrediente] = 5

# Loop dos inputs e criando o dicionário de pedido para saber qual o mais vendido
dict_pedidos = {}
condicional = 0
loop = False
while not loop:
    try:
        pedido = input()
        if pedido not in dict_receitas:
            condicional += 1
            if condicional == 3: # Limita as duas entradas do pedido
                print(f"Atendendo demandas, {pedido} é a mais nova adição ao cardápio do Sabores de Recife.")
                # Tupla para ser concatenada e ser o valor da nova receita no dict_receitas
                tupla_ingredientes = ()
                for i in range(9):
                    tupla = input(), 
                    tupla_ingredientes += tupla # Concatenando a tupla para "adicionar" os ingredientes do novo pedido
                dict_receitas[pedido] = tupla_ingredientes
                # Criando o dict_pedidos
                if pedido not in dict_pedidos:
                    dict_pedidos[pedido] = 0 #recebe 0 pq ele foi adicionadoao cardápio neste momento
                else:
                    dict_pedidos[pedido] += 1
            else:
                print(f"{pedido} ainda não é uma opção disponível.")
        else:
            print(f"{pedido} saindo...")
            # Criando o dict_pedidos
            if pedido not in dict_pedidos:
                dict_pedidos[pedido] = 1
            else:
                dict_pedidos[pedido] += 1
    except EOFError:
        loop = True
print("##### Fim do expediente #####")

# Criando um dicionário para o custo de cada receita
dict_precos = {}
for chave, valor in dict_receitas.items():
    custo_total = 0
    # Percorrendo a tupla para calcular o valor de cada ingrediente
    for ingrediente in valor:
        custo_total += dict_ingredientes.get(ingrediente, 0) #.get() recebe 0 como valor padrão para evitar quebra do código
    if chave != "bobo de camarao" and chave != "tapioca de carne de sol" and chave !="carne de sol com macaxeira" and chave != "camarao na moranga":
        dict_precos[chave] = (custo_total + 5) # Adicionando os 5 reais q a questão ordena
    else:
        dict_precos[chave] = custo_total

num_pedidos =  sum(dict_pedidos.values())

while num_pedidos > 0:
    dispensa = verificao_de_estoque(dict_ingredientes, dict_receitas, dict_estoque, dict_pedidos, caixa)  
    prato = preparacao_do_pedido(dict_estoque, dict_pedidos, dict_receitas)
    if num_pedidos == 1:
        lucro = financas(dict_pedidos, dict_precos, caixa) # Restaurante em alavancagem

    num_pedidos -= 1

lucro -= 30
print(f"O lucro obtido no dia de hoje foi de R${lucro:.2f}.")

# Usando "max" para determinar o pedido mais vendido e .capitalize() para iniciar o nome do pedido com letra maiúscula
mais_vendido = max(dict_pedidos, key = dict_pedidos.get)
if mais_vendido == "bobo de camarao":
    print("O bom e tradicional Bobó de Camarão, líder em vendas, nunca será superado!")
else:
    print(f"{mais_vendido.capitalize()} está fazendo sucesso entre os clientes, ultrapassando até mesmo o lendário Bobó de Camarão.")






