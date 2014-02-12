/*
Print the first K prime number
*/

#include <iostream>
#include <cmath>
using namespace std;

void PrimeNum(int k)
{
    if(k<=0)
    return;
    int num=2;
    int i,j;
    for(i=1;i<=k;)
    {
        for(j=2;j<=sqrt(num);j++)
        {
            if(num%j==0)
            break;
        }
        if(j>sqrt(num))
        {
            cout<<num<<endl;
            i++;
        }
        num++;
    }
}
int main()
{    
   int K=10;
   PrimeNum(K);
   return 0;
}
