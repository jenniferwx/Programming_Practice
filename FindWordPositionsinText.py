'''
Given a text file and a word, find the positions that the word occurs in the file. We’ll be asked to find 
the positions of many words in the same file.
'''

# Solution 1: construct hashtable O(N), O(1) for searching
import collections as col
import re  #Regular expression operations library

def getWords(text): 
    return re.sub(r'[^a-z0-9]',' ',text.lower()).split()  
    # convert to lower letters and replace non-alphanumeric letter to space, finally split on whitespace
    
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
      
  

# Better Solution: Trie        
'''
it's very useful to use a trie while performing storage and retrieval on text data
'''
class Node: 
      def __init__(self, letter): 
          self.letter = letter 
          self.isTerminal = False 
          self.children = {} 
          self.positions = []

class Trie: 
    def __init__(self): 
        self.root=Node('')   
        
    def __contains__(self, word): 
        current=self.root 
        for letter in word: 
            if letter not in current.children: 
                return False 
            current=current.children[letter] 
        return current.isTerminal   
        
    def __getitem__(self, word): 
        current=self.root 
        for letter in word: 
            if letter not in current.children: 
                current.children[letter]=Node(letter) 
            current=current.children[letter] 
            current.isTerminal=True 
        return current.positions   
        
    def __str__(self): 
        self.output([self.root]) 
        return ''   
    
    def output(self, currentPath, indent=''): 
        #Depth First Search 
        currentNode=currentPath[-1] 
        if currentNode.isTerminal: 
            word=''.join([node.letter for node in currentPath]) 
            print indent+word+' '+str(currentNode.positions) 
            indent+=' ' 
        for letter, node in sorted(currentNode.children.items()): 
            self.output(currentPath[:]+[node], indent)
            
def createIndex2(text): 
    trie=Trie() 
    words=getWords(text) 
    for pos, word in enumerate(words): 
        trie[word].append(pos) 
    return trie   

def queryIndex2(index, word): 
    if word in index: 
        return index[word] 
    else: 
        return []
        
        
