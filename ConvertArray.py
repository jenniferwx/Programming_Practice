'''
Given an array:

[a_1, a_2, ..., a_N, b_1, b_2, ..., b_N, c_1, c_2, ..., c_N ]

convert it to:

[a_1, b_1, c_1, a_2, b_2, c_2, ..., a_N, b_N, c_N]

in-place using constant extra space.
'''

# Solution 1: use extra space

def getIDX(idx,N):
   return (idx%3)*N+idx/3

def NewArray(array):
  N = len(array)/3
  return [array[getIDX(i,N)] for i in range(len(array))]
  
  
#Solution 2: 
def convertArray(arr): 
  N=len(arr)/3 
  for currentIndex in range(len(arr)): 
    swapIndex=getIndex(currentIndex, N) 
    while swapIndex<currentIndex: 
      swapIndex=getIndex(swapIndex, N) 
      arr[currentIndex], arr[swapIndex] = arr[swapIndex], arr[currentIndex]
  
