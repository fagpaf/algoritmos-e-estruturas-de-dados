resposta_correta_1 = input()
resposta_correta_2 = input()
resposta_correta_3 = input()
pergunta1_ghostface = input()
resposta1 = input()
if resposta1 == resposta_correta_1:
  print('Muito bem! Olha como a primeira foi fácil, seu amigo talvez sobreviva. Falta só mais duas para acabar com isso!')
  pergunta2_ghostface = input()
  resposta2 = input()
  if resposta2 == resposta_correta_2:
    print(f'A resposta está e…exata! Você é mais inteligente do que eu pensei, já posso caprichar nesta última, vamos ver se você realmente conhece filmes de terror!')
    pergunta3_ghostface = input()
    resposta3 = input()
    if resposta3 == resposta_correta_3:
      print(f'Droga, não vai ser hoje que vou ver sangue, que pena! Mas não se esqueça de mim, quem sabe um dia algum dos seus amigos não queiram brincar para lhe salvar!')
    else:
      print(f'A resposta está e…e…rrada hahahahaha. Essa é a parte que eu mais gosto, venha aqui no quintal, você pode dar um adeus!')
  else:
    print('A resposta está e…e…rrada hahahahaha. Essa é a parte que eu mais gosto, venha aqui no quintal, você pode dar um adeus!')
    
else:
  print(f'A resposta está e…e…rrada hahahahaha. Essa é a parte que eu mais gosto, venha aqui no quintal, você pode dar um adeus!')
