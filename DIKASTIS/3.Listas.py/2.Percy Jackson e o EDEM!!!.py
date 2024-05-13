q = int(input())
pontuacao = 0
# Lista correta 
gabarito_zeus =['Zeus', 'trovão', 'deus']
gabarito_afrodite = ['Afrodite', 'amor', 'deusa']
gabarito_poseidon = ['Poseidon', 'oceanos', 'deus']
gabarito_hercules = ['Hércules', 'força', 'semideus']
gabarito_aquiles = ['Aquiles', 'resistência', 'semideus']
gabarito_orfeu = ['Orfeu', 'música', 'semideus']
# Correção
if q == 0:
  print('Infelizmente, Percy Jackson, chegou atrasado para a exame...')
else:
  for n in range(1, q+1):
    q_respostas = input()
    respostas_percy = []
    respostas_percy = q_respostas.split(', ')
    if (respostas_percy[0] in gabarito_zeus) and (respostas_percy[1] in gabarito_zeus) and (respostas_percy[2] in gabarito_zeus):
      print(f'A resposta da {n}ª questão está... CORRETA!')
      pontuacao += 1
    elif (respostas_percy[0] in gabarito_afrodite) and (respostas_percy[1] in gabarito_afrodite) and (respostas_percy[2] in gabarito_afrodite):
      print(f'A resposta da {n}ª questão está... CORRETA!')
      pontuacao += 1
    elif (respostas_percy[0] in gabarito_poseidon) and (respostas_percy[1] in gabarito_poseidon) and (respostas_percy[2] in gabarito_poseidon):
      print(f'A resposta da {n}ª questão está... CORRETA!')
      pontuacao += 1
    elif (respostas_percy[0] in gabarito_hercules) and (respostas_percy[1] in gabarito_hercules) and (respostas_percy[2] in gabarito_hercules):
      print(f'A resposta da {n}ª questão está... CORRETA!')
      pontuacao += 1
    elif (respostas_percy[0] in gabarito_aquiles) and (respostas_percy[1] in gabarito_aquiles) and (respostas_percy[2] in gabarito_aquiles):
      print(f'A resposta da {n}ª questão está... CORRETA!')
      pontuacao += 1
    elif (respostas_percy[0] in gabarito_orfeu) and (respostas_percy[1] in gabarito_orfeu) and (respostas_percy[2] in gabarito_orfeu):
      print(f'A resposta da {n}ª questão está... CORRETA!')
      pontuacao += 1
    else:
      print(f'A resposta da {n}ª questão está... ERRADA!')
# % de Acertos
if q != 0:
  porcentagem = int((pontuacao / q) * 100)
  print(f'Percy Jackson, sua taxa de acerto no EDEM é de aproximadamente... {porcentagem}%')
  if porcentagem == 100:
    print(f'UAU, você gabaritou! Você é praticamente um deus do Olimpo!')
  if 60 <= porcentagem < 100:
    print(f'Muito bem, você quase pode começar a desfilar entre os semideuses!')
  if 20 <= porcentagem < 60:
    print(f'Você pode melhorar um pouco mais!')
  if porcentagem < 20:
    print(f'Bem... te vejo ano que vem')