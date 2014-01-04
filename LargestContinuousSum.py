'''
Given an array of integers (positive and negative) find the largest continuous sum.
Solutions:
we start summing up the numbers and store in a current sum variable. 
when the currentSum becomes negative, we restart the current sum value.
note: we don't reset the current sum value to zeros (which is the solution for array containing positive numbers), 
because when the arrary contains all negatives, 
the result will be the largest negative number.
'''

def largestContinuousSum(arr): 
  if len(arr)==0: 
    return 
  maxSum=currentSum=arr[0] 
  for num in arr[1:]:
    currentSum = max(currentSum+num, num) # no need to reset to zero when currentSum is less than zeros
    maxSum = max(currentSum, maxSum) 
  return maxSum 
