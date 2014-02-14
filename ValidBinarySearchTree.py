'''
Given a binary tree, check whether it’s a binary search tree or not.
'''

class Node: def __init__(self, val=None): 
  self.left, self.right, self.val = None, None, val   
  INFINITY = float("infinity") 
  NEG_INFINITY = float("-infinity")   
  
def isBST(tree, minVal=NEG_INFINITY, maxVal=INFINITY): 
  if tree is None: 
    return True   
  
  if not minVal <= tree.val <= maxVal: 
    return False   
  
  return isBST(tree.left, minVal, tree.val) and isBST(tree.right, tree.val, maxVal)
  
  
# Second Solution: inorder Traversal

def isBSTree2(tree,LastNode=NEG_INFINITY):
  if tree is None:
    return True
  if not isBSTree2(tree.left,LastNode):
    return False
  
  if tree.val<LastNode:
    return False
  
  lastNode = tree.val
  return isBSTree2(tree.right,LastNode)
