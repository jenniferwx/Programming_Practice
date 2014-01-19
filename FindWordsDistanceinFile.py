'''
CTCI Chapter18.5
Given any two words, find the shortest distance between them in the file
'''

import math
import sys
import re
def shortestDistance(str0,ch1,ch2):
    DIST = sys.maxint
    ch1pos = -1
    ch2pos = -1
    # convert to lower-case letter
    str0 = re.sub(r'[^a-z]',' ',str0.lower())
    ch1 = ch1.lower()
    ch2 = ch2.lower()
    string = str0.split()
    for i in range(len(string)):
        if string[i]==ch1:
           ch1pos = i
           dist = ch1pos-ch2pos 
           if dist<DIST and ch2pos>-1:
              DIST = dist
        elif string[i]==ch2:
             ch2pos = i
             dist = ch2pos-ch1pos 
             if dist<DIST and ch1pos>-1:
                DIST = dist
    return DIST    
 

if __name__=="__main__":
   string = "I love Hangeng and Hangeng love I right?"
   ch1 = 'I'
   ch2 = 'Hangeng'
   dist = shortestDistance(string,ch1,ch2)
   print dist
