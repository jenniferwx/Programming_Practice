'''
The Game of Master Mind from CTCI
Chapter 17.5
'''

import collections
def Estimate(solution, guess):
    hits = 0
    pseudoHits = 0
    Table = collections.defaultdict(int)
    Sol = list(solution)
    Gue = list(guess)
    for i in range(len(Sol)):
        if Gue[i]==Sol[i]:
           hits+=1
        else:   
           Table[Sol[i]]+=1   
    
    # count the number of pseudoHits
    for ch in Gue:
        if Table[ch]>0:
           pseudoHits +=1
           Table[ch] -=1
    
    return hits, pseudoHits
        


if __name__=='__main__':
   print "Input the solution: \n"
   solution = "RGBY" #raw_input()
   print "Input the guess: \n"
   guess = "GGRR" #raw_input()
   hits,pseudohits = Estimate(solution,guess)
   print "("+str(hits)+"Hits"+str(pseudohits)+"pseudoHits)"
   
