n1 = int(input())
if n1 < 0:
  print(f'{n1:.2f} não está gravado(a) na caixa, não adianta nem continuar que ela não vai abrir.')
elif 0 < n1:
  n2 = int(input())
  if n2 < 0:
    print(f'{n2} não está gravado(a) na caixa, não adianta nem continuar que ela não vai abrir.')
  elif 0 < n2:
    n3 = int(input())
    if n3 < 0:
      print(f'{n3} não está gravado(a) na caixa, não adianta nem continuar que ela não vai abrir.')
    elif 0 < n3:
      palavra = input()
      if not palavra.islower():
        print(f'{palavra} não está gravado(a) na caixa, não adianta nem continuar que ela não vai abrir.')
      elif palavra.islower():
        if (n1 % 2) == 0:
          n1 = (n1 * 2)
        else:
          n1 = (n1 * 0.5)
        if (n2 % 2) == 0:
          n2 = (n2 * 2)
        else:
          n2 = (n2 * 0.5)
        if (n3 % 2) == 0:
          n3 = (n3 * 2)
        else:
          n3 = (n3 * 0.5)
        n5 = int(input())
        numero_final = float((n5 * n1 * n2 * n3 )**(1/2))
        if 10 <= numero_final:
          print(f'O número {numero_final:.2f} e a palavra {palavra} eram as respostas. A caixa foi aberta.')
        elif numero_final < 10:
          z = 10 - (numero_final)
          print(f'A combinação era muito pequena, a caixa só vai poder ser aberta daqui a {z} anos.')