/*
Amazon interview: Given an Array, replace each element in the Array with its Next Element(To its RHS) 
which is Larger than it. If no such element exists, then no need to replace.
Ex:
i/p: {2,12,8,6,5,1,2,10,3,2}
o/p:{12,12,10,10,10,2,10,10,3,2}
*/

#include <iostream>
using namespace std;

//Complexity: O(n)
void Replace(int A[],int len)
{
    if(len<=0)
    return;
    int M = A[len-1];
    int right = A[len-1];
    for(int j = len-2;j>=0;j--)
    {
        int next = A[j];
        if(A[j]<=M)
        {
            A[j] = A[j]<right?min(right,M):M;
        }
        else
        M = A[j];
        
        right = next;
        
    }
}
int main()
{
   int A[] = {2,12,8,6,5,1,2,10,3,2};
   //o/p:{12,12,10,10,10,2,10,10,3,2}
   int len = sizeof(A)/sizeof(int);
   Replace(A,len);
   for(int i=0;i<len;i++)
   cout<<A[i]<<",";
   
   return 0;
}
