grego_antigo = input()
lista = []
frase_decifrada = []
contem_algarismo = False
# Verifica se a Mensagem é um Espaço Vazio
if grego_antigo == " ":
  print('Ué não tem nada para me decifrar aqui')
# Iterando o Input para Somar com o ord()
else:
  for char in grego_antigo:
    lista.append(char)
# Descobrindo o Valor Decimal e o Caractere da Tabela ASCII
  for char in grego_antigo:
    if char == " ":
      frase_decifrada.append(" ")       
    else:
      n = ord(char)
      soma = n + len(lista)
      caractere = chr(soma)
      frase_decifrada.append(caractere)
  # Verifica se o Caractere é um Algarismo de 0-9
      # fazer lista de 0/9 para funcionar
      if '0' <= caractere <= '9':
        contem_algarismo = True
if contem_algarismo:
  print("Algo de errado não está certo. Será que estou ficando doido?")
else:
  print('Descobri o que a mensagem significa: ' + "".join(frase_decifrada))