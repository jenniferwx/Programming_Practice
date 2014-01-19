'''
CTCI chap18.2
shuffle a deck of cards with equal probability
'''

import random

def shuffle(cards):
    for i in range(len(cards)):
        ind = random.randint(1,len(cards)-i)+i-1
        cards[ind],cards[i] = cards[i],cards[ind]      
        

if __name__=="__main__":
   cards = [1,2,3,4]
   shuffle(cards)
   print cards
