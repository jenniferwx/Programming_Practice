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
    while(currentcount!=0):
        currentnode = nodes.popleft();
        currentcount -=1
        print currentnode.val
        if currennode.left:
           nodes.append(currentnode.left)
           nextcount +=1
        if currentnode.right:
           nodes.append(currentnode.right)
           nextcount +=1
        if currentcount==0:
           print '\n'
           currentcount, nextcount = nextcount, currentcount
        
    
    
      

