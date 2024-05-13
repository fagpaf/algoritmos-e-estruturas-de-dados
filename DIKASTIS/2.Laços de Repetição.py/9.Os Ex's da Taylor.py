loop = True
nome_pretendente = ''
while loop:
  affair = True
  nome_pretendente = input()
  if nome_pretendente != 'vou dormir':
    palavra_pretendente = input()
    palavra_taylor = input()
    for i in (palavra_taylor):
      if i in palavra_pretendente:
        palavra_pretendente = palavra_pretendente.replace(i, '', 1)
      else:
        affair = False
    if affair:
      print(f'você acertou, estreou na lista! {nome_pretendente}')
    else:
      print(f'perdeu covarde!')
  else:  
    loop = False