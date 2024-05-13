nome_missao = input()
nome_semideus = ''
grupo_de_herois = []
loop = True
while loop:
  nome_semideus = input()
  if nome_semideus != 'Grupo formado':
    grupo_de_herois.append(nome_semideus)
  else:
    loop = False
print(f'O grupo formado por {len(grupo_de_herois)} heróis para a missão {nome_missao} foi:')
for heroi in (grupo_de_herois):
  print(f'- {heroi}')