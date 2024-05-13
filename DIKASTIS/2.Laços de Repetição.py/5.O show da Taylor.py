show_name = input() 
Fim_da_análise = int(0000)
VIPs = int(1000)
Ingressos_normais_longe_do_palco = int(1001)
Ingressos_normais_perto_do_palco = int(1002)
Pessoas_que_não_pagaram = int(1003)
Erro = int(1004)
loop = True
number_VIPs = 0
while (loop):
  codigo_vip = int(input())
  if codigo_vip == VIPs:
    print(f'Mais um VIP! Não podemos esquecer de contabilizá-lo.')
    number_VIPs += 1
  elif codigo_vip == Ingressos_normais_longe_do_palco:
    print(f'Ingresso Normal. Não iremos contabilizá-lo.')
  elif codigo_vip == Ingressos_normais_perto_do_palco:
    print(f'Ele ficará na frente do show, porém não é VIP! Não será contabilizado também.')
  elif codigo_vip == Pessoas_que_não_pagaram:
    print(f'Espera, quem é esse? Ele não pagou! Não devemos sequer analisar sua entrada.')
  elif codigo_vip == Erro:
    print(f'Esse código não existe! O sistema quebrou...')
    print(f'Vamos aguardar até que o suporte nos ajude.')
    repetir = True
    while (repetir):
      text_situacao = input()
      if text_situacao == 'Ajudou':
        loop = False
        repetir = False
      else:
        print(f'Ainda não...')
  elif codigo_vip == Fim_da_análise:
    loop = False
print(f'O show da Taylor Swift será em {show_name} e contará com {number_VIPs} VIPs!')
