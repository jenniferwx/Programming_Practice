'''
Given a number, find the next higher number using only the digits in the given number. 
For example if the given number is 1234, next higher number with same digits is 1243
'''

def FindNext(num):
    number = str(num)
    length = len(number)
    for i in range(length-2,-1,-1):
        current = number[i]
        right = number[i+1]
        if current < right:
           temp = sorted(number[i:])
           Next = temp[temp.index(current)+1]
           temp.remove(Next)
           temp = ''.join(temp)
           return int(number[:i]+Next+temp)
    return num       
