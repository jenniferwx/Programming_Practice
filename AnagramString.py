/*
Given two strings, check if they’re anagrams or not. Two strings are anagrams if they are written using 
the same exact letters, ignoring space, punctuation and capitalization. Each letter should have the same 
count in both strings. For example, ‘Eleven plus two’ and ‘Twelve plus one’ are meaningful anagrams of 
each other.
*/
import collections

def getLetters(str0):
    res = ''
    for ch in str0:
        if ch ==' ':
            continue
        else:
            res+=ch    
    return res
    
def isAnagram(str1, str2): 
    str1, str2 = getLetters(str1), getLetters(str2) 
    if len(str1)!=len(str2): 
        return False 
    counts=collections.defaultdict(int) 
    for letter in str1: 
        counts[letter]+=1 
    for letter in str2: 
        counts[letter]-=1 
        if counts[letter]<0:
            return False 
    return True 
 
if __name__=='__main__':
    str1 = 'one plus    two'
    str2 = 'two plus one'
    
    if(isAnagram(str1,str2)):
        print(str1+' and '+str2+' is Anagram')
    else:
        print(str1+' and '+str2+' is not Anagram')          
