def bolo_de_chip(qtd_inicial, desejada):
  qtd_bolo = 0 
  if qtd_inicial == desejada:
    qtd_bolo += 1
  elif (qtd_inicial < desejada) or (qtd_inicial % 3 != 0):
    qtd_bolo += 0 
  else:
    qtd_bolo += bolo_de_chip((qtd_inicial * 2) //3, desejada)
    qtd_bolo += bolo_de_chip(qtd_inicial // 3, desejada)

  return qtd_bolo


num_pedidos = int(input())
for n in range(num_pedidos):
  qtd_ini, qtd_desej = input().split(' ')
  ini = int(qtd_ini)
  desej = int(qtd_desej)
  if bolo_de_chip(ini, desej) > 0:
    print("SIM")
  else:
    print("NAO")