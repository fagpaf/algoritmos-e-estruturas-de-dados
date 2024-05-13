filme1 = input()
pontuacao_global_filme1 = int(input())
critica_filme1 = input()
filme2 = input()
pontuacao_global_filme2 = int(input())
critica_filme2 = input()
filme3 = input()
pontuacao_global_filme3 = int(input())
critica_filme3 = input()

if critica_filme1 == 'boa':
  pontuacao_global_filme1 = float(pontuacao_global_filme1 * 1.25)
elif critica_filme1 == 'media':
  pontuacao_global_filme1 = float(pontuacao_global_filme1 * 1.00)
elif critica_filme1 == 'ruim':
  pontuacao_global_filme1 = float(pontuacao_global_filme1 * 0.75)
elif critica_filme1 == 'pessima':
  pontuacao_global_filme1 = 0

if critica_filme2 == 'boa':
  pontuacao_global_filme2 = float(pontuacao_global_filme2 * 1.25)
elif critica_filme2 == 'media':
  pontuacao_global_filme2 = float(pontuacao_global_filme2 * 1.00)
elif critica_filme2 == 'ruim':
  pontuacao_global_filme2 = float(pontuacao_global_filme2 * 0.75)
elif critica_filme2 == 'pessima':
  pontuacao_global_filme2 = 0

if critica_filme3 == 'boa':
  pontuacao_global_filme3 = float(pontuacao_global_filme3 * 1.25)
elif critica_filme3 == 'media':
  pontuacao_global_filme3 = float(pontuacao_global_filme3 * 1.00)
elif critica_filme3 == 'ruim':
  pontuacao_global_filme3 = float(pontuacao_global_filme3 * 0.75)
elif critica_filme3 == 'pessima':
  pontuacao_global_filme3 = 0

if pontuacao_global_filme3 < pontuacao_global_filme2 < pontuacao_global_filme1:
  if (0 < pontuacao_global_filme3) and (0 < pontuacao_global_filme2) and (0 < pontuacao_global_filme1):
    print('**** TOP 3 FILMES ****')
    print(f'{filme1} está em 1° lugar\n{filme2} está em 2° lugar\n{filme3} está em 3° lugar')
  elif pontuacao_global_filme3 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme1} está em 1° lugar\n{filme2} está em 2° lugar\n{filme3} está em 3° lugar\n{filme3} teve uma crítica péssima')
  elif pontuacao_global_filme2 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme1} está em 1° lugar\n{filme3} está em 2° lugar\n{filme2} está em 3° lugar\n{filme2} teve uma crítica péssima')
  elif pontuacao_global_filme1 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme2} está em 1° lugar\n{filme3} está em 2° lugar\n{filme1} está em 3° lugar\n{filme1} teve uma crítica péssima')

if pontuacao_global_filme2 < pontuacao_global_filme3 < pontuacao_global_filme1:
  if (0 < pontuacao_global_filme3) and (0 < pontuacao_global_filme2) and (0 < pontuacao_global_filme1):
    print('**** TOP 3 FILMES ****')
    print(f'{filme1} está em 1° lugar\n{filme3} está em 2° lugar\n{filme2} está em 3° lugar')
  elif pontuacao_global_filme2 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme1} está em 1° lugar\n{filme3} está em 2° lugar\n{filme2} está em 3° lugar\n{filme2} teve uma crítica péssima')
  elif pontuacao_global_filme3 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme1} está em 1° lugar\n{filme2} está em 2° lugar\n{filme3} está em 3° lugar\n{filme3} teve uma crítica péssima')
  elif pontuacao_global_filme1 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme3} está em 1° lugar\n{filme2} está em 2° lugar\n{filme1} está em 3° lugar\n{filme1} teve uma crítica péssima')

