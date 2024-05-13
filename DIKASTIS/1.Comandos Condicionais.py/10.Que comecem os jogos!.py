direcao_escolhida = input()
numero = int(input())
pontuacao = 0
if (numero % 2 != 0):
  if direcao_escolhida == 'direita':
    pontuacao += 150
    escolha1 = 'CERTA'
  elif direcao_escolhida == 'esquerda':
    pontuacao -= 150
    escolha1 = 'ERRADA'
else:
  if direcao_escolhida == 'direita':
    pontuacao -= 150
    escolha1 = 'ERRADA'
  elif direcao_escolhida == 'esquerda':
    pontuacao += 150
    escolha1 = 'CERTA'

direcao_escolhida = input()
cor = input()
planta = input()
macaneta = input()
if ((cor == 'dourada') or (cor == 'prateada')) or (((planta == 'avenca') or (planta == 'espadinha')) and (macaneta == 'redonda')):
  if direcao_escolhida == 'direita':
    pontuacao += 200
    escolha2 = 'CERTA'
  elif direcao_escolhida == 'esquerda':
    pontuacao -= 200
    escolha2 = 'ERRADA'
else:
  if direcao_escolhida == 'esquerda':
    pontuacao += 200
    escolha2 = 'CERTA'
  elif direcao_escolhida == 'direita':
    pontuacao -= 200
    escolha2 = 'ERRADA'

direcao_escolhida = input()
cor = input()
numero = int(input())
planta = input()
macaneta = input()
if ((numero % 5 == 0) and (planta == 'espadinha') and (macaneta == 'quadrada')) or (cor == 'perolada'):
  if direcao_escolhida == 'esquerda':
    pontuacao += 250
    escolha3 = 'CERTA'
  elif direcao_escolhida == 'direita':
    pontuacao -= 250
    escolha3 = 'ERRADA'
else:
  if direcao_escolhida == 'direita':
    pontuacao += 250
    escolha3 = 'CERTA'
  elif direcao_escolhida == 'esquerda':
    pontuacao -= 250
    escolha3 = 'ERRADA'

direcao_escolhida = input()
numero = int(input())
if (numero % 3 == 0) and (numero % 2 != 0) and (numero % 5 != 0):
  if direcao_escolhida == 'direita':
    pontuacao += 300
    escolha4 = 'CERTA'
  elif direcao_escolhida == 'esquerda':
    pontuacao -= 300
    escolha4 = 'ERRADA'
else:
  if direcao_escolhida == 'esquerda':
    pontuacao += 300
    escolha4 = 'CERTA'
  elif direcao_escolhida == 'direita':
    pontuacao -= 300
    escolha4 = 'ERRADA'

cor = input()
numero = int(input())
planta = input()
flor = input()
macaneta = input()
if (cor == 'acobreada') and ((numero % 2 != 0) or ((macaneta == 'triangular') or (macaneta =='quadrada'))) and (planta == 'jiboia'):
  pontuacao += 500
  escolha5 = 'CERTA'
elif (cor == 'prateada') and ((flor != 'margarida') or (flor != 'papoula') or (flor != 'cosmos')) and ((macaneta == 'hexagonal') or (macaneta == 'redonda')):
  pontuacao += 450
  escolha5 = 'CERTA'
elif (cor == 'dourada') and ((flor == 'lirio') or (flor == 'ixora')) and (macaneta == 'hexagonal'):
  pontuacao += 400
  escolha5 = 'CERTA'
else:
  pontuacao -= 500
  escolha5 = 'ERRADA'
print(f'ARISU, VOCÊ FEZ SUAS ESCOLHAS E AGORA VEREMOS SE ESCOLHEU AS PORTAS CERTAS:')
print(f'{escolha1} {escolha2} {escolha3} {escolha4} {escolha5}')
if 0 < pontuacao:
  if ((escolha1 == 'ERRADA') or (escolha2 == 'ERRADA') or (escolha3 == 'ERRADA') or (escolha4 == 'ERRADA') or (escolha5 == 'ERRADA')):
    print(f'Você passou com {pontuacao} pontos, mas faça melhores escolhas da próxima vez.')
  elif ((escolha1 == 'CERTA') and (escolha2 == 'CERTA') and (escolha3 == 'CERTA') and (escolha4 == 'CERTA') and (escolha5 == 'CERTA')):
    print(f'Parece que a sorte está ao seu favor, Arisu... Você conseguiu passar com {pontuacao} pontos!')
elif pontuacao < 0:
  if ((escolha1 == 'CERTA') or (escolha2 == 'CERTA') or (escolha3 == 'CERTA') or (escolha4 == 'CERTA') or (escolha5 == 'CERTA')):
    print(f'Por mais que você tenha feito escolhas corretas, não foi suficiente para sobreviver. Você finalizou o jogo com {pontuacao} pontos')
  elif ((escolha1 == 'ERRADA') and (escolha2 == 'ERRADA') and (escolha3 == 'ERRADA') and (escolha4 == 'ERRADA') and (escolha5 == 'ERRADA')):
    print(f'Todas suas escolhas foram erradas, Arisu, esperávamos mais de você... Você será executado pois obteve {pontuacao} pontos.')