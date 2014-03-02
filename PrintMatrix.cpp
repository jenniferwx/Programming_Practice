/*
Give a N*N matrix, print it out diagonally. 
Follow up, if it is a M*N matrix, how to print it out. 
Example: 
1 2 3 
4 5 6 
7 8 9 
print: 
1 
2 4 
3 5 7 
6 8 
9 

*/

#include <iostream>
#include <vector>
using namespace std;
void Print(int A[][4], int m, int n)
{
    if(m<=0)
    return;
    for(int sum=0;sum<=(n-1)+(m-1);sum++)
    {
        int i=0;
        int j=0;
        int count = 0;
        while(i<m)
        {
           if(i>sum)
           break;
           if(j>=n)
           {
              i++;
              j=0;
           }
           if(i+j==sum)
           {
               cout<<A[i][j];
               i++;
               j=0;
               count++;
           }
           else
           j++;
        }
        while(count<=n)
        {
            cout<<" ";
            count++;
        }
        cout<<endl;
    }
}
int main()
{
   int A[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
   int m =3,n=4;
   Print(A,m,n);
   return 0;
}
