'''
Given an array which has n integers. It has both positive and negative integers.Now you need to sort this array in 
such a way that,the negative integers should be in the front,and the positive integers should at the back. Also the 
relative position should not be changed.
eg. -1 1 3 -2 2 ans: -1 -2 1 3 2.

Required running time complexity is O(N) and the space complexity is O(1)
'''

def sortarray(array):
    length = len(array)
    negID = 0
    for i in range(length):
        if array[i]<0:
            posID = i
            if posID!= negID:
               array[negID], array[posID] = array[posID], array[negID]
               newID = negID+1
               while newID!=posID:
                   array[posID],array[newID] = array[newID], array[posID]   
                   newID +=1
            negID +=1
    return array
    
if __name__=='__main__':
   array = [-5,1,3,4,-2,10,-6]
   array = sortarray(array)
   print array
