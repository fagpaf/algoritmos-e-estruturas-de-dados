linhas = int(input())
colunas = int(input())
matriz = []
# Formando a Matriz
for i in range(linhas):
  andar = []
  for j in range(colunas):
    elemento = int(input())
    andar.append(elemento)
  matriz.append(andar)
# Printando a Matriz
for n in range(linhas):
  linha_atual = " ".join(map(str, matriz[n]))
  print(linha_atual)
print()
# Encontrando o chalé com mais campistas
number_chale = 0
qtd_campistas = 0
for x in range(linhas):
  soma_atual = sum(matriz[x])
  if soma_atual > qtd_campistas:
    qtd_campistas = soma_atual
    number_chale = x + 1
print(f'O chalé {number_chale} foi o que mais recebeu semi-deuses, tendo um acréscimo de {qtd_campistas} novos campistas!')
