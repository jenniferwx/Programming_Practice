'''
Generate all permutations of a given string
'''

def permutations(str):
    if(len(str)==1):
        return str[0]
    permutation = permutations(str[1:])
    word = str[0]
    result = []
    
    for perm in permutation:
        for i in range(len(perm)+1):  # note: len+1
            result.append(perm[:i]+word+perm[i:])
    
    return result        
    
