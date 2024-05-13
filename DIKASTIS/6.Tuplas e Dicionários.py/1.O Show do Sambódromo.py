escolas_de_samba = ("Porto da Pedra", "Beija-flor", "Salgueiro", "Grande Rio", "Unidos da Tijuca", "Imperatriz", "Mocidade", "Portela", "Vila Isabel", "Mangueira", "Paraíso do Tuiuti", "Viradouro")
dict_escolas = {}
lista_primeira_aparicao = []
encerrar = False
# Loop para receber os inputs e formar o dicionário
while not encerrar:
  escola = input()
  if escola == "Fim":
    encerrar = True
  else:
    chave, valor = escola.split(":")
    # Verifica se a chave já existe no dictonário
    if chave in dict_escolas:
      print(f"{chave} teve sua nota atualizada!")
    dict_escolas[chave] = float(valor)
    # Verifica se a chave pertence a tupla inical
    if chave not in escolas_de_samba:
      print("Epa, o que essa escola está fazendo aqui?!")
    else:
      # Verifica se é a primeira aparição da chave
      if chave not in lista_primeira_aparicao:
        print(f"{chave} teve sua nota apurada!")
        lista_primeira_aparicao.append(chave)
    if chave not in escolas_de_samba:
      del dict_escolas[chave]
print("")
print("CLASSIFICAÇÃO DO CARNAVAL 2024:")
#Função Sorted para criar uma lista organizando o dicionário em ordem decrescente de notas.
sorted_escolas = sorted(dict_escolas, key = dict_escolas.get, reverse = True)
idx = 1
#For para iterar sobre cada chave do dicionário.
for key in sorted_escolas:
  #Value = dict_escolas[key] recebe o valor da chave percorrida no for, assim printando a chave e o valor correto
  value = dict_escolas[key]
  print(f"{idx}. {key}: {value}")
  idx += 1
print("")
#Criando duas variáveis para o código ficar mais legível no print
primeira_colocada = sorted_escolas[0]
ultima_colocada = sorted_escolas[-1]
print(f"É CAMPEÃ! A ESCOLA {primeira_colocada} É A GRANDE VENCEDORA DO CARNAVAL DE 2024, FAZENDO {dict_escolas[primeira_colocada]} PONTOS!!")
print(f"Infelizmente, a escola {ultima_colocada} não alcançou as expectativas, fazendo apenas {dict_escolas[ultima_colocada]} pontos, e foi rebaixada.")