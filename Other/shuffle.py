# import random

# def shuffle(ary): # adding ary as an argument
 
#     a = len(ary) # what is the length of the array
 
#     b = a - 1   # b is the array minus one
                            
#     for d in range(b,0,-1): # Iterate over the array
 
#         e = random.randint(0,d) # Lets generate a random number
 
#         if e == d: # continue if the last number is the same as the random number thrown
#             ary[d],ary[e]=ary[e],ary[d]
#             return ary

#int* permutation(int size){ // Cria uma permutação baseada no algoritmo de Fischer-Yates
#    int* perm = (int*)malloc((size-1) * sizeof(int));
#    // Algoritmo de Fischer-Yates
#    for(int i = size - 2; i > 0; i--){
#        int j = rand() % (i+1);   // Gera um índice aleatório 'j' entre 0 e 'i' 
#        int temp = perm[i];
#        perm[i] = perm[j];
#        perm[j] = temp;
#        // Esse 'for' faz o embaralhamento do array trocando
#    }
#    return perm;
#}



# text1 = """Pre order : 5 3 2 4 7 6 8
# In order  : 2 3 4 5 6 7 8
# Post order: 2 4 3 6 8 7 5
# """

# text2 = """Pre order : 5 3 2 4 7 6 8
# In order  : 2 3 4 5 6 7 8
# Post order: 2 4 3 6 8 7 5"""

# if text1 == text2:
#     print("Os textos são idênticos")
# else:
#     print("Os textos são diferentes")


# while True:
#     print(f"FLAVINHO GOSTOSO")
# ----------------------------------------------------------------------
# import matplotlib.pyplot as plt
# import networkx as nx

# # Cria um grafo dirigido
# G = nx.DiGraph()

# # Adiciona os nós
# nodes = ["A", "B", "C", "D", "E", "F", "G"]
# G.add_nodes_from(nodes)

# # Adiciona as arestas com os pesos
# edges = [
#     ("A", "B", 2), ("A", "C", 5), ("A", "D", 1),
#     ("B", "E", 7), ("D", "B", 3), ("D", "E", 2), ("D", "F", 4),
#     ("E", "G", 1), ("F", "G", 3), ("C", "F", 6)
# ]
# G.add_weighted_edges_from(edges)

# # Define as posições dos nós para a plotagem
# pos = {
#     "A": (0, 2), "B": (2, 2), "C": (0, 0), "D": (1, 1), "E": (3, 1), 
#     "F": (1, 0), "G": (3, 0)
# }

# # Define as distâncias finais
# distances = {"A": 0, "B": 2, "C": 5, "D": 1, "E": 3, "F": 5, "G": 4}

# # Desenha o grafo
# plt.figure(figsize=(10, 6))
# nx.draw(G, pos, with_labels=True, node_color='skyblue', node_size=2000, font_size=16, font_weight='bold', edge_color='gray')
# labels = nx.get_edge_attributes(G, 'weight')
# nx.draw_networkx_edge_labels(G, pos, edge_labels=labels, font_size=14)

# # Adiciona as distâncias nos nós
# distance_labels = {node: f"{node}\n({dist})" for node, dist in distances.items()}
# nx.draw_networkx_labels(G, pos, labels=distance_labels, font_size=16, font_color='black', font_weight='bold')

# plt.title("Algoritmo de Dijkstra - Exemplo de Caminho Mais Curto")
# plt.show()

