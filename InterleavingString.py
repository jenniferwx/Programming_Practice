'''
We are given 3 strings: str1, str2, and str3. Str3 is said to be a shuffle of str1 and str2 if it can be formed 
by interleaving the characters of str1 and str2 in a way that maintains the left to right ordering of the characters 
from each string. 

For example, given str1=”abc” and str2=”def”, str3=”dabecf” is a valid shuffle. 
since it preserves the character ordering of the two strings. So, given these 3 strings write a function that 
detects whether str3 is a valid shuffle of str1 and str2. 

'''

'''
Solution: Dynamic Programming and cache the already evaluated results to avoid precomputation. 
Once we see that two input strings don’t produce a valid shuffle, we cache this information 
(if they do produce a valid shuffle then we’re done and return True, so no need to cache). 
'''
# Complexity: O(NM)--N and M are the length of str1 and str2
def isShuffle2(str1, str2, str3, cache=set()): 
  if (str1, str2) in cache: 
    return False   
  if len(str1)+len(str2)!=len(str3): 
    return False   
  if not str1 or not str2 or not str3: 
    if str1+str2==str3: 
      return True 
    else: 
      return False   
      
  if str1[0]!=str3[0] and str2[0]!=str3[0]: 
    return False   
    
  if str1[0]==str3[0] and isShuffle2(str1[1:], str2, str3[1:], cache): 
    return True 
  if str2[0]==str3[0] and isShuffle2(str1, str2[1:], str3[1:], cache): 
    return True   
  cache.add( (str1, str2) )   
  
  return False
