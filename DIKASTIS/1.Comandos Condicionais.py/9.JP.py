numero = int(input())
if numero == 1:
  string_1 = input()
  string_2 = input()
  string_3 = input()
  if len(string_1) > len(string_2) and len(string_1) > len(string_3):
    print(string_1)
    print('(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
  elif len(string_2) > len(string_1) and len(string_2) > len(string_3):
    print(string_2)
    print('(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
  elif len(string_3) > len(string_1) and len(string_3) > len(string_2):
    print(string_3)
    print('(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
  else:
    print("(Droga! Ainda não consegui descobrir o local que possui mais sinais desconhecidos! Vou ter que ficar mais um tempo nessa Mansão Mal-Assombrada...)")
    if string_1 > string_2 and string_1 > string_3:
      print(string_1)
      print('(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
    elif string_2 > string_1 and string_2 > string_3:
      print(string_2)
      print('(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
    elif string_3 > string_1 and string_3 > string_2:
      print(string_3)
      print('(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
    else:
      print('"AAAAAA! Um fantasma me assustou!"')
      print('(Uma mensagem apareceu no monitor que você estava usando. "Agente, um erro inesperado aconteceu. A EPF contactará você novamente quando tudo estiver funcionando da forma correta. Nosso sistema foi invadido por alguém que se identifica como Hubert P.Enguin")')
elif numero == 2:
  string_1 = input()
  string_2 = input()
  string_3 = input()
  if len(string_1) < len(string_2) and len(string_1) < len(string_3):
    print(string_1)
    print('(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
  elif len(string_2) < len(string_1) and len(string_2) < len(string_3):
    print(string_2)
    print('(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
  elif len(string_3) < len(string_1) and len(string_3) < len(string_2):
    print(string_3)
    print('(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
  else:
    print("(Droga! Ainda não consegui descobrir o local que possui mais sinais desconhecidos! Vou ter que ficar mais um tempo nessa Mansão Mal-Assombrada...)")
    if string_1 > string_2 and string_1 > string_3:
      print(string_1)
      print('(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
    elif string_2 > string_1 and string_2 > string_3:
      print(string_2)
      print('(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
    elif string_3 > string_1 and string_3 > string_2:
      print(string_3)
      print('(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
    else:
      print('"AAAAAA! Um fantasma me assustou!"')
      print('(Uma mensagem apareceu no monitor que você estava usando. "Agente, um erro inesperado aconteceu. A EPF contactará você novamente quando tudo estiver funcionando da forma correta. Nosso sistema foi invadido por alguém que se identifica como Hubert P.Enguin")')
else:
  print(" ")
print("(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)") 