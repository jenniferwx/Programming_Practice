'''
Given an input string, reverse all the words. 
For example:
input: “Interviews are awesome!” 
output: “awesome! are Interviews”. 

Consider all consecutive non-whitespace characters as individual words. If there are multiple spaces between words 
reduce them to a single white space. Also remove all leading and trailing whitespaces. 
So, the output for ”   CS degree”, “CS    degree”, “CS degree   “, or ”   CS   degree   ” are all the same: “degree CS”
'''

# push the words to a stack and in the end pop all to reverse 
def reverseWords(text):
    words=[] 
    length=len(text) 
    space=set(string.whitespace) 
    index=0 
    while index<length: 
      if text[index] not in space: 
         wordStart=index 
      while index<length and text[index] not in space: 
          index+=1 
      words.append(text[wordStart:index]) 
      index+=1   
      print " ".join(reversed(words)) 


# other solutions, which might be regarded as cheating ones
def reverseWords1(text): 
    print " ".join(reversed(text.split()))   
def reverseWords2(text): 
    print " ".join(text.split()[::-1]) 
