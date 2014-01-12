'''
Given a string of opening and closing parentheses, check whether it’s balanced. 
We have 3 types of parentheses: round brackets: (), square brackets: [], and curly brackets: {}. 
'''

def isBalanced(expr): 
    if len(expr)%2!=0: 
      return False 
    opening=set('([{') 
    match=set([ ('(',')'), ('[',']'), ('{','}') ]) 
    stack=[] 
    for char in expr: 
        if char in opening: 
           stack.append(char) 
        else: 
           if len(stack)==0: 
              return False 
           lastOpen=stack.pop()
           if (lastOpen, char) not in match: 
              return False 
    return len(stack)==0