if pontuacao_global_filme1 < pontuacao_global_filme3 < pontuacao_global_filme2:
  if (0 < pontuacao_global_filme3) and (0 < pontuacao_global_filme2) and (0 < pontuacao_global_filme1):
    print('**** TOP 3 FILMES ****')
    print(f'{filme2} está em 1° lugar\n{filme3} está em 2° lugar\n{filme1} está em 3° lugar')
  elif pontuacao_global_filme1 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme2} está em 1° lugar\n{filme3} está em 2° lugar\n{filme1} está em 3° lugar\n{filme1} teve uma crítica péssima')
  elif pontuacao_global_filme3 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme2} está em 1° lugar\n{filme1} está em 2° lugar\n{filme3} está em 3° lugar\n{filme3} teve uma crítica péssima')
  elif pontuacao_global_filme2 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme3} está em 1° lugar\n{filme1} está em 2° lugar\n{filme2} está em 3° lugar\n{filme2} teve uma crítica péssima')

if pontuacao_global_filme3 < pontuacao_global_filme1 < pontuacao_global_filme2:
  if (0 < pontuacao_global_filme3) and (0 < pontuacao_global_filme2) and (0 < pontuacao_global_filme1):
    print('**** TOP 3 FILMES ****')
    print(f'{filme2} está em 1° lugar\n{filme1} está em 2° lugar\n{filme3} está em 3° lugar')
  elif pontuacao_global_filme3 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme2} está em 1° lugar\n{filme1} está em 2° lugar\n{filme3} está em 3° lugar\n{filme3} teve uma crítica péssima')
  elif pontuacao_global_filme1 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme2} está em 1° lugar\n{filme3} está em 2° lugar\n{filme1} está em 3° lugar\n{filme1} teve uma crítica péssima')
  elif pontuacao_global_filme2 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme1} está em 1° lugar\n{filme3} está em 2° lugar\n{filme2} está em 3° lugar\n{filme2} teve uma crítica péssima')

if pontuacao_global_filme2 < pontuacao_global_filme1 < pontuacao_global_filme3:
  if (0 < pontuacao_global_filme3) and (0 < pontuacao_global_filme2) and (0 < pontuacao_global_filme1):
    print('**** TOP 3 FILMES ****')
    print(f'{filme3} está em 1° lugar\n{filme1} está em 2° lugar\n{filme2} está em 3° lugar')  
  elif pontuacao_global_filme2 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme3} está em 1° lugar\n{filme1} está em 2° lugar\n{filme2} está em 3° lugar\n{filme2} teve uma crítica péssima')
  elif pontuacao_global_filme1 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme3} está em 1° lugar\n{filme2} está em 2° lugar\n{filme1} está em 3° lugar\n{filme1} teve uma crítica péssima')
  elif pontuacao_global_filme3 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme1} está em 1° lugar\n{filme2} está em 2° lugar\n{filme3} está em 3° lugar\n{filme3} teve uma crítica péssima')

if pontuacao_global_filme1 < pontuacao_global_filme2 < pontuacao_global_filme3:
  if (0 < pontuacao_global_filme1) and (0 < pontuacao_global_filme2) and (0 < pontuacao_global_filme3):
    print('**** TOP 3 FILMES ****')
    print(f'{filme3} está em 1° lugar\n{filme2} está em 2° lugar\n{filme1} está em 3° lugar')
  elif pontuacao_global_filme1 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme3} está em 1° lugar\n{filme2} está em 2° lugar\n{filme1} está em 3° lugar\n{filme1} teve uma crítica péssima')
  elif pontuacao_global_filme2 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme3} está em 1° lugar\n{filme1} está em 2° lugar\n{filme2} está em 3° lugar\n{filme2} teve uma crítica péssima')
  elif pontuacao_global_filme3 == 0:
    print('**** TOP 3 FILMES ****')
    print(f'{filme2} está em 1° lugar\n{filme1} está em 2° lugar\n{filme3} está em 3° lugar\n{filme3} teve uma crítica péssima')