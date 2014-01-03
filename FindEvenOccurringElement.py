'''
Given an integer array, one element occurs even number of times and all others have odd occurrences. 
Find the element with even occurrences.
'''
def getEven1(arr): 
  counts=collections.defaultdict(int) 
  for num in arr: 
    counts[num]+=1 
    for num, count in counts.items(): 
      if count%2==0: 
        return num

# second solution: XOR (assume there is only one even number)
def getEven2(arr): 
  return reduce(lambda x, y: x^y, arr+list(set(arr)))  
