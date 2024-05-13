colecao_sergio = input().split(', ')
qtd_total_edicoes = int(input())
livros_percy = ['O Ladrão de Raios', 'O Mar de Monstros', 'A Maldição do Titã', 'A Batalha do Labirinto', 'O Último Olimpiano']
# Criação de Novas Listas
livros_outras_sagas = []
lista_verificacao = []
livros_faltando = []
for i in livros_percy:
  if i in colecao_sergio:
    lista_verificacao.append(i)
  if i not in colecao_sergio:
    livros_faltando.append(i)
for l in colecao_sergio:
  if l not in livros_percy:
    livros_outras_sagas.append(l)
# Outputs
if qtd_total_edicoes > 0:
  if lista_verificacao == livros_percy:
    print('Sua coleção está completa! Você pode ler à vontade.')
  if 5 > len(livros_faltando) > 0:
    print(f'Infelizmente, sua coleção está incompleta. Falta(m) esse(s) livro(s): {", ".join(livros_faltando)}.')
  if len(lista_verificacao) == 0:
    print(f'Caramba, você não tem nenhum livro. Compre todos imediatamente.')
  if len(livros_outras_sagas) != 0:
    print(f'Cuidado, Sérgio! Você está organizando seus livros de uma forma errada, o(s) livro(s): {", ".join(livros_outras_sagas)}, não faz(em) parte da saga "Percy Jackson e os Olimpianos".')
else:
  print(f'Caramba, você não tem nenhum livro. Compre todos imediatamente.')