'''
CTCI chapter 18.4 
Write a method to cont the number of 2s between 0 and n
'''

import math
def count2inRangeDigits(number,pos):
    powerof10 = 10**pos
    nextpowerof10 = powerof10*10
    right = number%powerof10
    
    RoundDown = number - number%nextpowerof10
    RoundUp = RoundDown + nextpowerof10
    digits = (number/powerof10)%10    
    if digits<2:
       return RoundDown/10
    elif digits>2:
       return RoundUp/10
    else:
       return RoundDown/10 + right +1
    
def count2inRange(number):
    count = 0
    length = len(list(str(number)))
    for i in range(length):
        count += count2inRangeDigits(number,i)
        
    return count    

if __name__=="__main__":
   number = 112
   count = count2inRange(number)
   print count
