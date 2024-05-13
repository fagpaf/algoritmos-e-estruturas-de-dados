def senha_de_acesso(meu_codigo):
  if (meu_codigo == 1) or (meu_codigo == 0):
    x = 1
  else:
    if meu_codigo % 2 == 0:
      x = senha_de_acesso(meu_codigo - 1)
    else:
      x = meu_codigo * senha_de_acesso(meu_codigo - 2)
  return x


num = int(input())
# Output
print(senha_de_acesso(num))