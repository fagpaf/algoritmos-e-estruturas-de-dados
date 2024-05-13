numero = int(input())
string_1 = input()
string_2 = input()
string_3 = input()
if numero == 1:
  if (len(string_3) < len(string_1) and len(string_2) < len(string_1)):
    print(f'{string_1}')
    print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
    print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
  elif (len(string_3) < len(string_2) and len(string_1) < len(string_2)):
    print(f'{string_2}')
    print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
    print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
  elif (len(string_1) < len(string_3) and len(string_2) < len(string_3)):
    print(f'{string_3}')
    print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
    print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
  elif (len(string_3) == len(string_2) == len(string_1)):
    print(f'(Droga! Ainda não consegui descobrir o local que possui mais sinais desconhecidos! Vou ter que ficar mais um tempo nessa Mansão Mal-Assombrada...)')
    if ((string_3 < string_1) and (string_2 < string_1 )):
      print(f'{string_1}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_3 < string_2) and (string_1 < string_2 )):
      print(f'{string_2}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_1 < string_3) and (string_2 < string_3)):
      print(f'{string_3}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    else:
      print(f'"AAAAAA! Um fantasma me assustou!"\n(Uma mensagem apareceu no monitor que você estava usando. "Agente, um erro inesperado aconteceu. A EPF contactará você novamente quando tudo estiver funcionando da forma correta. Nosso sistema foi invadido por alguém que se identifica como Hubert P.Enguin")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
  elif ((len(string_3) < len(string_2) and len(string_3) < len(string_1) and len(string_1) == len(string_2))):
    print(f'(Droga! Ainda não consegui descobrir o local que possui mais sinais desconhecidos! Vou ter que ficar mais um tempo nessa Mansão Mal-Assombrada...)')
    if ((string_3 < string_1) and (string_2 < string_1)):
      print(f'{string_1}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_3 < string_2) and (string_1 < string_2)):
      print(f'{string_2}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_1 < string_3) and (string_2 < string_3)):
      print(f'{string_3}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    else:
      print(f'"AAAAAA! Um fantasma me assustou!"\n(Uma mensagem apareceu no monitor que você estava usando. "Agente, um erro inesperado aconteceu. A EPF contactará você novamente quando tudo estiver funcionando da forma correta. Nosso sistema foi invadido por alguém que se identifica como Hubert P.Enguin")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
  elif ((len(string_2) < len(string_3) and len(string_2) < len(string_1) and len(string_1) == len(string_3))):
    print(f'(Droga! Ainda não consegui descobrir o local que possui mais sinais desconhecidos! Vou ter que ficar mais um tempo nessa Mansão Mal-Assombrada...)')
    if ((string_3 < string_1) and (string_2 < string_1)):
      print(f'{string_1}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_3 < string_2) and (string_1 < string_2)):
      print(f'{string_2}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_1 < string_3) and (string_2 < string_3)):
      print(f'{string_3}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    else:
      print(f'"AAAAAA! Um fantasma me assustou!"\n(Uma mensagem apareceu no monitor que você estava usando. "Agente, um erro inesperado aconteceu. A EPF contactará você novamente quando tudo estiver funcionando da forma correta. Nosso sistema foi invadido por alguém que se identifica como Hubert P.Enguin")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
  elif ((len(string_1) < len(string_2) and len(string_1) < len(string_3) and len(string_3) == len(string_2))):
    print(f'(Droga! Ainda não consegui descobrir o local que possui mais sinais desconhecidos! Vou ter que ficar mais um tempo nessa Mansão Mal-Assombrada...)')
    if ((string_3 < string_1) and (string_2 < string_1)):
      print(f'{string_1}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_3 < string_2) and (string_1 < string_2)):
      print(f'{string_2}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_1 < string_3) and (string_2 < string_3)):
      print(f'{string_3}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    else:
      print(f'"AAAAAA! Um fantasma me assustou!"\n(Uma mensagem apareceu no monitor que você estava usando. "Agente, um erro inesperado aconteceu. A EPF contactará você novamente quando tudo estiver funcionando da forma correta. Nosso sistema foi invadido por alguém que se identifica como Hubert P.Enguin")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
  else:
    print(f'"AAAAAA! Um fantasma me assustou!"\n(Uma mensagem apareceu no monitor que você estava usando. "Agente, um erro inesperado aconteceu. A EPF contactará você novamente quando tudo estiver funcionando da forma correta. Nosso sistema foi invadido por alguém que se identifica como Hubert P.Enguin")')
    print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
elif numero == 2:
  if (len(string_3) > len(string_1) and len(string_2) > len(string_1)):
    print(f'{string_1}')
    print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
    print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
  elif (len(string_3) > len(string_2) and len(string_1) > len(string_2)):
    print(f'{string_2}')
    print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
    print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
  elif (len(string_1) > len(string_3) and len(string_2) > len(string_3)):
    print(f'{string_3}')
    print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
    print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
  elif ((len(string_3) > len(string_2) and len(string_3) > len(string_1) and len(string_1) == len(string_2))):
    print(f'(Droga! Ainda não consegui descobrir o local que possui mais sinais desconhecidos! Vou ter que ficar mais um tempo nessa Mansão Mal-Assombrada...)')
    if ((string_3 < string_1) and (string_2 < string_1)):
      print(f'{string_1}')
      print(f'Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços"')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_3 < string_2) and (string_1 < string_2 )):
      print(f'{string_2}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_1 < string_3) and (string_2 < string_3 )):
      print(f'{string_3}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    else:
      print(f'"AAAAAA! Um fantasma me assustou!"\n(Uma mensagem apareceu no monitor que você estava usando. "Agente, um erro inesperado aconteceu. A EPF contactará você novamente quando tudo estiver funcionando da forma correta. Nosso sistema foi invadido por alguém que se identifica como Hubert P.Enguin")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
  elif ((len(string_2) > len(string_3) and len(string_2) > len(string_1) and len(string_1) == len(string_3))):
    print(f'(Droga! Ainda não consegui descobrir o local que possui mais sinais desconhecidos! Vou ter que ficar mais um tempo nessa Mansão Mal-Assombrada...)')
    if ((string_3 < string_1) and  (string_2 < string_1)):
      print(f'{string_1}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_3 < string_2) and (string_1 < string_2)):
      print(f'{string_2}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_1 < string_3) and (string_2 < string_3)):
      print(f'{string_3}')
      print(f'Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços"')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    else:
      print(f'"AAAAAA! Um fantasma me assustou!"\n(Uma mensagem apareceu no monitor que você estava usando. "Agente, um erro inesperado aconteceu. A EPF contactará você novamente quando tudo estiver funcionando da forma correta. Nosso sistema foi invadido por alguém que se identifica como Hubert P.Enguin")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
  elif ((len(string_1) > len(string_2) and len(string_1) > len(string_3) and len(string_3) == (string_2))):
    print(f'(Droga! Ainda não consegui descobrir o local que possui mais sinais desconhecidos! Vou ter que ficar mais um tempo nessa Mansão Mal-Assombrada...)')
    if ((string_3 < string_1) and (string_2 < string_1)):
      print(f'{string_1}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_3 < string_2) and (string_1 < string_2)):
      print(f'{string_2}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_1 < string_3) and (string_2 < string_3)):
      print(f'{string_3}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    else:
      print(f'"AAAAAA! Um fantasma me assustou!"\n(Uma mensagem apareceu no monitor que você estava usando. "Agente, um erro inesperado aconteceu. A EPF contactará você novamente quando tudo estiver funcionando da forma correta. Nosso sistema foi invadido por alguém que se identifica como Hubert P.Enguin")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
  else:
    print(f'(Droga! Ainda não consegui descobrir o local que possui mais sinais desconhecidos! Vou ter que ficar mais um tempo nessa Mansão Mal-Assombrada...)')
    if ((string_3 < string_1) and (string_2 < string_1)):
      print(f'{string_1}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_3 < string_2) and (string_1 < string_2)):
      print(f'{string_2}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    elif ((string_1 < string_3) and (string_2 < string_3)):
      print(f'{string_3}')
      print(f'(Ao terminar sua tarefa, uma mensagem apareceu no monitor que você estava usando. "Muito bem agente. A EPF agradece os seus esforços")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')
    else:
      print(f'"AAAAAA! Um fantasma me assustou!"\n(Uma mensagem apareceu no monitor que você estava usando. "Agente, um erro inesperado aconteceu. A EPF contactará você novamente quando tudo estiver funcionando da forma correta. Nosso sistema foi invadido por alguém que se identifica como Hubert P.Enguin")')
      print(f'(Depois de ler a mensagem, você dormiu. Ao acordar, você não estava mais no CIn de outubro de 2012, mas no CIn de 2023, sem acreditar na situação que vivenciou)')