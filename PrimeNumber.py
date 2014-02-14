'''
Print the top K prime number
'''

import math

def PrimeNumber(K):
    i=1
    num=2
    while i<=K:
        r = int(math.sqrt(num))
        for j in range(2,r+1): #[m+2 for m in range(r)]:
            if num%j==0:
             break;
        if j==r+1:
           print num
           i +=1
        num +=1   


if __name__=="__main__":
    K = 10
    PrimeNumber(K)
    
