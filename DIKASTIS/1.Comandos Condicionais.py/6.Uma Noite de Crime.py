vida = int(input())
poder_sua_arma = int(input())
sua_habilidade_luta = int(input())
seu_poder_surpresa = int(input())
poder_arma_mascarado = int(input())
habilidade_luta_mascarado = int(input())
poder_surpresa_mascarado = int(input())
defesa_mascarado = int(input())

if ((poder_arma_mascarado < poder_sua_arma) and (habilidade_luta_mascarado < sua_habilidade_luta) and (poder_surpresa_mascarado < seu_poder_surpresa) and (0 < vida)):
  print(f'Ainda bem que deu tudo certo, está quase em casa')
  poder_arma_mascarado = int(input())
  poder_luta_mascarado = int(input())
  poder_surpresa_novo_mascarado = int(input())
  if ((poder_arma_mascarado <= poder_sua_arma) and (habilidade_luta_mascarado <= sua_habilidade_luta) and (poder_surpresa_mascarado <= seu_poder_surpresa) and (0 < vida)):
    print(f'Casa, aqui vou eu')
  else:
    print(f'Oh, no! Acabou pra mim')
else:
  vida -= defesa_mascarado
  if 0 < vida:
    print(f'Rápido, corra antes que ele vá atrás de você!')
    poder_arma_novo_mascarado = int(input())
    poder_luta_novo_mascarado = int(input())
    poder_surpresa_novo_mascarado = int(input())
    poder_sua_arma = (poder_sua_arma) - (poder_sua_arma * 0.05) 
    sua_habilidade_luta = (sua_habilidade_luta) - (sua_habilidade_luta * 0.05)
    seu_poder_surpresa = (seu_poder_surpresa) + (seu_poder_surpresa * 0.05)
    if ((poder_arma_novo_mascarado <= poder_sua_arma) and (poder_luta_novo_mascarado <= sua_habilidade_luta) and (poder_surpresa_novo_mascarado <= seu_poder_surpresa)):
      print(f'Casa, aqui vou eu')  
    else:
      print(f'Oh, no! Acabou pra mim')
  else:
    print(f'Oh, no! Acabou pra mim')