'''
Find the first non-repeated (unique) character in a given string.
'''

# Solution 1: Hash Table
import collections
def FindFirst(text):
    Table = collections.defaultdic(int)
    for letters in text:
        Table[letters] +=1
    for letters in text:
        if(Table[letters]==1):
        return letters
        
        
# Solution 2: one pass for the hash table        
