n = int(input())
Anti_Hero = int(12)
Blank_Space = int(17)
You_Belong_With_Me = int(24)
Shake_it_off = int(16)
Lover = int(8)
Delicate = int(12)
Lavender_Haze = int(19)
Our_Song = int(11)
number = 1
for i in range(n):
    musica = input()
    if musica == 'AntiHero':
      number *= Anti_Hero
    elif musica == 'BlankSpace':
      number *= Blank_Space
    elif musica == 'YouBelongWithMe':
      number *= You_Belong_With_Me
    elif musica == 'Shakeitoff':
      number *= Shake_it_off
    elif musica == 'Lover':
      number *= Lover
    elif musica == 'Delicate':
      number *= Delicate
    elif musica == 'LavenderHaze':
      number *= Lavender_Haze
    elif musica == 'OurSong':
      number *= Our_Song
print(f'Parabéns por adquirir o ingresso! Seu assento é o {number}, estamos ansiosos para vê-lo, vai ser incrível!')