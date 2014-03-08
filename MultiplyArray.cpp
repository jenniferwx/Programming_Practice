/*
Facebook Interview question:
input [2,3,1,4]
output [12,8,24,6]

Multiply all fields except it's own position.

Restrictions:
1. no use of division
2. complexity in O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> multiply(vector<int> A,int L)
{
    vector<int> left(L,1);
    vector<int> right(L,1);
    vector<int> output(L,0);
    for(int i = 1;i<L;i++)
    left[i] = A[i-1]*left[i-1];
    for(int i=L-2;i>=0;i--)
    right[i] = A[i+1]*right[i+1];
    
    for(int i=0;i<L;i++)
    output[i] = left[i]*right[i];
    return output;
}

// Lower space complexity: O(N)
vector<int> multiply2(vector<int> A,int L)
{
    vector<int> output(L,0);
    int p = 1;
    for(int i=0;i<L;i++)
    {
        output[i] = p;
        p = p*A[i];
    }
    p=1;
    for(int i=L-1;i>=0;i--)
    {
        output[i] = output[i]*p;
        p = p*A[i];
    }
    return output;
}

int main()
{
   int A[] = {2,3,1,4,5};
   int len = sizeof(A)/sizeof(int);
   vector<int> array(A,A+len);
   vector<int> output = multiply(array,len);
   for(int i=0;i<len;i++)
   cout<<output[i]<<",";
   return 0;
}
