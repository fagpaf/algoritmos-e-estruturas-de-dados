# Def que Irá Somar os Valores 
def soma_presentes(codigo_presente):
  soma = 0
  for numero in codigo_presente:
    soma += numero
  return soma
           
# Def para Decifrar o Nome do Presente 
def decodificar_presentes(codigo_presente):
  palavra = ''.join(chr(numero) for numero in codigo_presente) 
  return palavra

# Variáveis Globais
n_presentes = int(input())
lista_presentes = [] 
presentes_excluidos = []
lista_final = []

# Printando a Primeira Parte
for presentes in range(n_presentes):
  codigo_presente = [int(num) for num in input().split()]
  presente_decodificado = decodificar_presentes(codigo_presente)
  lista_presentes.append(presente_decodificado) 
  # Verificando o Critério de Exclusão 
  if presente_decodificado in lista_final or presente_decodificado in presentes_excluidos:
    print(f"{presente_decodificado} já está na lista de presentes da Anya!!")
  else:
    print(f"{presente_decodificado} foi adicionado a lista ultrassecreta de presentes da Anya!!")
    if soma_presentes(codigo_presente) % 2 == 0 :
      lista_final.append(presente_decodificado)
    else:
      if presente_decodificado:
        presentes_excluidos.append(presente_decodificado) 
   
# Printando os Presentes Excluidos
if len(presentes_excluidos) != 0:
    print(f"Infelizmente o Twilight é mão de vaca e os seguintes itens precisaram ser excluídos da lista de presentes ultrassecretos da Anya: {', '.join(presentes_excluidos)}.")
else:  
  if len(lista_final) != 0:
    print("P
    arece que o Dia das Crianças desse ano será especial!!!! Anya ganhará todos os presentes planejados, mesmo que ela não seja tão exemplar como deveria…")   

# Caso a Lista de Presentes Não Tenha Sido Zerada 
if len(lista_final) != 0:
  print(f"Lista final dos melhores presentes da Anya: {', '.join(lista_final)}.")
else:
  print("O quê? Nenhum presente? Isso é um absurdo! Vamos corrigir essa injustiça e garantir que Anya tenha um Dia das Crianças inesquecível!")