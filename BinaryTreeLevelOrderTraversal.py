'''
'''

class Node:
    def __init__(self, val = None):
        self.left, self.right, self.val = None, None, val
        
import collections

def LevelOrderPrint(tree):
    if not tree:
       return
    nodes = collections.deque(tree)
    currentcount, nextcount = 1,0
    while(len(nodes)!=0):
        currentnodes = nodes.popleft();
        currentcount -=1
        print currentnodes.val
        if currennodes.left:
           nodes.append(currentnodes.left)
           nextcount +=1
        if currentnodes.right:
           nodes.append(currentnodes.right)
           nextcount +=1
        if currentcount==0:
           print '\n'
           currentcount, nextcount = nextcount, currentcount
        
    
    
      

