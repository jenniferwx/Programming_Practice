/*
Given a list of number from 1 to n, find the kth number and eliminate it.
output the last number in the list
*/

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

int countInCircle(vector<int> num,int n,int k)
{
    
    assert(n>=1);
    assert(k>=1);
    int start = 0;
    while(num.size()>1)
    {
        for(int i=1;i<k;i++)
        {
            start++;
            if(start==num.size())
            start=0;
        }
        int next = start+1;
        if(next==num.size())
        next = 0;
//        cout<<"erase:"<<num[start]<<endl;
        num.erase(num.begin()+start);
        start = next==0?next:next-1;
        cout<<"start:"<<num[start]<<endl;
    }
    return num[start];
    
}

int LastRemaining(vector<int> num,int n,int k)
{
    assert(n>=1);
    assert(k>=1);
    int last = 0;
    for(int i=2;i<=n;i++)
    {
        last = (last+k)%i;
        cout<<"Last:"<<last<<endl;
    }
    return last+1;
}
int main()
{
   int A[] = {1,2,3,4,5,6};
   int K = 6;
   int size = sizeof(A)/sizeof(int);
   vector<int> num(A,A+size);
   for(int i=0;i<size;i++)
   cout<<num[i]<<",";
   cout<<endl;
   cout<<countInCircle(num,size,K)<<endl;
   cout<<LastRemaining(num,size,K)<<endl;
   
   return 0;
}
