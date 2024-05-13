min = 0
musicas = int()
ouvindo = True
comentario = 0
while(ouvindo):
  if musicas < 21  :
    opiniao = input()
    if opiniao == 'amei':
      min += 4
      musicas += 1 
    elif opiniao == 'não parei de ouvir':
      musicas += 1
      repetir = True
      comentario = 0
      while(repetir):
        opiniao1 = input()
        if opiniao1 == 'pulei':
          repetir = False
          min += 4 * comentario
        else:
          comentario += 1
    elif opiniao == 'essa não deu':
      musicas += 1
      min += 0
    elif opiniao == 'escutei só metade':
      musicas += 1
      min += 2
    elif opiniao == 'parei':
      musicas += 0
      ouvindo = False
      print(f'Você ouviu {min} minutos hoje!!!')
  elif musicas == 21:
    ouvindo = False
    print(f'Você ouviu {min} minutos hoje!!!')