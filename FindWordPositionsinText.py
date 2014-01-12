'''
Given a text file and a word, find the positions that the word occurs in the file. We’ll be asked to find 
the positions of many words in the same file.
'''

# Solution 1: 
import collections as col
import re

def getWords(text): 
    return re.sub(r'[^a-z0-9]',' ',text.lower()).split() 
    
def CreateIndex(text) :
    index = col.defaultdict(list)
    words = getWords(text)
    for pos, word in enumerate(words):
        index[word].append(pos)
    return index

def GetIndex(index, word):
    if word in index:
       return index[word]
    else:
       return []
      
        
