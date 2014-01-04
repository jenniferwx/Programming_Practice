'''
There is an array of non-negative integers. A second array is formed by shuffling the elements of the first 
array and deleting a random element. 
Given these two arrays, find which element is missing in the second array.
'''

# Solution 1: O(NlogN)
def findMissingNumber1(array1, array2): 
  array1.sort() 
  array2.sort() 
  for num1, num2 in zip(array1, array2):  ##
    if num1!=num2: 
      return num1 
  return array1[-1] 
  
'''  
Note: "zip" function returns a list of tuples, where the i-th tuple contains the i-th element from each of 
the argument sequences or iterables. The returned list is truncated in length to the length of the shortest 
argument sequence. When there are multiple arguments which are all of the same length, zip() is similar to 
map() with an initial argument of 'None'.
'''

# Solution 2: O(N)+space complexity O(N)
def findMissingNumber2(array1, array2): 
  d=collections.defaultdict(int) 
  for num in array2: 
    d[num]+=1 
  for num in array1: 
    if d[num]==0: 
      return num 
  else: d[num]-=1 
  
# Solution 3: XOR, complexity: O(N)  
def findMissingNumber3(array1, array2): 
  result = 0
  for num in array1+array2: 
    result^=num 
  return result
  
  
