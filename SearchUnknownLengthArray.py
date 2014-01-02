'''
Given a sorted array of unknown length and a number to search for, return the index of the number in the array. 
Accessing an element out of bounds throws exception. If the number occurs multiple times, return the index of any 
occurrence. If it isn’t present, return -1. 
'''

def getIndex(arr, num): 
  #check array indexes 0, 2^0, 2^1, 2^2, ... 
    index, exp = 0, 0 
    while True: 
      try: 
        if arr[index]==num:
          return index 
        elif arr[index]<num:
          index=2**exp 
          exp+=1 
        else:
          break 
        except IndexError:
          break  
      
#Binary Search 
    left=(index/2)+1 
    right=index-1 
    while left<=right: 
      try: 
        mid=left+(right-left)/2 
        if arr[mid]==num: 
          return mid 
        elif arr[mid]<num: 
          left=mid+1 
        else: 
          right=mid-1 
        except IndexError: 
          right=mid-1   
    return -1 
