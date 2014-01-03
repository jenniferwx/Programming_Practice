'''
Given an integer array, one element occurs odd number of times and all others have even occurrences. 
Find the element with odd occurrences. (only one odd number)
'''
def getOdd(arr): 
    return reduce(lambda x, y: x^y, arr) 
