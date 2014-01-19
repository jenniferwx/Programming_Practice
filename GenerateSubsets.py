'''
CTCI chapter 18.3
Write a method to randomly generate a set of m integers from an array of size n.
Each element must have equal probability of being chosen
'''

import random

def SubsetGenerator(array,m):
    subset = []
    for i in range(m):
        ind = random.randint(1,len(array)-i)+i-1
        subset.append(array[ind])
        array[ind] = array[i]      
    return subset

if __name__=="__main__":
   array = [1,2,3,4,5,6,7,8,9]
   subset = SubsetGenerator(array,3)
   print subset
