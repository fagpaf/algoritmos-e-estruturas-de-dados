import random

def shuffle(ary): # adding ary as an argument
 
    a = len(ary) # what is the length of the array
 
    b = a - 1   # b is the array minus one
                            
    for d in range(b,0,-1): # Iterate over the array
 
        e = random.randint(0,d) # Lets generate a random number
 
        if e == d: # continue if the last number is the same as the random number thrown
            ary[d],ary[e]=ary[e],ary[d]
            return ary