lista_total = []
loop = False
while not loop:
  escola = input()
  if escola == "Não há mais escolas":
    loop = True
  else:
    tema_desfile = input()
    tempo_limite = int(input())
    lista_total.append([escola, tema_desfile, tempo_limite])

# Criando um dicionário com Listas para facilitar o uso dele
dict_avaliacoes = {}
continuar = False
while not continuar:
  lista_do_dicionario = [] # Essa Lista irá receber as Notas dos input's
  quesito = input()
  if quesito == "Não há mais quesitos":
    continuar = True
  else:
    # Utilizando for para não ter erro na montagem do dicionário e renovar o input da Nota
    for i in range(len(lista_total)):
      avaliacao = input()
      nome_escola, nota = avaliacao.split(" - ")
      nota = float(nota)
      lista_do_dicionario.append([nome_escola, nota])
    if len(lista_do_dicionario) == len(lista_total):
      # O Valor é a Lista 
      dict_avaliacoes[quesito] = lista_do_dicionario
#-------------------------------------------------------
# Ignorando a segunda e terceira variáveis em cada lista
#for escola, _, _ in lista_total:
#    print(escola)
#-------------------------------------------------------
# Criando um dicionário para relacionar a escola a sua respectiva nota no quesito
dict_notas = {}
for chave in dict_avaliacoes:
  for i in range(len(dict_avaliacoes[chave])):
    escola_rj, nota = dict_avaliacoes[chave][i]
    # Verifique se a escola já está no novo dicionário
    if escola_rj not in dict_notas:
      dict_notas[escola_rj] = [nota]  # Inicializa como uma lista para poder adicionar
    else:
      dict_notas[escola_rj].append(nota)

# Dicionário para encontrar a maior média e a escola campeã
dict_media = {}
for idx in range(len(lista_total)): # Iterando a lista dos input's iniciais para acessar o dicinário de notas e o tempo limite de apresentação
  escola = lista_total[idx][0]
  tempo = lista_total[idx][2]
  for i in dict_notas:
    # Somando e fazendo a média 
    soma_notas = sum(dict_notas[escola][:])
    media = (soma_notas / len(dict_avaliacoes))
    # Satisfazendo as condicionais iniciais do limite de tempo para a apresentação
    if 65 < tempo < 75:
      media += 0 
    elif tempo < 65:
      diferença = (tempo - 65) * 0.1
      media += diferença
    else:
      diferença = (75 - tempo) * 0.1
      media += diferença
  dict_media[escola] = (round(media, 2)) # Deixando o resultado em duas casas decimais

# Usando max para determinar o 1 lugar no dicionário
nome_vencedor = max(dict_media, key=dict_media.get)
nota_vencedor = max(dict_media.values())
print(f"E o vencedor do desfile de escola de samba do Rio de Janeiro de 2024 é:\n{nome_vencedor} com uma nota final de {nota_vencedor}!")