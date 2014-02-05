'''

Broken Necklace

You have a necklace of N red, white, or blue beads (3<=N<=350) some of which are red, others blue, 
and others white, arranged at random. Here are two examples for n=29:


The beads considered first and second in the text that follows have been marked in the picture.

The configuration in Figure A may be represented as a string of b's and r's, where b represents a blue bead and r 
represents a red one, as follows: brbrrrbbbrrrrrbrrbbrbbbbrrrrb .

Suppose you are to break the necklace at some point, lay it out straight, and then collect beads of the same color 
from one end until you reach a bead of a different color, and do the same for the other end (which might not be of 
the same color as the beads collected before this).
Determine the point where the necklace should be broken so that the most number of beads can be collected.
Example
For example, for the necklace in Figure A, 8 beads can be collected, with the breaking point either between bead 9 
and bead 10 or else between bead 24 and bead 25.

In some necklaces, white beads had been included as shown in Figure B above. When collecting beads, a white bead
that is encountered may be treated as either red or blue and then painted with the desired color. The string that 
represents this configuration will include the three symbols r, b and w.

Write a program to determine the largest number of beads that can be collected from a supplied necklace.
PROGRAM NAME: beads
INPUT FORMAT
Line 1:	N, the number of beads
Line 2:	a string of N characters, each of which is r, b, or w
SAMPLE INPUT (file beads.in)

29

wwwbbrwrbrbrrbrbrwrwwrbwrwrrb

OUTPUT FORMAT
A single line containing the maximum of number of beads that can be collected from the supplied necklace.
SAMPLE OUTPUT (file beads.out)

11

'''

def maxlength(array):
    L0 = len(array)
    array = array+array+array
    maxLen = 0
    for i in range(L0):
        R = startRight = i+L0
        L = startLeft = startRight-1
        # check the length of beads in the direction to left
        V1 = array[startLeft]
        L1 = 1;
        startLeft -=1
        while startLeft>=L-L0+1:
           if (array[startLeft]==V1 or array[startLeft]=='w'):
              L1 +=1
              startLeft -=1
           else:
              break  
        # check length of beads in the direction to right
        V2 = array[startRight]
        L2 = 1
        startRight +=1
        while startRight<=R+L0-1:
           if (array[startRight]==V2 or array[startRight]=='w'):
              L2 +=1
              startRight +=1
           else:
              break
        
        if(L1+L2>maxLen):
          maxLen = L1+L2
          
    return maxLen
    
    
if __name__=="__main__":
    string = "aarrrrabbbbaaa"
    print string
   
    res = maxlength(string)
    print res
