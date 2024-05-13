pontuacao = 0
musica = 0
loop_ac = True
while(loop_ac):
  acontecimentos = input()
  if (acontecimentos == 'os fãs estão cantando as músicas em coro') or (acontecimentos == 'houve um pedido de casamento na sessão'):
    pontuacao += 2
  elif (acontecimentos == 'os fãs estão ligando os flashes e atrapalhando a visão') or (acontecimentos == 'os fãs estão dançando na frente da tela') or (acontecimentos == 'os fãs estão gritando o nome da Taylor e atrapalhando a música'):
    pontuacao -= 2
  elif (acontecimentos == 'os fãs estão formando uma ciranda'):
    pontuacao -= 3
  elif (acontecimentos == 'long live'):
    loop_ac = False
    musica += 1
    quantidade_de_musicas_tocadas = musica
    print (f'A Taylor conseguiu concluir o show sem muitas interrupções e cantou {quantidade_de_musicas_tocadas} músicas.')
  else:
    musica += 1
    pontuacao += 1
  if (pontuacao < 0):
    loop_ac = False
    quantidade_de_musicas_tocadas = musica
    print(f'A Taylor só conseguiu cantar {quantidade_de_musicas_tocadas} músicas e a sessão foi interrompida.')