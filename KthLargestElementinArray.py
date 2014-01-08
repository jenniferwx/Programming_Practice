'''

'''

import random

# Solution 1: Selection sort
def partition1(arr, left, right, pivotIndex): 
  arr[right], arr[pivotIndex]=arr[pivotIndex], arr[right] 
  pivot=arr[right] 
  swapIndex=left 
  for i in range(left, right): 
    if arr[i]<pivot: 
      arr[i], arr[swapIndex] = arr[swapIndex], arr[i] 
      swapIndex+=1 
  
  arr[right], arr[swapIndex]=arr[swapIndex], arr[right] 
  return swapIndex   
  
def kthLargest1(arr, left, right, k): 
  if not 1<=k<=len(arr): 
    return -1
  if left==right: 
    return arr[left]   
  while True: 
    pivotIndex=random.randint(left, right) 
    pivotIndex=partition1(arr, left, right, pivotIndex) 
  
    rank=pivotIndex+1 #pivotIndex-left+1 
    if rank==k: 
      return arr[pivotIndex] 
    elif k<rank: 
      return kthLargest1(arr, left, pivotIndex-1, k) 
    else: 
      return kthLargest1(arr, pivotIndex+1, right, k) #k-rank
    
if __name__=='__main__':
  array = [1,5,4,3,2,1]
  k = 5
  print kthLargest1(array,0,len(array)-1,k)       
    
