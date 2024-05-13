numero_celebridades = int(input())
Taylor_Swift = False
Katy_Perry = False
Ariana_Grande = False
Beyonce = False
Shakira = False
Gerard_Pique = False
Kanye_West = False
Chris_Martin = False
# Persona non Grata
for i in range(1, numero_celebridades + 1):
  celebridade = input()
  if celebridade == "Gerard Piqué":
    Gerard_Pique = True
  if celebridade == "Kanye West":
    Kanye_West = True
  if celebridade == "Chris Martin":
    Chris_Martin = True
  print(f'Apresentador: Contamos com a ilustre presença de {celebridade}, uma salva de palmas!')
# Candidatos ao Prêmio VMA
loop = True
while loop:
  nome_candidata = input()
  if nome_candidata == 'Taylor Swift':
    Taylor_Swift = True
  if nome_candidata == "Katy Perry" :
    Katy_Perry = True
  if nome_candidata == "Ariana Grande" :
    Ariana_Grande = True
  if nome_candidata == "Beyoncé" :
    Beyonce = True
  if nome_candidata == "Shakira" :
    Shakira = True
  if nome_candidata == 'Início da Premiação':
    loop = False
# Premiação
print(f'Apresentador: Vamos deixar de enrolação e ir para a premiação!')
print(f'Apresentador: E a artista do ano do MTV Video Music Awards 2023 é...')
# Taylor Swift Win
if Taylor_Swift:
  print('TAYLOR SWIFT')
  if Kanye_West:
    print(f'Kanye West: Eu vou te deixar terminar. Estou feliz por você, mas Beyoncé fez um dos melhores vídeos de todos os tempos.')
# Katy Parry Win
elif not Taylor_Swift and Katy_Perry:
  print('KATY PERRY')
# Ariana Grande Win
elif not Taylor_Swift and not Katy_Perry and Ariana_Grande:
  print('ARIANA GRANDE')
# Beyoncé Win
elif not Taylor_Swift and not Katy_Perry and not Ariana_Grande and Beyonce:
  print('BEYONCÉ')
  if Chris_Martin:
    print('Chris Martin: Minha heroína, minha irmã, meu tudo. Você merece!')
# Shakira Win
elif not Taylor_Swift and not Katy_Perry and not Ariana_Grande and not Beyonce and Shakira:
  print('SHAKIRA')
  if Gerard_Pique:
    print(f'Gerard Piqué: Meu amor me perdoa, volta pra mim...')