'''
Implement XOR operation
'''

def XOR(a,b):
    result = 0
    power = 1
    while a>0 or b>0:
        m = a%2
        n = b%2
        if m+n==1:
           result = result+power
        
        power *=2
        a = a/2
        b = b/2
    
    return result
    
if __name__=='__main__':
   a = 123
   b = 230
   print XOR(a,b)
