informacoes_deuses = [
  ['Zeus', 'Poseidon', 'Atenas', 'Ares', 'Afrodite'],
  [100, 90, 80, 70, 60],
  ['Raio', 'Tridente', 'Égide', 'Lança', 'Cinto Mágico']
]
sequencia = input()
lista_algarismos = []
idx = 0
for i in sequencia:
  lista_algarismos.append(int(i))
# Outputs, iterando o idx do último item da lista
for n in lista_algarismos:
  if (0 <= n < 2) or (n == 3):
    print(f'Deus:{informacoes_deuses[0][n]}')
    print(f'Poder:{informacoes_deuses[1][n]}')
    print(f'Artefato:{informacoes_deuses[2][n]}')
    if idx != len(lista_algarismos) - 1:
      print()
      idx += 1
  elif n == 2:
    print(f'Deusa:{informacoes_deuses[0][n]}')
    print(f'Poder:{informacoes_deuses[1][n]}')
    print(f'Artefato:{informacoes_deuses[2][n]}')
    if idx != len(lista_algarismos) - 1:
      print()
      idx += 1
  elif n == 4:
    print(f'Deusa:{informacoes_deuses[0][n]}')
    print(f'Poder:{informacoes_deuses[1][n]}')
    print(f'Artefato:{informacoes_deuses[2][n]}')
    if idx != len(lista_algarismos) - 1:
      print()
      idx += 1