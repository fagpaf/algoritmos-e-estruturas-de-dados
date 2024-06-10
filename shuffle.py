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



text1 = """Pre order : 5 3 2 4 7 6 8
In order  : 2 3 4 5 6 7 8
Post order: 2 4 3 6 8 7 5
"""

text2 = """Pre order : 5 3 2 4 7 6 8
In order  : 2 3 4 5 6 7 8
Post order: 2 4 3 6 8 7 5"""

if text1 == text2:
    print("Os textos são idênticos")
else:
    print("Os textos são diferentes")
