num_versos = int(input())
acerto_plateia = 0
for i in range(1, num_versos + 1):
  input_plateia = input()
  letra_musica = ''
  for char in input_plateia:
    char = char.upper()
    letra_musica += char
  # 1° verso
  if i == 1:
    print("Cause, baby, now we've got")
    if letra_musica == 'BAD BLOOD':
      print(f'{letra_musica}')
      acerto_plateia += 1
  # 2° verso 
  if i == 2:
    print('You know it used to be')
    if letra_musica == 'MAD LOVE':
      print(f'{letra_musica}')
      acerto_plateia += 1
  # 3° verso 
  if i == 3:
    print('So take a look what')
    if letra_musica == "YOU'VE DONE":
      print(f'{letra_musica}')
      acerto_plateia += 1
  # 4° verso 
  if i == 4:
    print("Cause, baby, now we've got")
    if letra_musica == 'BAD BLOOD, HEY':
      print(f'{letra_musica}')
      acerto_plateia += 1
if acerto_plateia == num_versos:
    print('A plateia deu um show! Acertou tudo!')
elif (num_versos * 0.5) <= acerto_plateia:
    print('A plateia acertou a maior parte da música')
else:
    print('Foi um dia atípico e a plateia se esqueceu de grande da música')