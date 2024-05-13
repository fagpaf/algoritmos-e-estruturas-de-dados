# Itens que Procura
lista_deseja = input().split(', ')

# Itens Encontrados no Acampamento 
lista_encontrou = input().split(', ')

# Itens em Comum
qtd_list_deseja = 0
n = 0
lista_agrupamento = []
idx = 1
for i in lista_deseja:
  if i in lista_encontrou:
    lista_agrupamento.append(i)
    n += 1
  else:
    qtd_list_deseja += 1
if n != 0:
  print('Estes são os itens que já tenho no Acampamento Meio-Sangue:')
  for objeto in lista_agrupamento:
    print(f'{idx}º item: {objeto}')
    idx += 1
else:
  print(f'Hmm, preciso visitar um vendedor ambulante! Não encontrei nenhum dos {qtd_list_deseja} itens aqui no Acampamento Meio-Sangue.')

# Itens Para Comprar
qtd_itens_deseja = len(lista_deseja)
it_comprar = 0
lista_compras = []
for j in lista_deseja:
  if j not in lista_encontrou:
    lista_compras.append(j)
    it_comprar += 1
if (it_comprar) != 0 and len(lista_compras) < len(lista_deseja):
  print(f'Vou precisar adquirir {it_comprar} itens antes da batalha!')
elif (it_comprar) == 0:
  print(f'Perfeito, encontrei todos os {qtd_itens_deseja} itens aqui no Acampamento Meio-Sangue!')
print('Estou pronto para a batalha! Que comece a guerra contra os Titãs!')