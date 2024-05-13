def conferir_bits(bit):
  bit = list(bit)
  if len(bit) == 32:
    return ''.join(bit)
  else:
    bit.insert(0, '0')
    return conferir_bits(bit)


def fatiamento(firewall, byte, chances):
  if len(firewall) > 7:
    return verificacao_de_chave(firewall[1:], byte, chances)
#   Output's senhas erradas
  else:
    if chances > 1: 
      return "Não é essa a senha, estamos ficando sem tempo."
    else:
      print("Não é essa a senha, estamos ficando sem tempo.")
      return "Corre Keanu! Eles nos descobriram!!"


def verificacao_de_chave(parede_copia, byte, chances):
  if byte == parede_copia[:8]:
    return "Muito bem! Estamos dentro! Vamos queimar essa cidade!!"
  else:
    return fatiamento(parede_copia, byte, chances)
  

palavra = input()
limite_tentativas = int(input())
senha_correta = False
# Loop para renovar a senha e garantir o lim de tentativas
while limite_tentativas > 0 and not senha_correta:
  senha = input()
  parede_de_fogo = conferir_bits(palavra)
  acesso = verificacao_de_chave(parede_de_fogo, senha, limite_tentativas)
  print(acesso)
  limite_tentativas -= 1
  # Uma ideia diferente para não usar variavel global, na quebra do loop
  if "Muito bem!" in acesso:
    senha_correta = True