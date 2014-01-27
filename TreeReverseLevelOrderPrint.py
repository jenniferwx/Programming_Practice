'''
This is very similar to the previous post level order print. We again print the tree in level order, 
but now starting from bottom level to the root.
'''

class Node:
    def __init__(self,val = None):
       self.left, self.right, self.val = None, None, val


def ReverseLevelPrint(tree):
    if not tree:
       return
    LevelSize = collections.deque([1]) # stack
    Nodes = [tree] # queue
    nextcount,currentcount = 0,1
    i = 0
    
    while i< len(Nodes):
        currentnode = Nodes[i]
        currentcount -=1
        if currentnode.left:
           Nodes.append(currentnode.left)
           nexcount +=1
        if currentnode.right:
           Nodes.append(currentnode.right)
           nextcount +=1
        
        if currentcount==0:
           if nextcount ==0:
              break
           LevelSize.appendleft(nextcount)
           nextcount, currentcount = currentcount, nextcount
        i +=1   

    LastIDX = len(Nodes)
    for count in LevelSize:
        output = Nodes[LastIDX-count:LastIDX]
        print ' '.join(map(str, output.val)), '\n',
        LastIDX -= count
           
    
