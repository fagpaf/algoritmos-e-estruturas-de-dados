local_do_teste = input()
if local_do_teste == 'Salão':
  print('Em direção ao salão!')
elif local_do_teste == 'Praça':
  print('Para a praça eu vou!')
elif local_do_teste == 'Centro da cidade':
  print('Faz tempo que não visito o centro, mal posso esperar!')
hora_do_teste = int(input())
if local_do_teste == 'Salão' or local_do_teste == 'Praça':
  saida1 = hora_do_teste - 2 
else:
  saida2 = hora_do_teste - 1 
if (local_do_teste == 'Salão' or local_do_teste == 'Praça'):
  print(f'Pra chegar na hora, vou ter que sair de', saida1, 'horas.')
elif local_do_teste == 'Centro da cidade':
  print(f'Pra chegar na hora, vou ter que sair de', saida2, 'horas.')
resposta = input()
if resposta == 'Sim, Pearl! Siga seus sonhos!':
  print('Obrigada mãe! Eu vou ser uma estrela e o mundo todo saberá meu nome!')
elif resposta == 'Não. Você ficará na fazenda.':
  print('Você não vai me deixar aqui! EU NÃO VOU FICAR NESSA FAZENDA!')