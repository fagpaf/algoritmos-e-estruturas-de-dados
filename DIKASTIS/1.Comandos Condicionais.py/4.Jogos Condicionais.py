nome_vitima = input()
nome_antagonista = input()
tipo_armadilha = input()
tempo = int(input())
if nome_antagonista == 'John Kramer':
  if tipo_armadilha == 'Armadilha de urso reversa':
    if 300 <= tempo:
      print(f'Com tempo de sobra, {nome_vitima} consegue retirar a armadilha de sua cabeça, sobrevivendo com sucesso ao jogo de Jigsaw.')
    elif  150 <= tempo <= 300:
      print(f'À beira de perder a cabeça, e desafiando as expectativas de seu algoz, {nome_vitima} remove a armadilha de urso e por pouco escapa de um destino cruel.')
    else:
      print('Game Over...')
  elif tipo_armadilha == 'Tanque de agua':
    if 240 <= tempo:
      print(f'{nome_vitima} usa suas práticas de respiração na natação a seu favor, vencendo o jogo de Jigsaw sem perder muito fôlego.')
    elif 120 <= tempo < 240:
      print(f'{nome_vitima} passa por maus bocados, mas vira o jogo e consegue evitar, no limite, seu afogamento dentro da armadilha.')
    else:
      print('Game Over...')

elif nome_antagonista == 'Amanda Young':
  if tipo_armadilha == 'Caixa de laminas':
    if 600 <= tempo:
      print(f'Apenas com ferimentos leves, {nome_vitima} se liberta rapidamente das perigosas lâminas da armadilha montada pela discípula de Jigsaw.')
    elif 360 <= tempo < 600:
      print(f'Por um triz, {nome_vitima} sobrevive ao jogo de Amanda, mas com lesões profundas em suas mãos e braços.')
    else:
      print('Game Over...')
  if tipo_armadilha == 'Asas de anjo':
    if 180 <= tempo:
      print(f'Com surpreendente facilidade, {nome_vitima} alcança a chave da armadilha e vence o desafio da aprendiz de Jigsaw.')
    elif 90 <= tempo < 180:
      print(f'{nome_vitima} desafia as possibilidades e o cruel anseio de sua algoz, escapando da armadilha com poucas queimaduras e arranhões.')
    else:
      print('Game Over...')